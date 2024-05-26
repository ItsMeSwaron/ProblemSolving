#include<bits/stdc++.h>
using namespace std;

void TOH(int n, char a, char b, char c)
{
    if(n > 0)
    {
        TOH(n-1,a,c,b);
        cout << "Moving from " << a << " to " << c << endl;
        TOH(n-1,b,a,c);
    }
}

int main()
{
    int n;
    cin >> n;

    TOH(n,'A','B','C');

    return 0;
}