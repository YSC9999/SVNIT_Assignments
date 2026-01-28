import math

class Vector2D:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def magnitude(self):
        return math.sqrt(self.x ** 2 + self.y ** 2)

    def rotation(self):
        return math.degrees(math.atan2(self.y, self.x))

    @staticmethod
    def distance(v1, v2):
        return math.sqrt((v1.x - v2.x) ** 2 + (v1.y - v2.y) ** 2)

    @staticmethod
    def dot_product(v1, v2):
        return v1.x * v2.x + v1.y * v2.y

    @staticmethod
    def cross_product(v1, v2):
        return v1.x * v2.y - v1.y * v2.x

    def __str__(self):
        return f"Vector2D(x: {self.x}, y: {self.y})"

class Vector3D(Vector2D):
    def __init__(self, x, y, z):
        super().__init__(x, y)
        self.z = z

    def magnitude(self):
        return math.sqrt(self.x ** 2 + self.y ** 2 + self.z ** 2)

    def rotation(self):
        xy_magnitude = math.sqrt(self.x ** 2 + self.y ** 2)
        theta_xy = math.degrees(math.atan2(self.y, self.x))
        phi = math.degrees(math.atan2(self.z, xy_magnitude))
        return theta_xy, phi

    @staticmethod
    def distance(v1, v2):
        return math.sqrt((v1.x - v2.x) ** 2 + (v1.y - v2.y) ** 2 + (v1.z - v2.z) ** 2)

    @staticmethod
    def dot_product(v1, v2):
        return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z

    @staticmethod
    def cross_product(v1, v2):
        cx = v1.y * v2.z - v1.z * v2.y
        cy = v1.z * v2.x - v1.x * v2.z
        cz = v1.x * v2.y - v1.y * v2.x
        return Vector3D(cx, cy, cz)

    def __str__(self):
        return f"Vector3D(x: {self.x}, y: {self.y}, z: {self.z})"

def main():
    while True:
        print("\nMenu:")
        print("1. Create 2D Vector")
        print("2. Create 3D Vector")
        print("3. Calculate Distance")
        print("4. Calculate Dot Product")
        print("5. Calculate Cross Product")
        print("6. Exit")
        choice = int(input("Enter your choice: "))

        if choice == 1:
            x = float(input("Enter x-coordinate: "))
            y = float(input("Enter y-coordinate: "))
            v2d = Vector2D(x, y)
            print(f"Created {v2d}")
            print(f"Magnitude: {v2d.magnitude()}")
            print(f"Rotation: {v2d.rotation()}")

        elif choice == 2:
            x = float(input("Enter x-coordinate: "))
            y = float(input("Enter y-coordinate: "))
            z = float(input("Enter z-coordinate: "))
            v3d = Vector3D(x, y, z)
            print(f"Created {v3d}")
            print(f"Magnitude: {v3d.magnitude()}")
            print(f"Rotation: {v3d.rotation()}")

        elif choice == 3:
            x1 = float(input("Enter x-coordinate of first vector: "))
            y1 = float(input("Enter y-coordinate of first vector: "))
            z1 = float(input("Enter z-coordinate of first vector (0 for 2D): "))
            x2 = float(input("Enter x-coordinate of second vector: "))
            y2 = float(input("Enter y-coordinate of second vector: "))
            z2 = float(input("Enter z-coordinate of second vector (0 for 2D): "))
            if z1 == 0 and z2 == 0:
                v1 = Vector2D(x1, y1)
                v2 = Vector2D(x2, y2)
                print(f"Distance: {Vector2D.distance(v1, v2)}")
            else:
                v1 = Vector3D(x1, y1, z1)
                v2 = Vector3D(x2, y2, z2)
                print(f"Distance: {Vector3D.distance(v1, v2)}")

        elif choice == 4:
            x1 = float(input("Enter x-coordinate of first vector: "))
            y1 = float(input("Enter y-coordinate of first vector: "))
            z1 = float(input("Enter z-coordinate of first vector (0 for 2D): "))
            x2 = float(input("Enter x-coordinate of second vector: "))
            y2 = float(input("Enter y-coordinate of second vector: "))
            z2 = float(input("Enter z-coordinate of second vector (0 for 2D): "))
            if z1 == 0 and z2 == 0:
                v1 = Vector2D(x1, y1)
                v2 = Vector2D(x2, y2)
                print(f"Dot Product: {Vector2D.dot_product(v1, v2)}")
            else:
                v1 = Vector3D(x1, y1, z1)
                v2 = Vector3D(x2, y2, z2)
                print(f"Dot Product: {Vector3D.dot_product(v1, v2)}")

        elif choice == 5:
            x1 = float(input("Enter x-coordinate of first vector: "))
            y1 = float(input("Enter y-coordinate of first vector: "))
            z1 = float(input("Enter z-coordinate of first vector (0 for 2D): "))
            x2 = float(input("Enter x-coordinate of second vector: "))
            y2 = float(input("Enter y-coordinate of second vector: "))
            z2 = float(input("Enter z-coordinate of second vector (0 for 2D): "))
            if z1 == 0 and z2 == 0:
                v1 = Vector2D(x1, y1)
                v2 = Vector2D(x2, y2)
                print(f"Cross Product: {Vector2D.cross_product(v1, v2)}")
            else:
                v1 = Vector3D(x1, y1, z1)
                v2 = Vector3D(x2, y2, z2)
                print(f"Cross Product: {Vector3D.cross_product(v1, v2)}")

        elif choice == 6:
            print("Exiting...")
            break

        else:
            print("Invalid choice. Please try again.")

if __name__ == "__main__":
    main()
