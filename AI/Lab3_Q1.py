import sys
import collections
import heapq

# Global Inputs
R, C = 0, 0
start = (0, 0)
goal = (0, 0)
obs = set()
dr = [1, 0, -1, 0]
dc = [0, 1, 0, -1]

def parse_point(s):
    try:
        parts = s.strip().split(',')
        return int(parts[0]), int(parts[1])
    except ValueError:
        return 0, 0

def valid(p, vis):
    r, c = p
    return 1 <= r <= R and 1 <= c <= C and p not in obs and p not in vis

def solveBFS():
    q = collections.deque([(start, 0)])
    vis = {start}
    
    while q:
        u, d = q.popleft()
        print(f"Explored Node: ({u[0]}, {u[1]})")
        
        if u == goal:
            print(f"Total Search Cost: {d}")
            return
        
        for i in range(4):
            v = (u[0] + dr[i], u[1] + dc[i])
            if valid(v, vis):
                vis.add(v)
                q.append((v, d + 1))

def solveDFS():
    st = [(start, 0)]
    vis = {start}
    
    while st:
        u, d = st.pop()
        print(f"Explored Node: ({u[0]}, {u[1]})")
        
        if u == goal:
            print(f"Total Search Cost: {d}")
            return
            
        # To match C++ iteration order if important, C++ does 0..3 (1, 0, -1, 0) -> right, up, left, down?
        # Actually dr={1,0,-1,0}, dc={0,1,0,-1}. 
        # i=0: (r+1, c) -> Down
        # i=1: (r, c+1) -> Right
        # i=2: (r-1, c) -> Up
        # i=3: (r, c-1) -> Left
        # Stack pops LIFO, so to match order of exploration (if they push 0..3), 3 is popped first.
        # However, C++ code loops 0..4 and pushes. So last pushed is 3. Popped is 3.
        # Python list as stack (append/pop) works same.
        
        for i in range(4):
            v = (u[0] + dr[i], u[1] + dc[i])
            if valid(v, vis):
                vis.add(v)
                st.append((v, d + 1))

def dls(u, d, limit, vis, cost_ref):
    print(f"Explored Node: ({u[0]}, {u[1]})")
    if u == goal:
        cost_ref[0] = d
        return True
    if d >= limit:
        return False
    
    vis.add(u)
    for i in range(4):
        v = (u[0] + dr[i], u[1] + dc[i])
        if valid(v, vis):
            if dls(v, d + 1, limit, vis, cost_ref):
                return True
    vis.remove(u) # Backtrack
    return False

def solveUCS():
    # Min-heap for priority queue
    # Heap elements: (cost, r, c). Using tuple for comparison.
    pq = [(0, start)]
    vis = set()
    
    while pq:
        cost, u = heapq.heappop(pq)
        
        if u in vis:
            continue
        vis.add(u)
        
        print(f"Explored Node: ({u[0]}, {u[1]})")
        
        if u == goal:
            print(f"Total Search Cost: {cost}")
            return
            
        for i in range(4):
            v = (u[0] + dr[i], u[1] + dc[i])
            # Check obstacles and bounds
            if 1 <= v[0] <= R and 1 <= v[1] <= C and v not in obs:
                 # In UCS/Dijkstra we push if not in visited (or better path found, but uniform cost doesn't need decrease-key if we just push)
                 # C++ implementation checks bounds inside loop
                 heapq.heappush(pq, (cost + 1, v))

def main():
    global R, C, start, goal, obs
    
    lines = sys.stdin.read().splitlines()
    if not lines:
        return

    # Line 1: Grid R,C
    # Check if empty lines exist
    line_idx = 0
    while line_idx < len(lines) and not lines[line_idx].strip():
        line_idx += 1
    if line_idx >= len(lines): return
    
    grid_line = lines[line_idx]
    R, C = parse_point(grid_line)
    line_idx += 1
    
    # Line 2: Start point ; Goal point
    if line_idx >= len(lines): return
    pts_line = lines[line_idx]
    if ';' in pts_line:
        parts = pts_line.split(';')
        start = parse_point(parts[0])
        goal = parse_point(parts[1])
    line_idx += 1
    
    # Line 3: Obstacles
    if line_idx >= len(lines): return
    obs_line = lines[line_idx]
    if obs_line.strip():
        tokens = obs_line.split(';')
        for t in tokens:
            if t.strip():
                obs.add(parse_point(t))
    line_idx += 1
    
    # Line 4: Strategy
    if line_idx >= len(lines): return
    strat = lines[line_idx].strip().lower()
    
    if strat == "bfs":
        print("\n--- BFS Traversal ---")
        solveBFS()
    elif strat == "dfs":
        print("\n--- DFS Traversal ---")
        solveDFS()
    elif strat == "ucs":
        print("\n--- UCS Traversal ---")
        solveUCS()
    elif strat == "dls":
        print("\n--- DLS Traversal (Limit: 5) ---")
        vis = set()
        cost_ref = [0]
        if not dls(start, 0, 5, vis, cost_ref):
            print("\nGoal not found within depth limit")
        else:
            print(f"Total Search Cost: {cost_ref[0]}")

if __name__ == "__main__":
    main()
