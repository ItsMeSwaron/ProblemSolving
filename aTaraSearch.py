import heapq
import math

# Graph representation and arrays
v = [[] for _ in range(1010)]
dis = [float('inf')] * 1010
heuristic = [0] * 1010
parent = [-1] * 1010

def aStar(src, goal):
    pq = []  # Priority queue
    heapq.heappush(pq, (0 + heuristic[src], src, 0))  # (f(n), node, g(n))
    dis[src] = 0
    parent[src] = -1

    while pq:
        _, node, cost = heapq.heappop(pq)

        if node == goal:
            break

        for CNode in v[node]:
            ChildNode, ChildCost = CNode
            if cost + ChildCost < dis[ChildNode]:
                dis[ChildNode] = cost + ChildCost
                parent[ChildNode] = node
                heapq.heappush(pq, (dis[ChildNode] + heuristic[ChildNode], ChildNode, dis[ChildNode]))

def printPath(goal):
    path = []
    node = goal
    while node != -1:
        path.append(node)
        node = parent[node]
    path.reverse()

    print("Solution path: ", end="")
    for i in range(len(path)):
        print(path[i], end="")
        if i != len(path) - 1:
            print("-", end="")
    print()

def main():
    n, e = map(int, input().split())  # Number of nodes and edges

    for _ in range(e):
        a, b, c = map(int, input().split())
        v[a].append((b, c))

    for i in range(n):
        dis[i] = float('inf')
        heuristic[i] = 0
        parent[i] = -1

    tmp = n
    start, goal = map(int, input().split())
    gx, gy = map(int, input().split())

    while tmp > 0:
        tmp -= 1
        a, x1, y1 = map(int, input().split())
        ans = math.sqrt((x1 - gx) ** 2 + (y1 - gy) ** 2)
        heuristic[a] = ans

    aStar(start, goal)

    if dis[goal] == float('inf'):
        print(f"{start} -> Unreachable")
    else:
        printPath(goal)
        print(f"Solution cost {dis[goal]}")

if __name__ == "__main__":
    main()
