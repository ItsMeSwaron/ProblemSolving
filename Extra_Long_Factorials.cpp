#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;

    vector <int> v;
    vector <int> ans;
    vector <int> tmpV;

    int val = 1;

    while(val != n+1)
    {
        v.push_back(val);
        val++;
    }

    // for(int x : v)
    // {
    //     cout << x << " ";
    // }

    ans.push_back(1);

    for(int i=0;i<n;i++)
    {
        int tmp = 0;

        for(int j=ans.size()-1;j>=0;j--)
        {
            int 
        }
    }


    return 0;
}