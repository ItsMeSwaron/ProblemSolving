#include<bits/stdc++.h>
using namespace std;

vector <int> v[1000];
bool vis[1000];
int level[1000];

void BFS(int src, int des)
{
    queue <int> q;
    q.push(src);
    vis[src] = true;
    level[src] = 0;

    while(!q.empty())
    {
        int par = q.front();
        q.pop();

        if(par == des)
        {
            cout << "Min number of edges between (" << src << ", " << des << "): "<< level[par] << endl;
            break;
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
}

int main()
{
    int N, M;
    cin >> N >> M;

    while(M--)
    {
        int a, b;
        cin >> a >> b;

        v[a].push_back(b);
        v[b].push_back(a);
    }

    int src, des;
    cin >> src >> des;

    BFS(src,des);
    
    return 0;
}