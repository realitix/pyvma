import vulkan as vk

from pyvma._pyvma import ffi, lib


VMA_MEMORY_USAGE_GPU_ONLY = lib.VMA_MEMORY_USAGE_GPU_ONLY
VMA_MEMORY_USAGE_UNKNOWN = lib.VMA_MEMORY_USAGE_UNKNOWN
VMA_MEMORY_USAGE_CPU_ONLY = lib.VMA_MEMORY_USAGE_CPU_ONLY
VMA_MEMORY_USAGE_CPU_TO_GPU = lib.VMA_MEMORY_USAGE_CPU_TO_GPU
VMA_MEMORY_USAGE_GPU_TO_CPU = lib.VMA_MEMORY_USAGE_GPU_TO_CPU
VMA_MEMORY_USAGE_MAX_ENUM = lib.VMA_MEMORY_USAGE_MAX_ENUM


def _new(kwargs):
    kwargs = {k: v for k, v in kwargs.items() if v is not None}

    for k, v in kwargs.items():
        if isinstance(v, ffi.CData) and ffi.typeof(v).kind == 'pointer':
            kwargs[k] = ffi.cast('void*', v)

    return kwargs


def _vk_arg(arg):
    return ffi.cast('void*', ffi.addressof(arg))


def VmaAllocatorCreateInfo(**kwargs):
    kwargs = _new(kwargs)

    if 'pVulkanFunctions' not in kwargs:
        functions = [
            'vkGetPhysicalDeviceProperties',
            'vkGetPhysicalDeviceMemoryProperties', 'vkAllocateMemory',
            'vkFreeMemory', 'vkMapMemory', 'vkUnmapMemory',
            'vkBindBufferMemory', 'vkBindImageMemory',
            'vkGetBufferMemoryRequirements', 'vkGetImageMemoryRequirements',
            'vkCreateBuffer', 'vkDestroyBuffer', 'vkCreateImage',
            'vkDestroyImage'
        ]
        init_functions = {x: ffi.cast('PFN_' + x, getattr(vk.lib, x))
                          for x in functions}

        # add extension functions
        ext_functions = ['vkGetBufferMemoryRequirements2KHR',
                         'vkGetImageMemoryRequirements2KHR']
        for x in ext_functions:
            fn = vk.lib.vkGetDeviceProcAddr(
                kwargs['device'], ffi.new('char[]', x.encode('ascii')))

            if fn == ffi.NULL:
                raise vk.ProcedureNotFoundError()

            fn = ffi.cast('PFN_' + x, fn)

            init_functions[x] = fn

        vulkan_functions = ffi.new('VmaVulkanFunctions*', init_functions)
        kwargs['pVulkanFunctions'] = vulkan_functions

    return ffi.new('VmaAllocatorCreateInfo*', kwargs)


def VmaAllocationCreateInfo(**kwargs):
    return ffi.new('VmaAllocationCreateInfo*', _new(kwargs))


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

    return pBuffer[0], pAllocation[0], pAllocationInfo[0]


def vmaDestroyBuffer(allocator, buffer, allocation):
    lib.vmaDestroyBuffer(allocator, buffer, allocation)


def vmaDestroyAllocator(allocator):
    lib.vmaDestroyAllocator(allocator)
