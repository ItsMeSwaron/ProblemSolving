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

    while(q.empty() == false)
    {
        int par = q.front();
        q.pop();

        // jabotiyo kaaj korbo
        if(par == des)
        {
            cout << level[des] << endl;
            break;
        }

        for(int child : v[par])
        {
            if(vis[child] == false)
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
    int Node, Edge;
    cin >> Node >> Edge;

    while(Edge != 0)
    {
        int A, B;
        cin >> A >> B;

        v[A].push_back(B);
        v[B].push_back(A);

        Edge--;
    }

    for(int i=0;i<1000;i++)
    {
        vis[i] = false;
    }

    int src, des;
    cin >> src >> des;

    BFS(src,des);
    

    return 0;
}