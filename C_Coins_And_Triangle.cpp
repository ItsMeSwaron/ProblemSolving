#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 

    int T;
    cin >> T;

    for(int i=0;i<T;i++)
    {
        int N;
        cin >> N;

        int tmp = 0;
        int cnt = 1;
        int ans = 0;

        if(N < 4) 
        {
            cout << 2 << endl;
            continue;
        }

        while(tmp <= N) 
        {
            tmp += cnt;
            cnt++;
            ans++;
        }

        cout << --ans << endl;
    }
    
    return 0;
}