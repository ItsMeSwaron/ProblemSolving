#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector <int> v;
    v.push_back(10);
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(30);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);

    int val = 30;

    for(int i=0;i<v.size();i++)
    {
        if(v[i] == val)
        {
            v.erase(v.begin()+i);
            i--;
        }
    }      

    for(int x : v)
    {
        cout << x << " ";
    }

    return 0;
}