import my_module
import numpy as np
# Create a NumPy array
arr = np.array([1.0, 2.0, 3.0, 4.0])
# Compute the sum of the array
# Outputs: 10.0
print(my_module.sum_array(arr))
# Scale the array elements
my_module.scale_array(arr, 2.0)
# Outputs: [2.0, 4.0, 6.0, 8.0]
print(arr)

print(my_module.divide(20,2))

help(my_module)