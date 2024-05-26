#include<bits/stdc++.h>
using namespace std;

vector <pair<int,int>> v[1010];
dis[1010];

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

    int src;
    cin >> src;
    dijkstra(src);

    return 0;
}