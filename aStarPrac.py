import math
import heapq

def heuristic(nodeCoords, startNode, goalNode):
    x1, y1 = nodeCoords[startNode]
    x2, y2 = nodeCoords[goalNode]
    return math.sqrt((x1-x2) ** 2 + (y1-y2) ** 2)

def aStarSearch(graph, nodeCoords, startNode, goalNode):
    priorityQueue = []
    heapq.heappush(priorityQueue, (0, startNode))

    gCost = {node : float('inf') for node in graph}
    gCost[startNode] = 0

    fCost = {node : float('inf') for node in graph}
    fCost[startNode] = heuristic(nodeCoords, startNode, goalNode)

    cameFrom = {}

    # openSet = set()
    # openSet.add(startNode)

    while priorityQueue:
        currentFCost, currentNode = heapq.heappop(priorityQueue)

        for childNode, childCost in graph[currentNode]:
            
            tentativeGCost = gCost[currentNode] + childCost

            if tentativeGCost < gCost[childNode]:
                gCost[childNode] = tentativeGCost
                fCost[childNode] = tentativeGCost + heuristic(nodeCoords, childNode, goalNode)
                heapq.heappush(priorityQueue, (fCost[childNode], childNode))
                cameFrom[childNode] = currentNode

    path = []

    currentNode = goalNode

    while currentNode != startNode:
        
        if currentNode not in cameFrom:
            return None, float('inf')
        
        path.append(currentNode)
        currentNode = cameFrom[currentNode]

    path.append(startNode)
    path.reverse()

    return path, gCost[goalNode]

if __name__ == '__main__':
    fileName = 'inputTara.txt' 
    try:
        with open(fileName, 'r') as file:
            data = file.read().splitlines()


        v = int(data[0])

        nodeCoords = {}
        
        for i in range(1,v+1):
            line = data[i].split()
            nodeCoords[line[0]] = (int(line[1]),int(line[2]))
        
        e = int(data[v+1])
        
        graph = {node : [] for node in nodeCoords}

        for i in range(v+2,v+e+2):
            line = data[i].split()
            u, v, cost = line[0], line[1], int(line[2])
            graph[u].append((v,cost))

        startNode = data[v+e+2]
        goalNode = data[v+e+3]
        print("file")

        ansPath, totalCost = aStarSearch(graph, nodeCoords, startNode, goalNode)

        if ansPath:
            print('Optimal path: ', end='')
            print('->'.join(ansPath))
            print(f'Total cost = {totalCost}')
        else:
            print('No path found')


    except Exception as e:
        print("Error:", str(e))