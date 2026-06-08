#include<bits/stdc++.h>
using namespace std;
int main()
{
    int sum = 0;

    for(int i=1;i<=30;i++)
    {
        sum += (3*i) + 1;
    }

    cout << sum << endl;

    return 0;
}