from os import path
import platform
from subprocess import call


HERE = path.dirname(path.realpath(__file__))
LINUX = platform.system() == 'Linux'


# ----------
# BUILD STATIC LIB
# ----------
def build():
    p1 = path.join(HERE, 'include')
    p2 = path.join(HERE, 'vk_mem_alloc.h')
    p3 = path.join(HERE, 'vk_mem_alloc.o')
    p4 = path.join(HERE, 'libvk_mem_alloc.a')
    c = ' -DVMA_IMPLEMENTATION -DVMA_STATIC_VULKAN_FUNCTIONS=0 '
    cmd1 = 'g++ -std=c++11 -fPIC -x c++ -I' + p1 + c + '-c ' + p2 + ' -o ' + p3
    cmd2 = 'ar rvs ' + p4 + ' ' + p3

    # Launch command
    call(cmd1, shell=True)
    call(cmd2, shell=True)


if __name__ == '__main__':
    build()
