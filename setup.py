from distutils.command.build import build
from setuptools import setup

from _cffi_build import vma_build


class VmaBuild(build):
    def run(self):
        vma_build.build()
        super(VmaBuild, self).run()

# version is [vma_version].[pyvma_version]

setup(
    name="pyvma",
    version='2.0.0.1',  # can't use pyshader.__version__
    author="realitix",
    author_email="realitix@gmail.com",
    description="Python CFFI binding for Vulkan Memory Allocator",
    long_description="Python CFFI binding for Vulkan Memory Allocator",
    packages=['_cffi_build', 'pyvma'],
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
    cffi_modules=["_cffi_build/pyvma_build.py:ffibuilder"]
)
