#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int parent[N];
int Level[N];

void DSUInitialize(int n)
{
    for (int i = 1; i <= n; i++)
    {
        parent[i] = -1;
        Level[i] = 1;
    }
}

int DSULeaderFinder(int node)
{
    if (parent[node] == -1)
    {
        return node;
    }

    int leader = DSULeaderFinder(parent[node]);
    parent[node] = leader;
    return leader;
}

void DSUUnionBYLevel(int node1, int node2)
{
    int leaderA = DSULeaderFinder(node1);
    int leaderB = DSULeaderFinder(node2);

    if(Level[leaderA] > Level[leaderB])
    {
        parent[leaderB] = leaderA; 
    }
    else if (Level[leaderB] > Level[leaderA])
    {
        parent[leaderA] = leaderB;
    }
    else
    {
        parent[leaderA] = leaderB;
        Level[leaderB]++;
    }    
}

class Edge
{
public:
    int u, v, w;
    Edge(int u, int v, int w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

bool cmp(Edge a, Edge b)
{
    return a.w < b.w;
}

int main()
{
    int n, e;
    cin >> n >> e;

    DSUInitialize(n);
    vector<Edge> edgeList;
 
    while (e--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edgeList.push_back(Edge(u, v, w));
    }

    sort(edgeList.begin(), edgeList.end(), cmp);
    
    long long totalCost = 0;
    int count = 0;
    
    for (Edge ed : edgeList)
    {
        int leaderU = DSULeaderFinder(ed.u);
        int leaderV = DSULeaderFinder(ed.v);
        
        if (leaderU == leaderV)
        {
            continue;
        }
        else
        {
            DSUUnionBYLevel(ed.u, ed.v);
            totalCost = totalCost + ed.w;
            count++;
        }
    }

    if(count == n-1)
    {
        cout << totalCost << endl;
    }
    else
    {
        cout << "-1" << endl;
    }

    return 0;
}