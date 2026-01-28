# Write a program to make the length of each element 15 of a given Numpy array and the
# string centred, left-justified, right-justified with paddings of _ (underscore).

import numpy as np

def justify_strings(input_array, width=15, padding_char='_'):
    arr = np.array(input_array, dtype=str)

    center_justified = np.empty_like(arr, dtype=object)
    left_justified = np.empty_like(arr, dtype=object)
    right_justified = np.empty_like(arr, dtype=object)

    for i, string in enumerate(arr.flat):
        center_justified.flat[i] = string.center(width, padding_char)

        left_justified.flat[i] = string.ljust(width, padding_char)

        right_justified.flat[i] = string.rjust(width, padding_char)
    
    return {
        'original': arr,
        'center_justified': center_justified,
        'left_justified': left_justified,
        'right_justified': right_justified
    }

def main():
    example_array = np.array(['apple', 'banana', 'cherry', 'date', 'elderberry', 'fig'])
    
    print("Original array:")
    print(example_array)
    print()

    result = justify_strings(example_array)

    print("Center justified (width=15, padding='_'):")
    print(result['center_justified'])
    print()
    
    print("Left justified (width=15, padding='_'):")
    print(result['left_justified'])
    print()
    
    print("Right justified (width=15, padding='_'):")
    print(result['right_justified'])
    print()
if __name__ == "__main__":
    main()