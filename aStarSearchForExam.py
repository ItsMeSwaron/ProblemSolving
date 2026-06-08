import math
import heapq  # For priority queue operations


def heuristic(node_coords, current_node, goal_node):
    """Calculate Euclidean distance as heuristic."""
    x1, y1 = node_coords[current_node]
    x2, y2 = node_coords[goal_node]
    return math.sqrt((x2 - x1) ** 2 + (y2 - y1) ** 2)


def a_star_search(graph, node_coords, start_node, goal_node):
    """Implement the A* search algorithm."""
    # Priority queue stores tuples of (f_cost, node)
    priority_queue = []
    heapq.heappush(priority_queue, (0, start_node))

    # g_cost stores the cost from the start node to the current node
    g_cost = {node: float('inf') for node in graph}
    g_cost[start_node] = 0

    # f_cost stores the total cost (g_cost + heuristic)
    f_cost = {node: float('inf') for node in graph}
    f_cost[start_node] = heuristic(node_coords, start_node, goal_node)

    # Keep track of the nodes' predecessors to reconstruct the path
    came_from = {}

    # Open set to track nodes that need to be evaluated
    # open_set = set()
    # open_set.add(start_node)

    while priority_queue:
        current_f_cost, current_node = heapq.heappop(priority_queue)

        # If we reach the goal node, reconstruct the path
        # if current_node == goal_node:
        #     break

        # Explore the neighbors
        for neighbor, cost in graph[current_node]:
            tentative_g_cost = g_cost[current_node] + cost
            if tentative_g_cost < g_cost[neighbor]:
                g_cost[neighbor] = tentative_g_cost
                f_cost[neighbor] = tentative_g_cost + heuristic(node_coords, neighbor, goal_node)
                heapq.heappush(priority_queue, (f_cost[neighbor], neighbor))
                came_from[neighbor] = current_node

    # Reconstruct the optimal path from came_from dictionary
    path = []
    current_node = goal_node
    while current_node != start_node:
        if current_node not in came_from:
            return None, float('inf')  # No path found
        path.append(current_node)
        current_node = came_from[current_node]

    path.append(start_node)
    path.reverse()

    return path, g_cost[goal_node]


if __name__ == "__main__":
    file_name = "inputTara.txt"
    try:
        with open(file_name, "r") as file:
            data = file.read().splitlines()

        # First line is the number of nodes
        V = int(data[0])

        # Next V lines are node coordinates
        node_coords = {}
        for i in range(1, V + 1):
            line = data[i].split()
            node_coords[line[0]] = (int(line[1]), int(line[2]))

        # Next line is the number of edges
        E = int(data[V + 1])

        # Next E lines are edges with costs
        graph = {node: [] for node in node_coords}
        for i in range(V + 2, V + 2 + E):
            line = data[i].split()
            u, v, cost = line[0], line[1], int(line[2])
            graph[u].append((v, cost))

        # Start and goal nodes
        start_node = data[V + 2 + E]
        goal_node = data[V + 3 + E]

        # Run A* search
        optimal_path, total_cost = a_star_search(graph, node_coords, start_node, goal_node)

        if optimal_path:
            print("Optimal Path:", " -> ".join(optimal_path))
            print("Total Cost:", total_cost)
        else:
            print(f"No path found from {start_node} to {goal_node}.")

    except Exception as e:
        print("Error:", str(e))
