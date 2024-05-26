#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x[5] = {3, 2, 5, 1, 4};

    for(int i=0;i<5-1;i++)
    {
        for(int j=0;j<5-1-i;j++)
        {
            if(x[j] > x[j+1])
            {
                swap(x[j],x[j+1]);
            }
        }
    }

    for(int z : x)
    {
        cout << z << " ";
    }

    return 0;
}