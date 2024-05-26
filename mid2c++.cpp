#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin >> T;

    for(int i=1;i<=T;i++)
    {
        int N;
        cin >> N;

        int S;
        cin >> S;

        int A[N];

        for(int i=0;i<N;i++)
        {
            cin >> A[i];
        }  

        int signal = 0;

        for(int j=0;j<N-2;j++)
        {
            for(int k=j+1;k<N-1;k++)
            {
                for(int l=k+1;l<N;l++)
                {
                    if(A[j] + A[k] + A[l] == S)
                    {
                        signal++;
                    }
                }
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


    }

    return 0;
}