#include<bits/stdc++.h>
using namespace std;

vector<int> v[1000];
bool vis[1000];
int maxCostPath[1000]; // To store the maximum cost path for each vertex

void BFS(int src, int minCost)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;
    maxCostPath[src] = 0;

    while (!q.empty())
    {
        int par = q.front();
        q.pop();

        for (int child : v[par])
        {
            if (!vis[child])
            {
                vis[child] = true;
                maxCostPath[child] = max(maxCostPath[par], maxCostPath[child]/* cost of edge par->child */);
                q.push(child);
            }
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;

    while (e--)
    {
        int a, b, weight;
        cin >> a >> b >> weight;

        v[a].push_back(b); 
        v[b].push_back(a);// Assuming the graph is directed
        // Store edge weights if applicable
        // edgeWeight[a][b] = weight;

        // For undirected graph
        // v[b].push_back(a);
        // edgeWeight[b][a] = weight;
    }

    int src, dest, minCost;
    cin >> src >> dest >> minCost;

    memset(vis, false, sizeof(vis));
    memset(maxCostPath, INT_MIN, sizeof(maxCostPath));

    BFS(src, minCost);

    if (maxCostPath[dest] > minCost)
    {
        cout << "Max cost path found: " << maxCostPath[dest] << endl;
    }
    else
    {
        cout << "No path found with cost greater than " << minCost << endl;
    }

    return 0;
}
