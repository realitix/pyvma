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
cdef = ""
if LINUX:
    cdef += open(path.join(HERE, 'cdef', 'stddef.cdef.h')).read()
cdef += open(path.join(HERE, 'cdef', 'vk_mem_alloc.cdef.h')).read()

ffibuilder.cdef(cdef)


# prepare libraries
libs = ['vk_mem_alloc']
if LINUX:
    libs += ['stdc++']

# prepare source
ffibuilder.set_source(
    '_pyvma',
    open(path.join(HERE, 'vk_mem_alloc.h')).read(),
    libraries=libs,
    library_dirs=[HERE],
    extra_compile_args=["-I"+INCLUDE_FOLDER]
)


if __name__ == '__main__':
    ffibuilder.compile(verbose=True)
