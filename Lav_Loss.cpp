#include<bits/stdc++.h>
using namespace std;
int main()
{
    double X, Y, Z;
    cin >> X >> Y >> Z;

    double ans;

    ans = X / (1 - (Y/100));

    double FinalAns = ans * (1 + (Z/100));

    printf("%.2f", FinalAns);

    return 0;
}