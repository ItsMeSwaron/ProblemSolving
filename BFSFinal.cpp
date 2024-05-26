#include<bits/stdc++.h>
using namespace std;

vector <int> v[1000];
bool vis[1000];
int level[1000];
int parent[1000];
bool ans = false;

void BFS(int src)
{
    queue <int> q;
    q.push(src);
    level[src] = 0;

    vis[src] = true;

    while(!q.empty())
    {
        int par = q.front();
        q.pop();

        for(int child : v[par])
        {
            if(parent[par] != child && vis[child] == true)
            {
                ans = true;
            }        

            if(!vis[child])
            {
                vis[child] = true;
                q.push(child);
                level[child] = level[par] + 1;
                parent[child] = par;
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
        int a, b;
        cin >> a >> b;

        v[a].push_back(b);
        v[b].push_back(a);
    }

    memset(vis,false,sizeof(vis));
    memset(level,-1,sizeof(level));
    memset(parent,-1,sizeof(parent));
    
    int src;
    cin >> src;

    BFS(src);

    if(ans)
    {
        cout << "cycle" << endl;
    }
    else
    {
        cout << "Nai" << endl;
    }

    return 0;
}