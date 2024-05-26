#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin >> T;

    for(int i=1;i<=T;i++)
    {
        int n;
        cin >> n;

        int a[n];
        for(int j=0;j<n;j++)
        {
            cin >> a[j];
        }

        if(n%2 != 0)
        {
            cout << "-1" << endl;
        }
        else
        {
            int holder[2] = {0};

            for(int k=0;k<n;k++)
            {
                if(a[k]%2 == 0)
                {
                    holder[0]++;
                } 
                else
                {
                    holder[1]++;
                }
            }

            if(holder[0] == holder[1])
            {
                cout << "0" << endl;
            }
            else if(holder[0] > holder[1])
            {
                int ans = (holder[0] - holder[1]) / 2;
                cout << ans << endl;
            }
            else if(holder[1] > holder[0])
            {
                int Ans = (holder[1] - holder[0]) / 2;
                cout << Ans << endl;
            }

        }

    }

    return 0;
}