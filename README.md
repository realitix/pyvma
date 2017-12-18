# PyVMA

# How to update

- Update vk_mem_alloc.h
- Run `cpp -std=c99 -P -Iinclude -o cdef/vk_mem_alloc.cdef.h vk_mem_alloc.h`

# Work In Progress

PyVMA is a wrapper for [Vulkan Memory Allocator](https://github.com/GPUOpen-LibrariesAndSDKs/VulkanMemoryAllocator).

I'm currently working on it. The cffi part is done so it can be used as is.
But I'm writing the Python part to hide cffi complexity.
It works on Linux and Windows, come back soon, it will be ok.
