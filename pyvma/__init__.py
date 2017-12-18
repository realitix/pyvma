import vulkan as vk

from pyvma._pyvma import ffi, lib


def _new(kwargs):
    kwargs = {k: v for k, v in kwargs.items() if v is not None}

    for k, v in kwargs.items():
        if ffi.typeof(v).kind == 'pointer':
            kwargs[k] = ffi.cast('void*', v)

    return kwargs


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


def vmaCreateAllocator(pCreateInfo):
    pAllocator = ffi.new('VmaAllocator*')
    result = lib.vmaCreateAllocator(pCreateInfo, pAllocator)
    if result != vk.VK_SUCCESS:
        raise vk._exception_codes[result]

    return pAllocator[0]
