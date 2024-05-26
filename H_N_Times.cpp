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

        char line[n];

        char ch;
        cin >> ch;

        for(int j=0;j<n;j++)
        {
            line[j] = ch;
        }

        for(int k=0;k<n;k++)
        {
            cout << line[k] << " ";
        }

        cout << endl;

    }

    return 0;
}