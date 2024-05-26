// #include<bits/stdc++.h>
// using namespace std;

// bool cmp(pair<int,int> &a, pair<int,int> &b)
// {
//     return a.first > b.first;
// }

// int main()
// {
//     long long int T;
//     cin >> T;

//     for(long long int i=1;i<=T;i++)
//     {
//         long long int N;
//         cin >> N;

//         long long int H[N];

//         for(long long int j=0;j<N;j++)
//         {
//             cin >> H[j];
//         }

//         vector <pair<int,int>> v;

//         for(long long int j=0;j<N;j++)
//         {
//             v.push_back({H[j],j});
//         }        

//         sort(v.begin(),v.end(),cmp);

//         if(v[0].second < v[1].second)
//         {
//             cout << v[0].second << " " << v[1].second << endl;
//         }
//         else
//         {
//             cout << v[1].second << " " << v[0].second << endl;
//         }
//     }

//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int T;
    cin >> T;

    for(long long int k=1;k<=T;k++)
    {
        long long int N;
        cin >> N;

        long long int H[N];

        for(long long int j=0;j<N;j++)
        {
            cin >> H[j];
        }

        long long int High = INT_MIN;
        long long int HighIndex;

        for(long long int j=0;j<N;j++)
        {
            if(High < H[j])
            {
                High = H[j];
                HighIndex = j;
            }
        }

        long long int SecondHigh = INT_MIN;
        long long int SecondHighIndex;

        for(long long int j=0;j<N;j++)
        {
            if(H[j] != High)
            {
                if(SecondHigh < H[j])
                {
                    SecondHigh = H[j];
                    SecondHighIndex = j;
                }
            }
        }

        for(int j=0;j<N;j++)
        {
            if(H[j] == High)
            {
                cout << HighIndex << " " << SecondHighIndex << endl;
                break;
            }
            
            if(H[j] == SecondHigh)
            {
                cout << SecondHighIndex << " " << HighIndex << endl;
                break;
            }
        }
    }

    return 0;
}