#include<bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    cin >> N;

    vector <int> A(N);

    for(int i=0;i<N;i++)
    {
        cin >> A[i];
    }

    int count = 0;

    for(auto it1=A.begin();it1<A.end()-1;it1++)
    {
        for(auto it2=it1+1;it2<A.end();it2++)
        {
            if(*it1+1 == *it2 || *it1-1 == *it2)
            {
                count++;
                break;
            }
        }

    }

    cout << count << endl;

    return 0;
}