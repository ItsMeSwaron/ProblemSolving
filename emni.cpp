#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector <int> v;

    v.push_back(50);
    v.push_back(40);
    v.push_back(30);
    v.push_back(20);
    v.push_back(10);

    cout << is_sorted(v.begin(),v.end(),greater<int>()) << endl;

    return 0;
}