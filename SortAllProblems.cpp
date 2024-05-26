// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int n;
//     cin >> n;
//     int arr[n];
//     for(int i=0;i<n;i++)
//     {
//         cin >> arr[i];
//     }

//     sort(arr,arr+n);


//     int i=0;
//     while(true)
//     {
//         if(i >= n-1)
//         {
//             break;
//         }
//         swap(arr[i],arr[i+1]);
//         i = i+2;
//     }

//     for(int i=0;i<n;i++)
//     {
//         cout << arr[i] << " ";
//     }

//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     char x[100];
    
//     for(int i=0;i<6;i++)
//     {
//         cin >> x[i];
//     }

//     for(int i=0;i<6-1;i++)
//     {
//         for(int j=0;j<6-1-i;j++)
//         {
//             if(x[j] > x[j+1])
//             {
//                 swap(x[j],x[j+1]);
//             }
//         }
//     }

//     for(int i=0;i<6;i++)
//     {
//         cout << x[i];
//     }    

//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int n;
//     cin >> n;
//     int x[n];

//     for(int i=0;i<n;i++)
//     {
//         cin >> x[i];
//     }

//     vector <int> v1;
//     vector <int> v2;
//     vector <int> answer;

//     if(n%2 == 0)
//     {
//         // for even
//         for(int i=0;i<n-1;i=i+2)
//         {
//            v1.push_back(x[i]);
//         }
//         // for odd
//         for(int i=1;i<n;i=i+2)
//         {
//             v2.push_back(x[i]);
//         }
//     }
//     else
//     {
//         // for even
//         for(int i=0;i<n;i=i+2)
//         {
//             v1.push_back(x[i]);
//         }
//         // for odd
//         for(int i=1;i<n-1;i=i+2)
//         {
//             v2.push_back(x[i]);
//         }        
//     }

//     // sort(v1.begin(),v1.end());

//     for(int i=0;i<n-1;i++)
//     {
//         for(int j=i+1;j<n;j++)
//         {
//             if(v1[i]>v1[j])
//             {
//                 swap(v1[i],v1[j]);
//             }
//         }
//     }

//     for(int i=0;i<n-1;i++)
//     {
//         for(int j=i+1;j<n;j++)
//         {
//             if(v2[i]<v2[j])
//             {
//                 swap(v2[i],v2[j]);
//             }
//         }
//     }

//     // sort(v2.begin(),v2.end(),greater<int>());

//     for(int x : v1)
//     {
//         answer.push_back(x);
//     }

//     for(int x : v2)
//     {
//         answer.push_back(x);
//     }

//     for(int x : answer)
//     {
//         cout << x << " ";
//     }

//     cout << endl;

//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int n, m;
//     cin >> n >> m;
//     int x[n][m];

//     for(int i=0;i<n;i++)
//     {
//         for(int j=0;j<m;j++)
//         {
//             cin >> x[i][j];
//         }
//     }

//     vector <int> v;

//     int i=0;
//     int j=0;
//     while(true)
//     {
//         v.push_back(x[i][j]);
//         j++;
//         if(j != m)
//         {
//             continue;
//         }

//         j = 0;
//         i++;

//         sort(v.begin(),v.end());

//         for(int x : v)
//         {
//             cout << x << " ";
//         }

//         cout << endl;

//         v.clear();

//         if(i==m)
//         {
//             break;
//         }
//     }

//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int n;
//     cin >> n;

//     int arr[n];

//     for(int i=0;i<n;i++)
//     {
//         cin >> arr[i];
//     }

//     for(int i=0;i<n-1;i++)
//     {
//         for(int j=0;j<n-1-i;j++)
//         {
//             if(arr[j] > arr[j+1])
//             {
//                 swap(arr[j],arr[j+1]);
//             }
//         }
//     }

//     if(n%2 != 0)
//     {
//         int i = 0;
//         while(i != n-1)
//         {
//             swap(arr[i],arr[i+1]);
//             i = i + 2;
//         }
//     }
//     else
//     {
//         int i = 0;
//         while(i != n)
//         {
//             swap(arr[i],arr[i+1]);
//             i = i + 2;
//         }
//     }

//     for(int i=0;i<n;i++)
//     {
//         cout << arr[i] << " ";
//     }

//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int n;
//     cin >> n;

//     int arr[n];

//     for(int i=0;i<n;i++)
//     {
//         cin >> arr[i];
//     }

//     sort(arr,arr+n);

