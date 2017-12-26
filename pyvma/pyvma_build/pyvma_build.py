from cffi import FFI
from os import path
import platform


HERE = path.dirname(path.realpath(__file__))
INCLUDE_FOLDER = path.join(HERE, 'include')
LINUX = platform.system() == 'Linux'

# ----------
# BUILD WRAPPER
# ----------
ffibuilder = FFI()

# prepare cdef
ffibuilder.cdef(open(path.join(HERE, 'cdef', 'vk_mem_alloc.cdef.h')).read())

# prepare libraries
l = ['vk_mem_alloc']
if LINUX:
    l += ['stdc++']

# prepare source
ffibuilder.set_source(
    '_pyvma',
    open(path.join(HERE, 'vk_mem_alloc.h')).read(),
    libraries=l,
    library_dirs=[HERE],
    extra_compile_args=["-I"+INCLUDE_FOLDER]
)


if __name__ == '__main__':
    ffibuilder.compile(verbose=True)

