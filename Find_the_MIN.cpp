#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    priority_queue<long long int,vector<long long int>,greater<long long int>> pq;
    
    long long int Q;
    cin >> Q;
    long long int query, X;

    while(Q--)
    {
        cin >> query;

        if(query == 1)
        {
            cin >> X;
            pq.push(X);
        }
        else
        {
            if(!pq.empty())
            {
                cout << pq.top() << "\n";
                int copy = pq.top();
                while(!pq.empty() && pq.top() == copy)
                {
                    pq.pop();
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