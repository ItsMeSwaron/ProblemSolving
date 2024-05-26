#include<bits/stdc++.h>
using namespace std;

vector<int> v[1000];
bool vis[1000];
stack<int> sortedVertices; // To store vertices in topological order

void DFS(int src)
{
    vis[src] = true;

    for(int babiez : v[src])
    {
        if(!vis[babiez])
        {
            DFS(babiez);
        }
    }
    sortedVertices.push(src); // Push the vertex to the stack after all its children are visited
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

    memset(vis,false,sizeof(vis));

    for(int i = 0; i < n; ++i)
    {
        if(!vis[i])
        {
            DFS(i);
        }
    }

    // Print the vertices in topological order
    while(!sortedVertices.empty())
    {
        cout << sortedVertices.top() << " ";
        sortedVertices.pop();
    }

    return 0;
}
