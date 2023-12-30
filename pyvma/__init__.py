import vulkan as vk

from pyvma._pyvma import ffi, lib


__version__ = '2.0.0.6.1'


VMA_MEMORY_USAGE_GPU_ONLY = lib.VMA_MEMORY_USAGE_GPU_ONLY
VMA_MEMORY_USAGE_UNKNOWN = lib.VMA_MEMORY_USAGE_UNKNOWN
VMA_MEMORY_USAGE_CPU_ONLY = lib.VMA_MEMORY_USAGE_CPU_ONLY
VMA_MEMORY_USAGE_CPU_TO_GPU = lib.VMA_MEMORY_USAGE_CPU_TO_GPU
VMA_MEMORY_USAGE_GPU_TO_CPU = lib.VMA_MEMORY_USAGE_GPU_TO_CPU
VMA_MEMORY_USAGE_MAX_ENUM = lib.VMA_MEMORY_USAGE_MAX_ENUM

VMA_ALLOCATOR_CREATE_EXTERNALLY_SYNCHRONIZED_BIT = lib.VMA_ALLOCATOR_CREATE_EXTERNALLY_SYNCHRONIZED_BIT # noqa
VMA_ALLOCATOR_CREATE_KHR_DEDICATED_ALLOCATION_BIT = lib.VMA_ALLOCATOR_CREATE_KHR_DEDICATED_ALLOCATION_BIT # noqa
VMA_ALLOCATOR_CREATE_FLAG_BITS_MAX_ENUM = lib.VMA_ALLOCATOR_CREATE_FLAG_BITS_MAX_ENUM # noqa

VMA_ALLOCATION_CREATE_DEDICATED_MEMORY_BIT = lib.VMA_ALLOCATION_CREATE_DEDICATED_MEMORY_BIT # noqa
VMA_ALLOCATION_CREATE_NEVER_ALLOCATE_BIT = lib.VMA_ALLOCATION_CREATE_NEVER_ALLOCATE_BIT # noqa
VMA_ALLOCATION_CREATE_MAPPED_BIT = lib.VMA_ALLOCATION_CREATE_MAPPED_BIT # noqa
VMA_ALLOCATION_CREATE_USER_DATA_COPY_STRING_BIT = lib.VMA_ALLOCATION_CREATE_USER_DATA_COPY_STRING_BIT # noqa
VMA_ALLOCATION_CREATE_FLAG_BITS_MAX_ENUM = lib.VMA_ALLOCATION_CREATE_FLAG_BITS_MAX_ENUM # noqa

VMA_POOL_CREATE_IGNORE_BUFFER_IMAGE_GRANULARITY_BIT = lib.VMA_POOL_CREATE_IGNORE_BUFFER_IMAGE_GRANULARITY_BIT # noqa
VMA_POOL_CREATE_FLAG_BITS_MAX_ENUM = lib.VMA_POOL_CREATE_FLAG_BITS_MAX_ENUM # noqa


def _new(kwargs):
    kwargs = {k: v for k, v in kwargs.items() if v is not None}

    for k, v in kwargs.items():
        if isinstance(v, ffi.CData) and ffi.typeof(v).kind == 'pointer':
            kwargs[k] = ffi.cast('void*', v)

    return kwargs


def _vk_arg(arg):
    return ffi.cast('void*', ffi.addressof(arg))


def VmaDeviceMemoryCallbacks(**kwargs):
    return ffi.new('VmaDeviceMemoryCallbacks*', _new(kwargs))


def VmaVulkanFunctions(**kwargs):
    return ffi.new('VmaVulkanFunctions*', _new(kwargs))


def VmaAllocatorCreateInfo(**kwargs):
    kwargs = _new(kwargs)

    if 'pVulkanFunctions' not in kwargs:
        functions = [
            'vkFreeMemory', 'vkMapMemory', 'vkUnmapMemory',
            'vkBindBufferMemory', 'vkBindImageMemory',
            'vkGetBufferMemoryRequirements', 'vkGetImageMemoryRequirements',
            'vkCreateBuffer', 'vkDestroyBuffer', 'vkCreateImage',
            'vkDestroyImage', 'vkFlushMappedMemoryRanges', 'vkInvalidateMappedMemoryRanges',
            'vkGetDeviceBufferMemoryRequirements', 'vkGetDeviceImageMemoryRequirements',

        ]
        init_functions = {x: ffi.cast('PFN_' + x, getattr(vk.lib, x))
                          for x in functions}

        # add extension functions
        ext_functions = ['vkGetBufferMemoryRequirements2KHR',
                         'vkGetImageMemoryRequirements2KHR',
                         'vkBindBufferMemory2KHR', 'vkBindImageMemory2KHR',
                         ]
        for x in ext_functions:
            fn = vk.lib.vkGetDeviceProcAddr(
                kwargs['device'], ffi.new('char[]', x.encode('ascii')))

            if fn == ffi.NULL:
                raise vk.ProcedureNotFoundError()

            fn = ffi.cast('PFN_' + x, fn)

            init_functions[x] = fn

        init_functions['vkGetDeviceProcAddr'] = vk.lib.vkGetDeviceProcAddr
        init_functions['vkGetInstanceProcAddr'] = vk.lib.vkGetInstanceProcAddr

        vulkan_functions = ffi.new('VmaVulkanFunctions*', init_functions)
        kwargs['pVulkanFunctions'] = vulkan_functions

    return ffi.new('VmaAllocatorCreateInfo*', kwargs)


