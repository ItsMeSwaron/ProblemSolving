#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int T;
    cin >> T;

    for(long long int i=1;i<=T;i++)
    {
        long long int n, k;
        cin >> n >> k;

        vector <long long int> v;

        while(n--)
        {
            int x;
            cin >> x;

            v.push_back(x);
        }

        vector <long long int> ans;

        for(long long int j=k;j<v.size();j++)
        {
            ans.push_back(v[j]);
        }

        for(long long int j=0;j<k;j++)
        {
            ans.push_back(v[j]);
        }

        for(long long int x : ans)
        {
            cout << x << " ";
        }

        cout << endl;
    }

    return 0;
}