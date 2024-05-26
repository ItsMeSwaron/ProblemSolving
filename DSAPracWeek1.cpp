#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int N;
    cin >> N;
    
    vector <long long int> V(N);

    for(long long int i=0;i<N;i++)
    {
        cin >> V[i];
    }

    long long int signal = 0;

    sort(V.begin(),V.end());

    for(long long int i=0;i<N-1;i++)
    {
        if(V[i] == V[i+1])
        {
            signal++;
        }
    }

    if(signal == 0)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;    
    }
    

    return 0;
}