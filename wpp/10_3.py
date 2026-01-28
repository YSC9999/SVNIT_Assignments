# Take N (N >= 10) random 2-dimensional points represented in cartesian coordinate space.
# Store them in a numpy array. Convert them to polar coordinates.

import numpy as np    
import math as mt

class polar:
    
    def __init__(self, x, y):
        self.x = x
        self.y = y
        
    def convert(self):
        theta = (mt.atan(self.x/self.y))*(180/mt.pi)
        radius = ((self.x**2) + (self.y**2))**(1/2)
        
        return theta, radius
    
n = int(input("Enter the no of 2D points: "))
arr = np.zeros((2,n), dtype=float)
for i in range(n):
    x = int(input("Enter the x cord of point: "))
    y = int(input("Enter the y cord of point: "))
    z = polar(x, y)
    a, b = z.convert()
    arr[0][i] = a
    arr[1][i] = b
    
choice = int(input("Enter the point number to see its polar coord: "))
print("Enter -1 to exit: ")
while choice != -1:
    if choice > len(arr):
        print("Enter a valid point number: ")
    print(arr[0][choice-1], arr[1][choice-1])
    choice = int(input("Enter the point number to see its polar coord: "))