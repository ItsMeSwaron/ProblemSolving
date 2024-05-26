#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x;
    cin >> x;

    vector <int> v(x);

    for(int i=0;i<x;i++)
    {
        cin >> v[i];
    }

    for(int i : v)
    {
        cout << i << " ";
    }

    return 0;
}