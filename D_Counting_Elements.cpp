#include<bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    cin >> N;

    vector <int> A(N);

    for(int i=0;i<N;i++)
    {
        cin >> A[i];
    }

    int count = 0;

    for(auto it=A.begin();it<A.end();it++)
    {
        if(find(A.begin(),A.end(),*it+1) != A.end())
        {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}