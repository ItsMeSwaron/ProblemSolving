#include<bits/stdc++.h>
using namespace std;

vector <pair<int,int>> v[1010];
int dis[1010];

class cmp
{
    public:
    bool operator()(pair <int,int> a, pair <int,int> b)
    {
        return a.second > b.second;
    }

};

void dijkstra(int src)
{
    priority_queue <pair <int,int>,vector<pair <int,int>>,cmp> pq;
    pq.push({src,0});
    dis[src] = 0;

    while(!pq.empty())
    {
        pair <int,int> p = pq.top();
        int node = p.first;
        int cost = p.second;
        pq.pop();

        for(pair <int,int> CNode : v[node])
        {
            int ChildNode = CNode.first;
            int ChildCost = CNode.second;
            
            if(cost + ChildCost < dis[ChildNode])
            {
                dis[ChildNode] = cost + ChildCost;
                pq.push({ChildNode,dis[ChildNode]});
            }
        }

    }
}

int main()
{
    vector <pair<int,double>> heu;
    int n, e;
    cin >> n >> e;

    int tmp = n;

    while(e--)
    {
        int a, b, c;
        cin >> a >> b >> c;

        v[a].push_back({b,c});
    }

    int start, goal;
    cin >> start >> goal;

    int gx, gy;
    cin >> gx >> gy;

    while(tmp--)
    {
        int a, x1, y1;
        cin >> a >> x1 >> y1;

        double ans;
        ans = sqrt(pow(x1-gx,2) + pow(y1-gy,2));

        heu.push_back({a,ans});
    }

    for(auto x : heu)
    {
        cout << x.first << " -> " << x.second << endl;
    }

    for(int i=0;i<n;i++)
    {
        dis[i] = INT_MAX;
    }

    // dijkstra(2);

    // for (int i = 0; i < n; i++)
    // {
    //     cout << i << "-> " << dis[i] << endl;
    // }

    return 0;
}