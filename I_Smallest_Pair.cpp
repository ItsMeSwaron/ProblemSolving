#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin >> T;

    for(int k=1;k<=T;k++)
    {
        int N;
        cin >> N;

        int A[N];

        for(int s=0;s<N;s++)
        {
            cin >> A[s];
        }

        int i=0, j=N-1;

        int mn;
        
        mn = INT_MAX;

        for(int i=0;i<N-1;i++)
        {
            for(int j=i+1;j<N;j++)
            {
                int nums = A[i] + A[j] + j - i; 

                if(mn > nums)
                {
                    mn = nums;
                }            
            }


        }

        cout << mn << endl;

    }


    return 0;
}