#include<bits/stdc++.h>
using namespace std;

vector <int> v[1000];
bool vis[1000];
int level[1000];

int BFS(int src, int N)
{
    queue <int> q;
    q.push(src);
    level[src] = 0;
    vis[src] = true; 
    int babus = 0;

    while(!q.empty())
    {
        int par = q.front();
        q.pop();

        if(par == N)
        {
            for(int babiez : v[par])
            {
                babus++;
            }
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

    return babus;

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

    int N;
    cin >> N;

    cout << BFS(0,N) << endl;

    return 0;
}