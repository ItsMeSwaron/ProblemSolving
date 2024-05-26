#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int N;
    cin >> N;

    priority_queue <long long int,vector<long long int>,greater<long long int>> A;

    for(long long int i=1;i<=N;i++)
    {
        long long int valz;
        cin >> valz;

        A.push(valz);
    }

    long long int Q;
    cin >> Q;

    for(long long int i=1;i<=Q;i++)
    {
        long long int queries;
        cin >> queries;

        if(queries == 0)
        {
            long long int X;
            cin >> X;

            A.push(X);
            cout << A.top() << endl;
        }
        else if(queries == 1)
        {
            if(!A.empty())
            {
                cout << A.top() << endl;
            }
            else
            {
                cout << "Empty" << endl;
            }
            
        }
        else if(queries == 2)
        {
            if(!A.empty())
            {
                A.pop();

                if(!A.empty())
                {
                    cout << A.top() << endl;
                }
                else
                {
                    cout << "Empty" << endl;
                }
                
            }
            else
            {
                cout << "Empty" << endl;
            }
        }
    }

    return 0;
}