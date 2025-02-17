from setuptools import setup, Extension
import pybind11
from pybind11.setup_helpers import Pybind11Extension, build_ext

ext_modules = [
    Extension(
        'my_module',
        ['main.cpp'],
        include_dirs=[pybind11.get_include()],
        language='c++'
    ),
]

setup(
    name='my_module',
    author='@kalwalt',
    description='A simple example project using pybind11 and numpy',
    ext_modules=ext_modules,
    cmdclass={'build_ext': build_ext},
    # Set to False to include binaries
    zip_safe=False,
    python_requires=">=3.7",
)