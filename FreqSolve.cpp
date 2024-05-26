#include<bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    cin >> N;

    int X[N];

    for(int i=0;i<N;i++)
    {
        cin >> X[i];
    }

    int frq[10] = {0};

    for(int i=0;i<N;i++)
    {
        int num = X[i];
        frq[num]++;
    } 

    // for(int Numz : frq)
    // {
    //     cout << Numz << " ";
    // }

    vector <int> v;

    int MaxInd = INT_MIN;
    int MaxVal;
    
    for(int i=0;i<10;i++)
    {
        if(MaxInd < frq[i])
        {
            MaxInd = frq[i];
            MaxVal = i;
        }
    }

    frq[MaxInd] = 0;

    while(MaxInd != 0)
    {
        v.push_back(MaxVal);
        MaxInd--;
    }

    cout << MaxInd << " " << MaxVal << endl;

    // int tempo = ;

    // while(mx != 0)
    // {
    //     cout << frq[tempo] << " ";
    //     mx--;
    // }


        // if(frq[i] > 0)
        // {
        //     while(frq[i] != 0)
        //     {
        //         v.push_back(i);
        //         frq[i]--;
        //     }
        // }
    // reverse(v.begin(),v.end());

    for(int Numz : v)
    {
        cout << Numz << " ";
    }

    return 0;
}