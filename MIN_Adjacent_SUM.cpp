#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;

    int A[n];

    for(int i=0;i<n;i++)
    {
        cin >> A[i];
    }

    sort(A,A+n);

    cout << A[0]+A[1] << endl;

    return 0;
}