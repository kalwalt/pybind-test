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
    m.doc() = R"pbdoc(
        Pybind11 plus numpy example plugin
        -----------------------

        This module provides several functions for array manipulation and basic arithmetic.

        Functions:
            sum_array(array): Takes a NumPy array as input and returns the sum of all its elements
            scale_array(array, factor): Takes a NumPy array and a scalar factor, multiplies each element by the factor
            divide(a, b): Takes two numbers and returns their quotient

        Example:
            >>> import my_module
            >>> result = my_module.sum_array(np.array([1,2,3]))
            >>> scaled = my_module.scale_array(np.array([1,2,3]), 2.0)
            >>> div = my_module.divide(10, 2)

        .. currentmodule:: my_module

        .. autosummary::
           :toctree: _generate

           sum_array
           scale_array
           divide
    )pbdoc";
    m.def("sum_array", &sum_array, R"pbdoc(
        Sum all elements of a NumPy array.

        Args:
            input (numpy.ndarray): Input array to sum.

        Returns:
            float: Sum of all elements in the array.
    )pbdoc");
    
    m.def("scale_array", &scale_array, R"pbdoc(
        Scale all elements of a NumPy array by a given factor.

        Args:
            array (numpy.ndarray): Array to be scaled.
            scale (float): Scaling factor.
    )pbdoc");
    
    m.def("divide", &divide, R"pbdoc(
        Divide two numbers.

        Args:
            a (float): Numerator.
            b (float): Denominator.

        Returns:
            float: Result of a/b.

        Raises:
            RuntimeError: If b is zero.
    )pbdoc");
}