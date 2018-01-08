# PyVMA

PyVMA is a wrapper for [Vulkan Memory Allocator](https://github.com/GPUOpen-LibrariesAndSDKs/VulkanMemoryAllocator).

## How to install

### Pip

You can install directly *pyvma* with pip:

```
pip install pyvma
```

### Manual install

You can install it manually if you want the latest version:

```
git clone https://github.com/realitix/pyvma
cd pyvma
python setup.py build
python setup.py install
```

## How to use

PyVMA is designed as a plugin of the [vulkan](https://github.com/realitix/vulkan) wrapper.
It depends on it and installs it when you use `pip`.
It follows the same conventions as `vulkan` wrapper.

## How to update this wrapper

- Update vk_mem_alloc.h
- Run `cpp -std=c99 -P -Iinclude -o cdef/vk_mem_alloc.cdef.h vk_mem_alloc.h`
