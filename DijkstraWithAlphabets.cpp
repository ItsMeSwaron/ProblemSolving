#include<bits/stdc++.h>
using namespace std;

vector <pair<char,int>> v[1010];
int dis[1010];

class cmp
{
    public:
    bool operator()(pair <char,int> a, pair <char,int> b)
    {
        return a.second > b.second;
    }

};

void dijkstra(char src)
{
    priority_queue <pair <char,int>,vector<pair <char,int>>,cmp> pq;
    pq.push({src,0});
    dis[tolower(src)-'a'] = 0;

    while(!pq.empty())
    {
        pair <char,int> p = pq.top();
        char node = p.first;
        int cost = p.second;
        pq.pop();

        for(pair <char,int> CNode : v[node])
        {
            char ChildNode = CNode.first;
            int ChildCost = CNode.second;
            
            if(cost + ChildCost < dis[ChildNode-'a'])
            {
                dis[ChildNode-'a'] = cost + ChildCost;
                pq.push({ChildNode,dis[ChildNode-'a']});
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
        char a, b;
        cin >> a >> b;
        int c;
        cin >> c;

        v[tolower(a)-'a'].push_back({b,c});
    }

    for(int i=0;i<n;i++)
    {
        dis[i] = INT_MAX;
    }

    dijkstra('S');

    for (int i = 0; i < 26; i++)
    {
        cout << char(toupper(char(i+'a'))) << " -> " << dis[i] << endl;
    }

    return 0;
}
