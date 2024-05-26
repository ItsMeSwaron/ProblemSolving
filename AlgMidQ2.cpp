#include<bits/stdc++.h>
#define ll long long int
using namespace std;

vector <pair<ll,ll>> V[1010];
ll Dis[1010];

class cmp
{
    public:
    bool operator()(pair <ll,ll> a, pair <ll,ll> b)
    {
        return a.second > b.second;
    }

};

void dijkstra(ll src)
{
    priority_queue <pair<ll,ll>,vector<pair<ll,ll>>,cmp> pq;
    pq.push({src,0});
    Dis[src] = 0;

    while(!pq.empty())
    {
        pair <ll,ll> p = pq.top();
        ll node = p.first;
        ll cost = p.second;
        pq.pop();

        for(pair <ll,ll> PairChild : V[node])
        {
            ll ChildNode = PairChild.first;
            ll ChildCost = PairChild.second;

            if(cost + ChildCost < Dis[ChildNode])
            {
                Dis[ChildNode] = cost + ChildCost;
                pq.push({ChildNode,Dis[ChildNode]});
            }
        }
    }
}

int main()
{
    ll N, E;
    cin >> N >> E;

    while(E--)
    {
        ll A, B, W;
        cin >> A >> B >> W;

        V[A].push_back({B,W});
    }

    for(ll i=1;i<=N;i++)
    {
        Dis[i] = INT_MAX;
    }

    ll S;
    cin >> S;

    ll T;
    cin >> T;

    for(ll i=1;i<=T;i++)
    {
        ll D, DW;
        cin >> D >> DW;

        dijkstra(S);

        if(Dis[D] <= DW)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }


    return 0;
}