#include<bits/stdc++.h>
using namespace std;

vector <int> v[1000];
bool vis[1000];

void BFS(int src, int des)
{
    memset(vis,false,sizeof(vis));
    queue <pair<int,int>> q;
    q.push({src,0});
    vis[src] = true;

    int signal = 0;

    while(!q.empty())
    {
        pair <int,int> p = q.front();
        q.pop();

        int par = p.first;
        int level = p.second;

        if(par == des)
        {
            cout << level << endl;
            signal++;
        }

        for(int child : v[par])
        {
            if(vis[child] == false)
            {
                q.push({child,level+1});
                vis[child] = true;
            }
        }
    }

    if(signal == 0)
    {
        cout << "-1" << endl;
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

    int Q;
    cin >> Q;

    for(int i=1;i<=Q;i++)
    {
        int source, destin;
        cin >> source >> destin;

        BFS(source,destin);
    }

    return 0;
}