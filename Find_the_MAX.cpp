#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<long long int,long long int> &a,pair<long long int,long long int> &b)
{
    return a.second > b.second;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    priority_queue<long long int> pq;
    
    long long int Q;
    cin >> Q;
    long long int query, X;
    long long int frq[1000] = {0};
    vector <pair<long long int,long long int>> v;

    while(Q--)
    {
        cin >> query;

        if(query == 1)
        {
            cin >> X;
            pq.push(X);
            for(int i=0;i<1000;i++)
            {
                frq[X]++;
            }
        }
        else
        {
            if(!pq.empty())
            {
                for(int i=0;i<1000;i++)
                {
                    if(frq[i] > 0)
                    {
                        v.push_back({frq[i],i});
                    }
                }

                if(!v.empty())
                {
                    sort(v.begin(),v.end(),cmp);
                }

                if(!pq.empty() && !v.empty() && pq.top() == v[0].first)
                {
                    cout << pq.top() << "\n";
                    int copy = pq.top();
                    while(!pq.empty() && pq.top() == copy)
                    {
                        pq.pop();
                    }
                }
            }
            else
            {
                cout << "empty\n";
            }
        }
    }

    return 0;
}