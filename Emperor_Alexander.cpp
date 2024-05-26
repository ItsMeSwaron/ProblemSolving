#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int parent[N];
int group_size[N];
bool vis[N];

void dsu_initialize(int n)
{
    for (int i = 1; i <= n; i++)
    {
        parent[i] = -1;
        group_size[i] = 1;
        vis[i] = false;
    }
}

int dsu_find(int node)
{
    if (parent[node] == -1)
    {
        return node;
    }

    int leader = dsu_find(parent[node]);
    parent[node] = leader;
    return leader;
}

void dsu_union_by_size(int node1, int node2)
{
    int leaderA = dsu_find(node1);
    int leaderB = dsu_find(node2);
    vis[node1] = true;
    vis[node2] = true;

    if (group_size[leaderA] > group_size[leaderB])
    {
        parent[leaderB] = leaderA;
        group_size[leaderA] += group_size[leaderB];
    }
    else
    {
        parent[leaderA] = leaderB;
        group_size[leaderB] += group_size[leaderA];
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

bool tracker(int n)
{
   for(int i=1;i<=n;i++)
   {
        if(!vis[i])
        {
            return false;
        }
   }
   return true;
}

int main()
{
    int n, e, tmp;
    cin >> n >> e;
    tmp = e;

    dsu_initialize(n);
    vector <Edge> edgeList;
    
    while (e--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edgeList.push_back(Edge(u, v, w));
    }
    
    sort(edgeList.begin(), edgeList.end(), cmp);
    
    long long int totalCost = 0;
    int count = 0;
    
    for (Edge ed : edgeList)
    {
        int leaderU = dsu_find(ed.u);
        int leaderV = dsu_find(ed.v);

        if (leaderU == leaderV)
        {
            continue;
        }
        else
        {
            dsu_union_by_size(ed.u, ed.v);
            totalCost += ed.w;
        }
            count++;
    }

    if(tracker(n) == true)
    {
        int FinalRoads = tmp - count;
        cout << FinalRoads << " " << totalCost << endl;
    }
    else
    {
        cout << "Not Possible" << endl;
    }

    return 0;
}