#include<bits/stdc++.h>
using namespace std;

bool cmp(vector<int> &a, vector<int> &b)
{
    return a[1] > b[1];
}

int main()
{
    vector <vector<int>> v = {{1,2},{5,7},{3,8},{24,9},{5,34}};

    sort(v.begin(),v.end(),cmp);

    for(auto x : v)
    {
        for(auto y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }

    return 0;
}