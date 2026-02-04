import sys
import collections
import heapq

# Global Inputs
MaxM, MaxC = 0, 0
BoatCap = 0
startState = None
goalState = None

class State:
    def __init__(self, m, c, b):
        self.m = m
        self.c = c
        self.b = b # 0 for Left, 1 for Right
    
    def __eq__(self, other):
        return self.m == other.m and self.c == other.c and self.b == other.b
    
    def __lt__(self, other):
        # Needed for priority queue or sorting if strictly required, 
        # though Python heap usually handles tuples. I'll use tuples for state storage in dicts/sets.
        if self.m != other.m: return self.m < other.m
        if self.c != other.c: return self.c < other.c
        return self.b < other.b

    def __hash__(self):
        return hash((self.m, self.c, self.b))
        
    def __repr__(self):
        side = 'L' if self.b == 0 else 'R'
        return f"({self.m},{self.c},{side})"

def parseState(s):
    # s format: "3,3,L"
    s = s.replace(',', ' ').strip()
    parts = s.split()
    m = int(parts[0])
    c = int(parts[1])
    bChar = parts[2]
    b = 0 if bChar.upper() == 'L' else 1
    return State(m, c, b)

def isValid(s):
    if s.m < 0 or s.m > MaxM or s.c < 0 or s.c > MaxC:
        return False
    # Check Left Bank
    if s.m > 0 and s.c > s.m:
        return False
    # Check Right Bank
    mR = MaxM - s.m
    cR = MaxC - s.c
    if mR > 0 and cR > mR:
        return False
    return True

def printPath(curr, parent):
    path = []
    # Reconstruct path by backtracking from curr to start
    # Note: parent maps State -> State
    # We must be careful about object identity or use comparison
    # Since we are using custom class, we rely on __eq__ and __hash__
    
    while curr != startState:
        path.append(curr)
        curr = parent[curr]
    path.append(startState)
    path.reverse()
    
    print("Solution Path:")
    path_strs = [str(x) for x in path]
    print(" -> ".join(path_strs))
    print(f"\nTotal Crossings: {len(path) - 1}")

def solveBFS():
    q = collections.deque([startState])
    parent = {startState: startState}
    dist = {startState: 0}
    
    # In BFS, we typically track visited in a set too, or rely on 'parent' keys
    
    while q:
        u = q.popleft()
        print(f"Explored Node: {u}")
        
        if u == goalState:
            printPath(u, parent)
            return

        sign = -1 if u.b == 0 else 1
        
        for m in range(MaxM + 1):
            for c in range(MaxC + 1):
                total = m + c
                if 1 <= total <= BoatCap:
                    # New state logic
                    # u.b=0 (Left) -> sign=-1 -> subtracting? 
                    # Wait, C++ logic: 
                    # int sign = (u.b == 0) ? -1 : 1;
                    # v.m += sign * m
                    # If u.b=0 (Boat Left), we want to move TO Right.
                    # Usually if boat is at Left, we SUBTRACT from Left counts?
                    # Let's check C++: 
                    # State is {m, c, b}. usually represents Left Bank counts?
                    # If parseState(3,3,L) -> {3,3,0}.
                    # If Boat is Left (b=0), they leave Left. So m should DECREASE.
                    # sign = -1. v.m = 3 + (-1)*1 = 2. Correct.
                    # If Boat is Right (b=1), they come back. m should INCREASE.
                    # sign = 1. v.m = 2 + (1)*1 = 3. Correct.
                    
                    v_m = u.m + sign * m
                    v_c = u.c + sign * c
                    v_b = 1 - u.b
                    v = State(v_m, v_c, v_b)
                    
                    if isValid(v) and v not in parent:
                        parent[v] = u
                        dist[v] = dist[u] + 1
                        q.append(v)
    print("Goal not found.")

def solveDFS():
    st = [startState]
    parent = {startState: startState}
    visited = set()
    
    while st:
        u = st.pop()
        
        if u in visited:
            continue
        visited.add(u)
        
        print(f"Explored Node: {u}")
        
        if u == goalState:
            printPath(u, parent)
            return
            
        sign = -1 if u.b == 0 else 1
        
        # Iteration order same as C++ usually for consistency?
        for m in range(MaxM + 1):
             for c in range(MaxC + 1):
                total = m + c
                if 1 <= total <= BoatCap:
                    v_m = u.m + sign * m
                    v_c = u.c + sign * c
                    v_b = 1 - u.b
                    v = State(v_m, v_c, v_b)
                    
                    if isValid(v) and v not in visited:
                        # In C++ code: if parent.find(v) == end, parent[v]=u
                        # Since we might revisit nodes in DFS via different path (but visited check prevents processing),
                        # we record parent on pushing if not set? 
                        # C++: if (isValid(v) && !visited.count(v)) { if(parent.find==end) parent=u; st.push(v); }
                        if v not in parent:
                            parent[v] = u
                        st.append(v)
    print("Goal not found.")

# DLS Variables
dlsParent = {}
dlsPath = set()
dlsFound = False

def dlsRecursive(u, depth, limit):
    global dlsFound, dlsParent
    if dlsFound: return
    
    print(f"Explored Node: {u}")
    
    if u == goalState:
        printPath(u, dlsParent)
        dlsFound = True
        return

    if depth >= limit:
        return

    dlsPath.add(u)
    
    sign = -1 if u.b == 0 else 1
    
    for m in range(MaxM + 1):
        for c in range(MaxC + 1):
            total = m + c
            if 1 <= total <= BoatCap:
                v_m = u.m + sign * m
                v_c = u.c + sign * c
                v_b = 1 - u.b
                v = State(v_m, v_c, v_b)
                
                if isValid(v) and v not in dlsPath:
                    dlsParent[v] = u
                    dlsRecursive(v, depth + 1, limit)
                    if dlsFound: return

    dlsPath.remove(u) # Backtrack

def solveDLS():
    global dlsFound, dlsParent, dlsPath
    dlsParent = {startState: startState}
    dlsPath = set()
    dlsFound = False
    dlsRecursive(startState, 0, 12)
    if not dlsFound:
        print("Goal not found within limit.")

def solveUCS():
    # Priority Queue stores (cost, counter, state)
    # Counter used to break ties if states are not comparable or to ensure stable sort, 
    # but here State needs to be comparable or we use a wrapper.
    # Python heapq compares elements[0], then elements[1], etc.
    # State needs to implement __lt__
    
    pq = []
    heapq.heappush(pq, (0, startState))
    
    parent = {startState: startState}
    costSoFar = {startState: 0}
    visited = set()
    
    while pq:
        cVal, u = heapq.heappop(pq)
        
        if u in visited:
            continue
        visited.add(u)
        
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
                        if v not in costSoFar or newCost < costSoFar[v]:
                            costSoFar[v] = newCost
                            parent[v] = u
                            heapq.heappush(pq, (newCost, v))
                            
    print("Goal not found.")

def main():
    global MaxM, MaxC, BoatCap, startState, goalState
    
    # Read all lines from stdin
    lines = sys.stdin.read().splitlines()
    if not lines: return
    
    # Filter empty lines just in case
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
        print("\n--- BFS Traversal ---")
        solveBFS()
    elif strat == "dfs":
        print("\n--- DFS Traversal ---")
        solveDFS()
    elif strat == "dls":
        print("\n--- DLS Traversal (Limit: 12) ---")
        solveDLS()
    elif strat == "ucs":
        print("\n--- UCS Traversal ---")
        solveUCS()
    else:
        print("Unknown Strategy")

if __name__ == "__main__":
    main()
