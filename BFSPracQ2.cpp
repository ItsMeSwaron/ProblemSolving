#include<bits/stdc++.h>
using namespace std;

vector <int> v[1000];
bool vis[1000];
int level[1000];
vector <int> REV;

void BFS(int src, int L)
{
    queue <int> q;
    q.push(src);
    vis[src] = true;
    level[src] = 0;

    while(!q.empty())
    {
        int par = q.front();
        q.pop();

        if(level[par] == L)
        {
            REV.push_back(par);
        }
        else
        {
            for(int childz : v[par])
            {
                if(vis[childz] == false)
                {
                    q.push(childz);
                    vis[childz] = true;
                    level[childz] = level[par] + 1; 
                }
            }
        }
    }

    reverse(REV.begin(),REV.end());

    for(int manz : REV)
    {
        cout << manz << " ";
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

    int L;
    cin >> L;

    BFS(0,L);

    return 0;
}