#include<bits/stdc++.h>
using namespace std;

vector <int> v[1000];
bool vis[1000];
bool path[1000];
bool ans = false;
stack <int> s;

void DFS(int src)
{
    vis[src] = true;
    path[src] = true;

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
    s.push(src);
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

    // if(ans)
    // {
    //     cout << "cycle" << endl;
    // }
    // else
    // {
    //     cout << "Nai" << endl;
    // }

    while(!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}