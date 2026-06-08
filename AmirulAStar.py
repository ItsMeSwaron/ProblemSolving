import math
from queue import PriorityQueue

# Heuristic function: Euclidean distance
def heuristic(node, goal, coords):
    x1, y1 = coords[node]
    x2, y2 = coords[goal]
    return math.sqrt((x2 - x1) ** 2 + (y2 - y1) ** 2)

# A* Search Algorithm
def a_star_search(start, goal, coords, graph):
    # Priority queue to store nodes based on f(n)
    priority_queue = PriorityQueue()
    priority_queue.put((0, start, 0, None))  # (f(n), node, g(n), parent)

    visited = {}
    path = {}

    while not priority_queue.empty():
        f, current, g, parent = priority_queue.get()

        if current in visited and visited[current] <= g:
            continue

        visited[current] = g
        path[current] = parent

        # If goal is reached, reconstruct the path
        if current == goal:
            solution_path = []
            total_cost = g
            while current:
                solution_path.append(current)
                current = path[current]
            solution_path.reverse()
            return solution_path, total_cost

        # Expand neighbors
        for neighbor, cost in graph.get(current, []):
            new_g = g + cost
            new_h = heuristic(neighbor, goal, coords)
            new_f = new_g + new_h
            priority_queue.put((new_f, neighbor, new_g, current))

    return None, float('inf')  # If no path found

# Input reading
coords = {}  # Node id is the key
adjlist = {}  # Node id is the key
with open('inputTara.txt', 'r') as f:
    V = int(f.readline())  # Number of vertices
    for _ in range(V):
        strs = f.readline().split()
        nid, x, y = strs[0], int(strs[1]), int(strs[2])
        coords[nid] = (x, y)  # x, y kept as a tuple
        adjlist[nid] = []  # Create empty list for each node's adjacencies

    E = int(f.readline())  # Number of edges
    for _ in range(E):
        strs = f.readline().split()
        n1, n2, c = strs[0], strs[1], int(strs[2])
        adjlist[n1].append((n2, c))  # (n2, c) tuple

    startnid = f.readline().strip()  # Start node
    goalnid = f.readline().strip()  # Goal node

# Display the graph
print("Graph:")
for nid in adjlist:
    print(nid, coords[nid], '--->', adjlist[nid])
    for tup in adjlist[nid]:
        print('\t', tup[0], tup[1])

print("Start:", startnid, "Goal:", goalnid)

# Run A* search
solution_path, solution_cost = a_star_search(startnid, goalnid, coords, adjlist)

# Output the solution
if solution_path:
    print("Solution path:", "-".join(solution_path))
    print("Solution cost:", solution_cost)
else:
    print("No path found.")