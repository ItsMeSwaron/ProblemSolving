#include<bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    cin >> N;

    vector <int> A(N);
    vector <int> :: iterator it;

    for(int i=0;i<N;i++)
    {
        cin >> A[i];
    }

    for(it=A.begin();it<A.end();it++)
    {
        if(*it > 0)
        {
            cout << "1" << " ";
        }
        else if(*it < 0)
        {
            cout << "2" << " "; 
        }
        else
        {
            cout << "0" << " ";
        }
    }

    cout << endl;

    return 0;
}