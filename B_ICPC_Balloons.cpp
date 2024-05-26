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

        char s[n];

        for(int j=0;j<n;j++)
        {
            cin >> s[j];
        }

        int alpha[27] = {0};

        for(int k=0;k<n;k++)
        {
            int nums = s[k] - 65;
            alpha[nums]++;
        }

        int marks = 0;

        for(int k=0;k<27;k++)
        {
            if(alpha[k] > 1)
            {
                marks = marks + alpha[k] + 1;
            }

            if(alpha[k] == 1)
            {
                marks = marks + 2;
            }
        }

        cout << marks  << endl;


    }

    return 0;
}