def VmaStatInfo(**kwargs):
    return ffi.new('VmaStatInfo*', _new(kwargs))


def VmaStat(**kwargs):
    return ffi.new('VmaStat*', _new(kwargs))


def VmaAllocationCreateInfo(**kwargs):
    return ffi.new('VmaAllocationCreateInfo*', _new(kwargs))


def VmaPoolCreateInfo(**kwargs):
    return ffi.new('VmaPoolCreateInfo*', _new(kwargs))


def VmaPoolStat(**kwargs):
    return ffi.new('VmaPoolStat*', _new(kwargs))


def VmaAllocationInfo(**kwargs):
    return ffi.new('VmaAllocationInfo*', _new(kwargs))


def VmaDefragmentationInfo(**kwargs):
    return ffi.new('VmaDefragmentationInfo*', kwargs)


def VmaDefragmentationStats(**kwargs):
    return ffi.new('VmaDefragmentationStats*', kwargs)


def vmaCreateAllocator(pCreateInfo):
    pAllocator = ffi.new('VmaAllocator*')

    result = lib.vmaCreateAllocator(pCreateInfo, pAllocator)
    if result != vk.VK_SUCCESS:
        raise vk.exception_codes[result]

    return pAllocator[0]


def vmaCreateBuffer(allocator, pBufferCreateInfo, pAllocationCreateInfo):
    pBuffer = ffi.new('VkBuffer*')
    pAllocation = ffi.new('VmaAllocation*')
    pAllocationInfo = ffi.new('VmaAllocationInfo*')

    result = lib.vmaCreateBuffer(allocator, _vk_arg(pBufferCreateInfo),
                                 pAllocationCreateInfo, pBuffer,
                                 pAllocation, pAllocationInfo)
    if result != vk.VK_SUCCESS:
        raise vk.exception_codes[result]

    return ffi.cast('void*', pBuffer[0]), pAllocation[0], pAllocationInfo[0]


def vmaDestroyBuffer(allocator, buffer, allocation):
    lib.vmaDestroyBuffer(allocator, buffer, allocation)


def vmaDestroyAllocator(allocator):
    lib.vmaDestroyAllocator(allocator)


def vmaGetPhysicalDeviceProperties(allocator):
    ppPhysicalDeviceProperties = ffi.new('VkPhysicalDeviceProperties**')
    lib.vmaGetPhysicalDeviceProperties(allocator, ppPhysicalDeviceProperties)
    return vk.StrWrap(ppPhysicalDeviceProperties[0])


def vmaGetMemoryProperties(allocator):
    ppPhysicalDeviceMemoryProperties = ffi.new('VkPhysicalDeviceMemoryProperties**') # noqa
    lib.vmaGetMemoryProperties(allocator, ppPhysicalDeviceMemoryProperties)
    return ppPhysicalDeviceMemoryProperties[0]


def vmaGetMemoryTypeProperties(allocator, memoryTypeIndex):
    pFlags = ffi.new('VkMemoryPropertyFlags*')
    lib.vmaGetMemoryTypeProperties(allocator, memoryTypeIndex, pFlags)
    return pFlags[0]


def vmaSetCurrentFrameIndex(allocator, frameIndex):
    lib.vmaSetCurrentFrameIndex(allocator, frameIndex)


def vmaCalculateStats(allocator):
    pStats = ffi.new('VmaStats*')
    lib.vmaCalculateStats(allocator, pStats)
    return pStats[0]


def vmaBuildStatsString(allocator, detailedMap):
    ppStatsString = ffi.new('char**')
    lib.vmaBuildStatsString(allocator, ppStatsString, detailedMap)
    return ppStatsString[0]


def vmaFreeStatsString(allocator, pStatsString):
    lib.vmaFreeStatsString(allocator, pStatsString)


def vmaFindMemoryTypeIndex(allocator, memoryTypeBits, pAllocationCreateInfo):
    pMemoryTypeIndex = ffi.new('uint32_t*')
    result = lib.vmaFindMemoryTypeIndex(allocator, memoryTypeBits,
                                        pAllocationCreateInfo,
                                        pMemoryTypeIndex)
    if result != vk.VK_SUCCESS:
        raise vk.exception_codes[result]

    return pMemoryTypeIndex[0]


