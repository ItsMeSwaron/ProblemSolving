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

    for(auto it=A.end()-1;it>=A.begin();it--)
    {
        cout << *it << " ";
    }

    return 0;
}