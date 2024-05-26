#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector <int> v = {1,2,5,3,8,6,7};

    for(int i=0;i<6;i++)
    {
        for(int j=i+1;j<7;j++)
        {
            if(v[i] < v[j])
            {
                swap(v[i],v[j]);
            }
        }
    }

    for(int x : v)
    {
        cout << x << endl;
    }

    return 0;
}