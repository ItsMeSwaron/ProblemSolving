#include<bits/stdc++.h>
using namespace std;

vector <int> v[100005];
bool vis[100005];
int level[100005];

void BFS(int src, int des, int k)
{
    queue <int> q;
    q.push(src);
    level[src] = 0;
    vis[src] = true;
    int par;

    while(!q.empty())
    {
        par = q.front();
        q.pop();

        if(par == des)
        {
            if(level[par] % 2 == 0 && k >= level[par] / 2)
            {
                cout << "YES" << endl;
                break;
            }
            else if(level[par] % 2 != 0 && k >= (level[par] / 2) + 1)
            {
                cout << "YES" << endl;
                break;
            }
            else
            {
                cout << "NO" << endl;
                break;
            }
        }

        for(int child : v[par])
        {
            if(!vis[child])
            {
                q.push(child);
                vis[child] = true;
                level[child] = level[par] + 1;
            }
        }
    } 

    if(par != des)
    {
        cout << "NO" << endl;
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
    memset(level,0,sizeof(level));

    int src, des, k;
    cin >> src >> des >> k;

    BFS(src,des,k);

    return 0;
}