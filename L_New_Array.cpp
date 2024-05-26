#include<bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    cin >> N;

    vector <int> A(N);
    vector <int> B(N);

    for(int i=0;i<N;i++)
    {
        cin >> A[i];
    }

    for(int i=0;i<N;i++)
    {
        cin >> B[i];
    }

    vector <int> C(N+N);

    C = B;

    C.insert(C.begin()+N,A.begin(),A.end());

    for(int x : C)
    {
        cout << x << " ";
    }

    return 0;
}