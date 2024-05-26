#include<bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    cin >> N;

    int x[N];
    
    for(int i=0;i<N;i++)
    {
        cin >> x[i];
    }

    sort(x,x+N,greater<int>());

    int left = 0;
    int right = N - 1;

    while(true)
    {
        int midel = (left + right) / 2;
        
        if(x[midel] == 0)
        {
            // bame jabo
            right = midel - 1;
        }
        else
        {
               
        }
    }

    return 0;
}