import numpy as np

class Grid:
    def __init__(self, x, y):
        self.x = x
        self.y = y
        self.grid = np.zeros((x, y))
        
    def display(self):
        print(self.grid)

class Queen:
    def __init__(self):
        self.queens = []
        self.grid = Grid(8, 8)
        
    def position(self, x, y):
        if self.grid.grid[x-1][y-1] != 0:
            return False
        
        self.grid.grid[x-1][y-1] = 1
        self.queens.append((x, y))
        
        self.attacks(x, y)
        return True
    def attacks(self, x, y):
        for i in range(self.grid.x):
            for j in range(self.grid.y):
                if i == x-1 and j == y-1:
                    continue
                
                # if(i == x-1 or j == y-1 or i+j == x+y-2 or i-j == x-y):
                #     if self.grid.grid[i][j] != 1:
                #         self.grid.grid[i][j] = -1
        # self.grid.display()
    def display(self):
        # self.grid.display()
        print(self.queens)

q = Queen()
q.position(5, 1)
count = 1
while count < 8:
    emptypositions = [(x, y) for x in range(1, 9) for y in range(1, 9) if q.grid.grid[x-1][y-1] == 0]
    if not emptypositions:
        break
    index = np.random.randint(0, len(emptypositions))
    x, y = emptypositions[index]
    if q.position(x, y):
        count += 1
q.display()
print(count)
