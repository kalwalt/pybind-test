#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>

namespace py = pybind11;

double sum_array(py::array_t<double> input) {
    auto buf = input.request();
    if (buf.ndim != 1)
        throw std::runtime_error("Number of dimensions must be one");

    double *ptr = (double *) buf.ptr;
    double sum = 0;
    for (size_t idx = 0; idx < buf.shape[0]; idx++)
        sum += ptr[idx];

    return sum;
}

void scale_array(py::array_t<double> array, double scale) {
    // Obtain mutable access to the array
    auto r = array.mutable_unchecked<1>();
    // Iterate over each element in the array
    for (ssize_t i = 0; i < r.shape(0); i++) {
        // Scale each element by the specified factor
        r(i) *= scale;
    }
}

double divide(double a, double b) {
    // Check if the divisor is zero
    if (b == 0) {
        // Throw a runtime error if division by zero occurs
        throw std::runtime_error("Division by zero");
    }
    return a / b;
}

PYBIND11_MODULE(my_module, m) {
    m.def("sum_array", &sum_array, "Sum all elements of a NumPy array");
    m.def("scale_array", &scale_array, "Scale all elements of a NumPy array by a given factor");
    m.def("divide", &divide, "Divide two numbers");
}