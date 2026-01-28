from math import pi

class Shape:
    def area(self):
        pass

    def perimeter(self):
        pass

class Rectangle(Shape):
    def __init__(self, length, width):
        self.length = length
        self.width = width

    def area(self):
        return self.length * self.width

    def perimeter(self):
        return 2 * (self.length + self.width)

class Circle(Shape):
    def __init__(self, radius):
        self.radius = radius

    def area(self):
        return pi * self.radius * self.radius

    def perimeter(self):
        return 2 * pi * self.radius

while True:
    print("\n1. Create Rectangle")
    print("2. Create Circle")
    print("3. Exit")
    choice = int(input("Enter your choice: "))

    if choice == 1:
        length = float(input("Enter rectangle length: "))
        width = float(input("Enter rectangle width: "))
        rectangle = Rectangle(length, width)
        print(f"Rectangle Area: {rectangle.area()}")
        print(f"Rectangle Perimeter: {rectangle.perimeter()}")

    elif choice == 2:
        radius = float(input("Enter circle radius: "))
        circle = Circle(radius)
        print(f"Circle Area: {circle.area()}")
        print(f"Circle Perimeter: {circle.perimeter()}")

    elif choice == 3:
        break

    else:
        print("Invalid choice")