//     int low, high;
//     cin >> low >> high;
//     vector <int> v;
//     int signal = 0;

//     for(int i=low;i<=high;i++)
//     {
//         for(int j=0;j<n;j++)
//         {
//             if(arr[j] == i)
//             {
//                 signal++;
//             }
//         }
//         if(signal == 0)
//         {
//             v.push_back(i);
//             signal = 0;
//         }
//         signal = 0;
//     }

//     for(int i=0;i<n;i++)
//     {
//         for(int j=i+1;j<n-1;j++)
//         {
//             if(v[i] > v[j])
//             {
//                 swap(v[i],v[j]);
//             }
//         }
//     }

//     for(int x : v)
//     {
//         cout << x << " ";
//     }

//     return 0;
// }

// #include <iostream>
// using namespace std;

// int main() {
//     int n;
//     cin >> n;
//     int arr[n];
//     for (int i = 0; i < n; ++i) {
//         cin >> arr[i];
//     }
//     int low, high;
//     cin >> low >> high;

//     for (int i = low; i <= high; ++i){ 
//         bool flg = false;
//         for (int j = 0; j < n; ++j){
//             if (arr[j] == i) {
//                 flg = true;
//                 break;
//             }
//         }
//         if (flg == false) {
//             cout << i << " ";
//         }
//     }

//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int row;
//     int col;
//     cin >> row >> col;

//     int mat[row][col];

//     for(int i=0;i<row;i++)
//     {
//         for(int j=0;j<col;j++)
//         {
//             cin >> mat[i][j];
//         }
//     }

//     vector <int> v;

//     for(int i=0;i<row;i++)
//     {
//         for(int j=0;j<col;j++)
//         {
//             v.push_back(mat[i][j]);
//         }
//     }

//     int n = row * col;

//     for(int i=0;i<n-1;i++)
//     {
//         for(int j=i+1;j<n;j++)
//         {
//             if(v[i] > v[j])
//             {
//                 swap(v[i],v[j]);
//             }
//         }
//     }    

//     int i = 0;
//     int j = 0;

//     for(int x : v)
//     {
//         mat[i][j] = x;
//         j++;
//         if(j == row)
//         {
//             i++;
//             j = 0;
//         }
//     }

//     for(int i=0;i<row;i++)
//     {
//         for(int j=0;j<col;j++)
//         {
//             cout << mat[i][j] << " ";
//         }
//         cout << endl;
//     }
   
//     return 0;
// // }

// #include<bits/stdc++.h>


// int count1s(int a[], int n){

//     int low = 0;
//     int high = n;
//     int key = 0;

//     while (low<=high)
//     {
//         int mid = (low+high)/2;
//         if(a[mid]==key){
//             high=mid-1;
//         }
//         if(a[mid]>key){
//             low=mid+1;
//         }

//     }
    
//     return low;
// }

// int main(){

//     int n = 7;
//     int a[n]={1,1,1,1,1,1,1};

//     int numofone = count1s(a,n);

//     if(numofone>n){
//         std::cout << numofone - 1 << "\n";
//     }
//     else{
//         std :: cout << numofone << "\n";
//     }

// }

// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int n;
//     cin >> n;

//     int arr[n];

//     for(int i=0;i<n;i++)
//     {
//         cin >> arr[i];
//     }

//     int frq[n] = {0};

//     for(int i=0;i<n;i++)
//     {
//         frq[arr[i]]++;
//     }

//     for(int i=0;i<n;i++)
//     {
//         if(frq[i] == 1)
//         {
//             cout << i << endl;
//         }
//     }

//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int x;
    cin >> x;

    int a[x];

    for(int i=0;i<x;i++)
    {
        cin >> a[i];
    }

    int frq[1015] = {0};

    for(int i=0;i<x;i++)
    {
        frq[a[i]]++;
    }    

    vector <pair<int,int>> v;

    for(int i=0;i<=1010;i++)
    {
        if(frq[i] > 0)
        {
            v.push_back({i,frq[i]});
        }
    }

    int len = 0;

    for(pair<int,int> x : v)
    {
        len++;
    }    

    for(int i=0;i<len-1;i++)
    {
        for(int j=i+1;j<len;j++)
        {
            if(v[i].second < v[j].second)
            {
                swap(v[i],v[j]);
            }
        }
    }

    for(pair<int,int> x : v)
    {
        while(x.second--)
        {
            cout << x.first << " ";
        }
    }

    return 0;
}