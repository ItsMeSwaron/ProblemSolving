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
        getchar();

        char S[N];

        for(int j=0;j<N;j++)
        {
            cin >> S[j];
        }

        int count = 0;

        for(int j=0;j<N;j++)
        {
            if(S[j] == '1')
            {
                if(j+1 != N && S[j+1] == '0')
                {
                    count++;
                }
            }
            else
            {
                if(j+1 != N && S[j+1] == '1')
                {
                    count++;
                }                
            }
        }
        cout << count << endl;
    }

    return 0;
}