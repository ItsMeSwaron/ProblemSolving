#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 

    int T;
    cin >> T;

    while(T--)
    {
        string M, W;
        cin >> M >> W;

        int szM = M.size();
        int szW = W.size();

        int arr1[30] = {0};
        int arr2[30] = {0};

        // cout << ('b' - 0) - 97 << endl;

        for(int i=0;i<szM;i++)
        {
            arr1[((M[i] - 0) - 97)-0]++;
            // cout << ((M[i] - 0) - 97)-0 << endl;
        }

        for(int i=0;i<szW;i++)
        {
            arr2[((W[i] - 0) - 97)-0]++;
        }

        int signal = 0;

        if(szM > szW)
        {
            for(int i=0;i<30;i++)
            {
                if((arr2[i] > 0 && arr1[i] == 0))
                {
                    signal = 1;
                    break;
                } 
            }

            if(signal) cout << "NO" << endl;
            else cout << "YES" << endl;
        }
        else if(szM < szW)
        {
            for(int i=0;i<30;i++)
            {
                if((arr1[i] > 0 && arr2[i] == 0))
                {
                    signal = 1;
                    break;
                } 
            }

            if(signal) cout << "NO" << endl;
            else cout << "YES" << endl;
        }
        else
        {
            for(int i=0;i<30;i++)
            {
                if(arr1[i] != arr2[i])
                {
                    signal = 1;
                    break;
                } 
            }

            if(signal) cout << "NO" << endl;
            else cout << "YES" << endl;
        }

    }

    return 0;
}