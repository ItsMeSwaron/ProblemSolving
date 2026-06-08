import math
import heapq
from collections import defaultdict

def aStar(start, goal):
    # Create a priority queue with (cost + heuristic, current cost, node)
    pq = []
    heapq.heappush(pq, (heuristic[start], 0, start))  # (f_score, g_score, node)
    dis[start] = 0

    while pq:
        _, current_dist, current_node = heapq.heappop(pq)

        # if current_node == goal:
        #     break

        for neighbor, weight in v[current_node]:
            new_dist = current_dist + weight
            # f(n) = g(n) + h(n)
            f_score = new_dist + heuristic.get(neighbor, float('inf'))  # f = g + h

            if new_dist < dis[neighbor]:  # Check if we found a better path
                dis[neighbor] = new_dist
                parent[neighbor] = current_node
                heapq.heappush(pq, (f_score, new_dist, neighbor))

def printPath(node):
    if parent[node] is None:
        print(node, end=' ')
        return
    printPath(parent[node])
    print(node, end=' ')

def main():
    # Input reading
    with open('inputTara.txt', 'r') as file:
        lines = [line.strip() for line in file if line.strip()]  # Clean and remove empty lines

    print(f"First line of input: '{lines[0]}'")

    # First line: Number of nodes and edges
    try:
        n, e = map(int, lines[0].split())  # Only take the first two elements
    except ValueError:
        print("Error: The first line must contain exactly two integers.")
        return

    global v, heuristic, dis, parent
    v = defaultdict(list)
    heuristic = {}
    dis = {}
    parent = {}

    # Initialize `dis` and `parent` for all nodes encountered
    nodes = set()

    # Next `e` lines: Edges
    for i in range(1, e + 1):
        a, b, c = lines[i].split()
        c = int(c)
        v[a].append((b, c))
        v[b].append((a, c))  # Assuming undirected graph
        nodes.add(a)
        nodes.add(b)

    # Next line: Start and goal nodes
    start, goal = lines[e + 1].split()

    # Next line: Coordinates of the goal node
    gx, gy = map(int, lines[e + 2].split())

    # Initialize `dis` and `parent` for all nodes
    for node in nodes:
        dis[node] = float('inf')
        parent[node] = None

    # Remaining lines: Nodes and their coordinates
    for i in range(e + 3, e + 3 + n):
        node, x1, y1 = lines[i].split()
        x1, y1 = int(x1), int(y1)
        ans = math.sqrt((x1 - gx) ** 2 + (y1 - gy) ** 2)
        heuristic[node] = ans

    # Perform A* search
    aStar(start, goal)

    if dis[goal] == float('inf'):
        print(f"{start} -> Unreachable")
    else:
        printPath(goal)
        print(f"\nSolution cost {dis[goal]}")

if __name__ == "__main__":
    main()

#include <bits/stdc++.h>
# using namespace std;

# vector<pair<int, int>> v[1010];
# int dis[1010];
# int heuristic[1010];
# int parent[1010];

# class cmp 
# {
#     public:
    
#     bool operator()(pair<int, int> a, pair<int, int> b) 
#     {
#         return (a.second + heuristic[a.first]) > (b.second + heuristic[b.first]);
#     }
# };

# void aStar(int src, int goal) 
# {
#     priority_queue <pair<int, int>, vector<pair<int, int>>, cmp> pq;
#     pq.push({src, 0});
#     dis[src] = 0;
#     parent[src] = -1;

#     while(!pq.empty()) 
#     {
#         pair<int, int> p = pq.top();
#         int node = p.first;
#         int cost = p.second;
#         pq.pop();

#         if(node == goal) break;

#         for(pair<int, int> CNode : v[node]) 
#         {
#             int ChildNode = CNode.first;
#             int ChildCost = CNode.second;

#             if(cost + ChildCost < dis[ChildNode]) 
#             {
#                 dis[ChildNode] = cost + ChildCost;
#                 parent[ChildNode] = node;
#                 pq.push({ChildNode, dis[ChildNode]});
#             }
#         }
#     }
# }

# void printPath(int goal) 
# {
#     vector <int> path;

#     for(int node = goal; node != -1; node = parent[node]) 
#     {
#         path.push_back(node);
#     }

#     reverse(path.begin(), path.end());

#     cout << "Solution path: ";

#     for(int node : path) 
#     {
#         cout << node;
#         if(node != path.back()) cout << "-";
#     }

#     cout << endl;
# }

# int main() 
# {
#     int n, e;
#     cin >> n >> e;

#     while(e--) 
#     {
#         int a, b, c;
#         cin >> a >> b >> c;
#         v[a].push_back({b, c});
#     }

#     for(int i = 0; i < n; i++) 
#     {
#         dis[i] = INT_MAX;
#         heuristic[i] = 0;
#         parent[i] = -1;
#     }

#     int tmp = n;

#     int start, goal;
#     cin >> start >> goal;

#     int gx, gy;
#     cin >> gx >> gy;

#     while(tmp--)
#     {
#         int a, x1, y1;
#         cin >> a >> x1 >> y1;

#         int ans;
#         ans = sqrt(pow(x1-gx,2) + pow(y1-gy,2));

#         heuristic[a] = ans;
#     }

#     aStar(start, goal);

#     if(dis[goal] == INT_MAX) 
#     {
#         cout << start << " -> Unreachable\n";
#     } 
#     else 
#     {
#         printPath(goal);
#         cout << "Solution cost " << dis[goal] << endl;
#     }

#     return 0;
# }

