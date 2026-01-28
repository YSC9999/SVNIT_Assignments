import math
points = []
for i in range(3):
    a = int(input("Give a number: "));
    b = int(input("Give a number: "));
    c = int(input("Give a number: "));
    tup=(a,b,c)
    points.append(tup)
nearest_neighbors = []
for i, p1 in enumerate(points):
    min_dist = float('inf')
    nearest_point = None
    for j, p2 in enumerate(points):
        if i != j:
            dist = math.sqrt((p1[0] - p2[0]) ** 2 + (p1[1] - p2[1]) ** 2 + (p1[2] - p2[2]) ** 2)
            if dist < min_dist:
                min_dist = dist
                nearest_point = p2
    nearest_neighbors.append((p1, nearest_point))
for ans in nearest_neighbors:
    print(ans)