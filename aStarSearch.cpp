#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> v[1010];
int dis[1010];
int heuristic[1010];
int parent[1010];

class cmp 
{
    public:
    
    bool operator()(pair<int, int> a, pair<int, int> b) 
    {
        return (a.second + heuristic[a.first]) > (b.second + heuristic[b.first]);
    }
};

void aStar(int src, int goal) 
{
    priority_queue <pair<int, int>, vector<pair<int, int>>, cmp> pq;
    pq.push({src, 0});
    dis[src] = 0;
    parent[src] = -1;

    while(!pq.empty()) 
    {
        pair<int, int> p = pq.top();
        int node = p.first;
        int cost = p.second;
        pq.pop();

        // if(node == goal) break;

        for(pair<int, int> CNode : v[node]) 
        {
            int ChildNode = CNode.first;
            int ChildCost = CNode.second;

            if(cost + ChildCost < dis[ChildNode]) 
            {
                dis[ChildNode] = cost + ChildCost;
                parent[ChildNode] = node;
                pq.push({ChildNode, dis[ChildNode]});
            }
        }
    }
}

void printPath(int goal) 
{
    vector <int> path;

    for(int node = goal; node != -1; node = parent[node]) 
    {
        path.push_back(node);
    }

    reverse(path.begin(), path.end());

    cout << "Solution path: ";

    for(int node : path) 
    {
        cout << node;
        if(node != path.back()) cout << "-";
    }

    cout << endl;
}

int main() 
{
    int n, e;
    cin >> n >> e;

    while(e--) 
    {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
    }

    for(int i = 0; i < n; i++) 
    {
        dis[i] = INT_MAX;
        heuristic[i] = 0;
        parent[i] = -1;
    }

    int tmp = n;

    int start, goal;
    cin >> start >> goal;

    int gx, gy;
    cin >> gx >> gy;

    while(tmp--)
    {
        int a, x1, y1;
        cin >> a >> x1 >> y1;

        int ans;
        ans = sqrt(pow(x1-gx,2) + pow(y1-gy,2));

        heuristic[a] = ans;
    }

    aStar(start, goal);

    if(dis[goal] == INT_MAX) 
    {
        cout << start << " -> Unreachable\n";
    } 
    else 
    {
        printPath(goal);
        cout << "Solution cost " << dis[goal] << endl;
    }

    return 0;
}

