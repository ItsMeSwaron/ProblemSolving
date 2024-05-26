#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin >> T;

    for(long long int i=1;i<=T;i++)
    {
        long long int N;
        cin >> N;

        list <long long int> A;

        for(long long int j=1;j<=N;j++)
        {
            int x;
            cin >> x;
            A.push_back(x);
        }

        A.sort();

        A.unique();

        for(long long int X : A)
        {
            cout << X << " ";
        }

        cout << endl;

    }

    return 0;
}