// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     long long int T;
//     cin >> T;

//     vector <long long int> v; 

//     for(long long int i=1;i<=T;i++)
//     {
//         v.clear();
//         v.push_back(-999);

//         long long int N;
//         cin >> N;

//         long long int CopyN;
//         CopyN = N;

//         while(CopyN--)
//         {
//             v.push_back(0);
//         }

//         for(long long int k=1;k<=N;k++)
//         {
//             long long int index = 1;

//             while(index != N+1)
//             {
//                 if(index%k == 0)
//                 {
//                     if(v[index] == 0)
//                     {
//                         v[index] = 1;
//                     }
//                     else
//                     {
//                         v[index] = 0;
//                     }
//                 }
//                 index++;
//             }
//         }

//         long long int cnt = 0;

//         for(long long int x : v)
//         {
//             if(x == 1)
//             {
//                 cnt++;
//             }
//         }

//         cout << cnt << endl;
//     }


//     return 0;
// }
