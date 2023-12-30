from distutils.command.build import build
from setuptools import setup
from os import path
import platform
from subprocess import call


# ----------
# BUILD STATIC LIB
# ----------
class VmaBuild(build):
    def run(self):
        self.build()
        super(VmaBuild, self).run()

    def build_linux(self):
        p1 = path.join(self.p, 'include')
        p2 = path.join(self.p, 'vk_mem_alloc.h')
        p3 = path.join(self.p, 'vk_mem_alloc.o')
        p4 = path.join(self.p, 'libvk_mem_alloc.a')
        c = ' -DVMA_IMPLEMENTATION -D_DEBUG -DVMA_STATIC_VULKAN_FUNCTIONS=0 '
        cmd1 = 'g++ -std=c++11 -fPIC -x c++ -I' + p1 + c + '-c ' + p2 + ' -o ' + p3  # noqa
        cmd2 = 'ar rvs ' + p4 + ' ' + p3

        call(cmd1, shell=True)
        call(cmd2, shell=True)


    def build_darwin(self):
        p1 = path.join(self.p, 'include')
        p2 = path.join(self.p, 'vk_mem_alloc.h')
        p3 = path.join(self.p, 'vk_mem_alloc.o')
        p4 = path.join(self.p, 'libvk_mem_alloc.a')
        c = ' -DVMA_IMPLEMENTATION -D_DEBUG -DVMA_STATIC_VULKAN_FUNCTIONS=0 '
        cmd1 = 'g++ -std=c++11 -fPIC -x c++ -I' + p1 + c + '-c ' + p2 + ' -o ' + p3
        cmd2 = 'ar rvs ' + p4 + ' ' + p3

        call(cmd1, shell=True)
        call(cmd2, shell=True)


    def build_windows(self):
        p1 = path.join(self.p, 'include')
        p2 = path.join(self.p, 'vk_mem_alloc.h')
        p3 = path.join(self.p, 'vk_mem_alloc.obj')
        p4 = path.join(self.p, 'vk_mem_alloc.lib')
        c = ' /DVMA_IMPLEMENTATION /DVMA_STATIC_VULKAN_FUNCTIONS=0 '
        cmd1 = 'CL.exe /c /I' + p1 + c +' /nologo /W3 /WX /Ox /Oi /GF /Gm- /EHsc /MD /GS /Gy /Zc:inline /Zc:wchar_t /Gd /TP /errorReport:none /Fo' + p3 + ' ' + p2  # noqa
        cmd2 = 'lib.exe /OUT:' + p4 + ' ' + p3

        call(cmd1, shell=True)
        call(cmd2, shell=True)

    def build(self):
        self.p = path.dirname(path.realpath(__file__))
        self.p = path.join(self.p, 'pyvma')
        self.p = path.join(self.p, 'pyvma_build')
        build_platform = {
            'Linux': self.build_linux,
            'Windows': self.build_windows,
            'Darwin': self.build_darwin,
        }
        build_platform[platform.system()]()


# version is [vma_version].[pyvma_version]

setup(
    name="pyvma",
    version='2.0.0.6.1',
    author="realitix",
    author_email="realitix@gmail.com",
    description="Python CFFI binding for Vulkan Memory Allocator",
    long_description="Python CFFI binding for Vulkan Memory Allocator",
    packages=['pyvma'],
    install_requires=["cffi"],
    setup_requires=["cffi"],
    include_package_data=True,
    url="http://github.com/realitix/pyvma",
    classifiers=[
        "Development Status :: 4 - Beta",
        "Intended Audience :: Developers",
        "License :: OSI Approved :: Apache Software License",
        "Natural Language :: English",
        "Programming Language :: Python :: 3.5",
        'Programming Language :: Python :: Implementation :: CPython',
    ],
    license="Apache 2.0",
    ext_package="pyvma",
    cmdclass={'build': VmaBuild},
    cffi_modules=["pyvma/pyvma_build/pyvma_build.py:ffibuilder"]
)
