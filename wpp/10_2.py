# A magic square is an N×N grid of numbers in which the entries in each row, column and
# main diagonal sum to the same number (equal to N(N^2+1)/2). Create a magic square for
# N=4, 5, 6, 7, 8

import numpy as np

def magic_square(n):
    if n % 2 == 0:
        return None
    else:
        square = np.zeros((n, n), dtype=int)
        for i in range(n):
            for j in range(n):
                square[i][j] = (i * n + j + 1) % (n * n) + 1
        return square
    

for i in range(4, 9):
    square = magic_square(i)
    if square is not None:
        print(f"Magic Square of size {i}:")
        print(square)
        print("Sum of each row, column and diagonal:")
        print(np.sum(square, axis=0)[0])
        print()
    else:
        print(f"Magic Square of size {i} is not possible.\n")
        print("Sum of each row, column and diagonal:")
        print(np.sum(square, axis=0)[0])
        print()