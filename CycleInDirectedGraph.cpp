#include<bits/stdc++.h>
using namespace std;

vector <int> v[1000];
bool vis[1000];
bool path[1000];
bool ans = false;

void DFS(int src)
{
    vis[src] = true;
    path[src] = true;
    // cout << src << " ";

    for(int child : v[src])
    {
        if(path[child] == true)
        {
            ans = true;
        }
        if(vis[child] == false)
        {
            DFS(child);
        }
    }
    path[src] = false;
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
    }

    for(int i=0;i<1000;i++)
    {
        vis[i] = false;
    }

    for(int i=0;i<1000;i++)
    {
        path[i] = false;
    }

    for(int i=0;i<n;i++)
    {
        if(vis[i] == false)
        {
            DFS(i);
        }
    }

    if(ans == true)
    {
        cout << "cycle detected" << endl;
    }
    else
    {
        cout << "no cycle" << endl;
    }    

    return 0;
}