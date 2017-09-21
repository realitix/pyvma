from cffi import FFI
from os import path

HERE = path.dirname(path.realpath(__file__))

ffi = FFI()

ffi.cdef(open(path.join(HERE, 'vk_mem_alloc.cdef.h')).read())

ffi.set_source(
    '_pyvma',
    '#define VMA_IMPLEMENTATION\n' +
    open(path.join(HERE, 'vk_mem_alloc.h')).read()
)

if __name__ == '__main__':
    ffi.build(verbose=true)
