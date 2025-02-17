# Pybind11 example with numpy

This is a simple example of how to use [pybind11](https://github.com/pybind/pybind11) to create Python bindings for C++ code with numpy arrays.


## Prerequisites
You need to have the following installed on your system:
- Python 3
- numpy
- pybind11
  
You can install numpy and pybind11 using pip:
```bash
pip install numpy pybind11
```
Alternatively, you can install numpy and pybind11 using conda:
```bash
conda install numpy pybind11
```

## Building the project

To build the project run the following commands:

```bash
python setup.py build_ext --inplace
```
 then run the example:
```bash
python example.py
```