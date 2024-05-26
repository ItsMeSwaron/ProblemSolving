#include<bits/stdc++.h>
using namespace std;

vector <int> v[1000];
bool vis[1000];
int parentNode[1000];
bool ans = false;

void BFS(int src)
{
    queue <int> q;
    q.push(src);
    vis[src] = true;

    while(q.empty() == false)
    {
        int par = q.front();
        q.pop();

        for(int child : v[par])
        {
            if(parentNode[par] != child && vis[child] == true)
            {
                ans = true;
            }

            if(vis[child] == false)
            {
                q.push(child);
                vis[child] = true;
                parentNode[child] = par;
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

    for(int i=0;i<n;i++)
    {
        vis[i] = false;
    }

    for(int i=0;i<n;i++)
    {
        parentNode[i] = -1;
    }

    int src;
    cin >> src;

    BFS(src);

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