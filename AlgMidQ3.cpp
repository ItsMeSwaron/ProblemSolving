#include <bits/stdc++.h>
using namespace std;
class Edge
{
public:
    long long int u, v, c;
    Edge(long long int u, long long int v, long long int c)
    {
        this->u = u;
        this->v = v;
        this->c = c;
    }
};

long long int dis[1000000];

int main()
{
    long long int n, e;
    cin >> n >> e;
    vector <Edge> EdgeList;
    while (e--)
    { 
        long long int u, v, c;
        cin >> u >> v >> c;
        EdgeList.push_back(Edge(u, v, c));
    }
    for (int i = 0; i <= n; i++)
    {
        dis[i] = 1e18;
    }

    long long int S;
    cin >> S;
    dis[S] = 0;    

    for (int i = 1; i <= n - 1; i++)
    {
        for (Edge ed : EdgeList)
        {
            long long int u, v, c;
            u = ed.u;
            v = ed.v;
            c = ed.c;
            if (dis[u] < 1e18 && dis[u] + c < dis[v])
            {
                dis[v] = dis[u] + c;
            }
        }
    }
     
    bool cycle = false;
    
    for (Edge ed : EdgeList)
    {
        long long int u, v, c;
        u = ed.u;
        v = ed.v;
        c = ed.c;
        if (dis[u] < 1e18 && dis[u] + c < dis[v])
        {
            cycle = true;
            break;
        }
    }

    if(cycle)
    {
        cout << "Negative Cycle Detected" << endl;
    }
    else
    {
        long long int T;
        cin >> T;
        
        for(int i=1;i<=T;i++)
        {
            long long int D;
            cin >> D;
            
            if(dis[D] == 1e18)
            {
                cout << "Not Possible" << endl;
            }
            else if(S == D)
            {
                cout << "0" << endl;
            }
            else
            {
                cout << dis[D] << endl;
            }
        }        
        
    }
  
    return 0;
}