def vmaCreatePool(allocator, pCreateInfo):
    pPool = ffi.new('VmaPool*')
    result = lib.vmaCreatePool(allocator, pCreateInfo, pPool)
    if result != vk.VK_SUCCESS:
        raise vk.exception_codes[result]

    return pPool[0]


def vmaDestroyPool(allocator, pool):
    lib.vmaDestroyPool(allocator, pool)


def vmaGetPoolStats(allocator, pool):
    pPoolStats = ffi.new('VmaPoolStats*')
    lib.vmaGetPoolStats(allocator, pool, pPoolStats)
    return pPoolStats[0]


def vmaMakePoolAllocationsLost(allocator, pool):
    pLostAllocationCount = ffi.new('size_t*')
    lib.vmaMakePoolAllocationsLost(allocator, pool, pLostAllocationCount)
    return pLostAllocationCount[0]


def vmaAllocateMemory(allocator, pVkMemoryRequirements, pCreateInfo):
    pAllocation = ffi.new('VmaAllocation*')
    pAllocationInfo = ffi.new('VmaAllocationInfo*')

    result = lib.vmaAllocateMemory(allocator, pVkMemoryRequirements,
                                   pCreateInfo, pAllocation,
                                   pAllocationInfo)
    if result != vk.VK_SUCCESS:
        raise vk.exception_codes[result]

    return pAllocation[0], pAllocationInfo[0]


def vmaAllocateMemoryForBuffer(allocator, buffer, pCreateInfo):
    pAllocation = ffi.new('VmaAllocation*')
    pAllocationInfo = ffi.new('VmaAllocationInfo*')
    result = lib.vmaAllocateMemoryForBuffer(allocator, buffer, pCreateInfo,
                                            pAllocation, pAllocationInfo)
    if result != vk.VK_SUCCESS:
        raise vk.exception_codes[result]

    return pAllocation[0], pAllocationInfo[0]


def vmaAllocateMemoryForImage(allocator, image, pCreateInfo):
    pAllocation = ffi.new('VmaAllocation*')
    pAllocationInfo = ffi.new('VmaAllocationInfo*')
    result = lib.vmaAllocateMemoryForBuffer(allocator, image, pCreateInfo,
                                            pAllocation, pAllocationInfo)
    if result != vk.VK_SUCCESS:
        raise vk.exception_codes[result]

    return pAllocation[0], pAllocationInfo[0]


def vmaFreeMemory(allocator, allocation):
    lib.vmaFreeMemory(allocator, allocation)


def vmaGetAllocationInfo(allocator, allocation):
    pAllocationInfo = ffi.new('VmaAllocationInfo*')
    lib.vmaGetAllocationInfo(allocator, allocation, pAllocationInfo)
    return pAllocationInfo[0]


def vmaSetAllocationUserData(allocator, allocation, pUserData):
    lib.vmaSetAllocationUserData(allocator, allocation, pUserData)


def vmaCreateLostAllocation(allocator):
    pAllocation = ffi.new('VmaAllocation*')
    lib.vmaCreateLostAllocation(allocator, pAllocation)
    return pAllocation[0]


def vmaMapMemory(allocator, allocation):
    ppData = ffi.new('void**')
    result = lib.vmaMapMemory(allocator, allocation, ppData)
    if result != vk.VK_SUCCESS:
        raise vk.exception_codes[result]

    info = vmaGetAllocationInfo(allocator, allocation)

    return ffi.buffer(ppData[0], info.size)


def vmaUnmapMemory(allocator, allocation):
    lib.vmaUnmapMemory(allocator, allocation)


def vmaDefragment(allocator, pAllocations, allocationCount,
                  pDefragmentationInfo):
    pAllocationsChanged = ffi.new('VkBool32*')
    pDefragmentationStats = ffi.new('VmaDefragmentationStats*')
    result = lib.vmaDefragment(allocator, pAllocations, allocationCount,
                               pAllocationsChanged, pDefragmentationInfo,
                               pDefragmentationStats)
    if result != vk.VK_SUCCESS:
        raise vk.exception_codes[result]
    return pAllocationsChanged, pDefragmentationStats


def vmaCreateImage(allocator, pImageCreateInfo, pAllocationCreateInfo):
    pImage = ffi.new('VkImage*')
    pAllocation = ffi.new('VmaAllocation*')
    pAllocationInfo = ffi.new('VmaAllocationInfo*')

    result = lib.vmaCreateImage(allocator, _vk_arg(pImageCreateInfo),
                                pAllocationCreateInfo, pImage,
                                pAllocation, pAllocationInfo)
    if result != vk.VK_SUCCESS:
        raise vk.exception_codes[result]

    return ffi.cast('void*', pImage[0]), pAllocation[0], pAllocationInfo[0]


def vmaDestroyImage(allocator, image, allocation):
    lib.vmaDestroyImage(allocator, image, allocation)

