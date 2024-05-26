#include<bits/stdc++.h>
using namespace std;

long long int solver(int X, int N)
{
    long long int ans = 0;

    for(int i=2;i<=N;i=i+2)
    {
        ans = ans + pow(X,i);
    }

    return ans;

}

int main()
{
    int X,N;
    long long int S;

    cin >> X >> N;

    S = solver(X,N);

    cout << S << endl;

    return 0;
}