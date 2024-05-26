#include<bits/stdc++.h>
using namespace std;

vector <pair<int,int>> v[1010];
int dis[1010];

void dijkstra(int src)
{
    queue <pair<int,int>> q;
    q.push({src,0});
    dis[src] = 0;

    while(!q.empty())
    {
        pair <int,int> p = q.front();
        int node = p.first;
        int cost = p.second;
        q.pop();

        for(pair <int,int> CNode : v[node])
        {
            int ChildNode = CNode.first;
            int ChildCost = CNode.second;

            if(cost + ChildCost < dis[ChildNode])
            {
                dis[ChildNode] = cost + ChildCost;
                q.push({ChildNode,dis[ChildNode]});
            }
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;

    while(e--)
    {
        int a, b, c;
        cin >> a >> b >> c;

        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }

    for(int i=0;i<n;i++)
    {
        dis[i] = INT_MAX;
    }

    dijkstra(0);

    for (int i = 0; i < n; i++)
    {
        cout << i << "-> " << dis[i] << endl;
    }


    return 0;
}