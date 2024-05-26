#include<bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    cin >> N;

    int A[N];
    
    for(int i=0;i<N;i++)
    {
        cin >> A[i];
    }

    int copy[N];

    for(int i=0;i<N;i++)
    {
        copy[i] = A[i];
    }

    int i=0,j=N-1;

    while(i < j)
    {
        swap(A[i],A[j]);
        i++;
        j--;
    }

    int signal = 0;

    for(int i=0;i<N;i++)
    {
        if(copy[i] == A[i])
        {
            signal++;
        }
    }

    if(signal == N)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }


    return 0;
}