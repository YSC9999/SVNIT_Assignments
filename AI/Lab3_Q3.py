import sys
import collections
import heapq

# Global Inputs
MaxM, MaxC, BoatCap = 0, 0, 0
startState = None
goalState = None
exploredNodes = 0

class State:
    def __init__(self, m, c, b):
        self.m = m
        self.c = c
        self.b = b # 0 for Left, 1 for Right
    
    def __eq__(self, other):
        return self.m == other.m and self.c == other.c and self.b == other.b
    
    def __lt__(self, other):
        if self.m != other.m: return self.m < other.m
        if self.c != other.c: return self.c < other.c
        return self.b < other.b

    def __hash__(self):
        return hash((self.m, self.c, self.b))
        
    def __repr__(self):
        side = 'L' if self.b == 0 else 'R'
        return f"({self.m},{self.c},{side})"

def parseState(s):
    s = s.replace(',', ' ').strip()
    parts = s.split()
    m = int(parts[0])
    c = int(parts[1])
    bChar = parts[2]
    b = 0 if bChar.upper() == 'L' else 1
    return State(m, c, b)

def isValid(s):
    if s.m < 0 or s.m > MaxM or s.c < 0 or s.c > MaxC: return False
    # Left bank check
    if s.m > 0 and s.c > s.m: return False 
    # Right bank check
    mR = MaxM - s.m
    cR = MaxC - s.c
    if mR > 0 and cR > mR: return False 
    return True

def printPath(curr, parent):
    path = []
    while curr != startState:
        path.append(curr)
        curr = parent[curr]
    path.append(startState)
    path.reverse()
    
    print("Solution Path:")
    print(" -> ".join([str(x) for x in path]))
    print(f"\nTotal Crossings: {len(path) - 1}")
    print(f"Total States Explored: {exploredNodes}")

def solveBFS():
    global exploredNodes
    q = collections.deque([startState])
    parent = {startState: startState}
    seen = {startState}
    
    while q:
        u = q.popleft()
        exploredNodes += 1
        print(f"Explored Node: {u}")
        
        if u == goalState:
            printPath(u, parent)
            return

        sign = -1 if u.b == 0 else 1
        
        for m in range(MaxM + 1):
            for c in range(MaxC + 1):
                total = m + c
                if 1 <= total <= BoatCap:
                    v_m = u.m + sign * m
                    v_c = u.c + sign * c
                    v_b = 1 - u.b
                    v = State(v_m, v_c, v_b)
                    
                    if isValid(v) and v not in seen:
                        seen.add(v)
                        parent[v] = u
                        q.append(v)
                        
    print("Goal not found.")
    print(f"Total States Explored: {exploredNodes}")

def solveUCS():
    global exploredNodes
    pq = []
    # (cost, state)
    heapq.heappush(pq, (0, startState))
    
    parent = {startState: startState}
    costs = {startState: 0}
    expanded = set()

    while pq:
        cVal, u = heapq.heappop(pq)
        
        if u in expanded: continue
        expanded.add(u)
        exploredNodes += 1
        
        print(f"Explored Node: {u}")
        
        if u == goalState:
            printPath(u, parent)
            return
        
        sign = -1 if u.b == 0 else 1
        
        for m in range(MaxM + 1):
            for c in range(MaxC + 1):
                total = m + c
                if 1 <= total <= BoatCap:
                    v_m = u.m + sign * m
                    v_c = u.c + sign * c
                    v_b = 1 - u.b
                    v = State(v_m, v_c, v_b)
                    
                    newCost = cVal + 1
                    
                    if isValid(v):
                        if v not in costs or newCost < costs[v]:
                            costs[v] = newCost
                            parent[v] = u
                            heapq.heappush(pq, (newCost, v))
                            
    print("Goal not found.")
    print(f"Total States Explored: {exploredNodes}")

def main():
    global MaxM, MaxC, BoatCap, startState, goalState
    
    lines = sys.stdin.read().splitlines()
    if not lines: return
    lines = [l for l in lines if l.strip()]
    if len(lines) < 5: return
    
    # Line 1: M, C
    line1 = lines[0].replace(',', ' ')
    parts1 = line1.split()
    MaxM = int(parts1[0])
    MaxC = int(parts1[1])
    
    # Line 2: Boat Cap
    BoatCap = int(lines[1])
    
    # Line 3: Start
    startState = parseState(lines[2])
    
    # Line 4: Goal
    goalState = parseState(lines[3])
    
    # Line 5: Strategy
    strat = lines[4].strip().lower()
    
    if strat == "bfs":
        print("\n--- BFS Traversal (Extended) ---")
        solveBFS()
    elif strat == "ucs":
        print("\n--- UCS Traversal (Extended) ---")
        solveUCS()
    else:
        print("Unknown/Unrequested Strategy for Lab3_Q3 (Only BFS/UCS requested)")

if __name__ == "__main__":
    main()
