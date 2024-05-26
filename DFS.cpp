#include<bits/stdc++.h>
using namespace std;

vector <int> v[1000];
bool vis[1000];

void DFS(int src)
{
    cout << src << " ";
    vis[src] = true;

    for(int babiez : v[src])
    {
        if(vis[babiez] == false)
        {
            DFS(babiez);
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;

    while(e--)
    {
        int a, b;
        cin >> a >> b;

        v[a].push_back(b);
        v[b].push_back(a);
    }

    memset(vis,false,sizeof(vis));

    int src;
    cin >> src;

    DFS(src);

    return 0;
}