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

//     sort(x,x+n);

//     int val, left, right, mid;
//     cin >> val;

//     left = 0;
//     right = n - 1;

//     int paisi = 0;

//     while(left <= right)
//     {
//         mid = (left + right) / 2;

//         if(pow(x[mid],2) == val)
//         {
//             paisi++;
//             break;
//         }
//         else if(pow(x[mid],2) > val)
//         {
//             right = mid - 1;
//         }
//         else
//         {
//             left = mid + 1;
//         }
//     }

//     if(paisi == 0)
//     {
//         cout << "Square root of " << val << " is: " << x[mid] << endl << "Index is : " << mid << endl;        
//     }
//     else
//     {
//         cout << "Pawa jai ni" << endl;
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

//     int left, right, mid;
//     left = 0;
//     right = n - 1;
//     int answer = 0;

//     while(left <= right)
//     {
//         mid = (left + right) / 2;

//         if(arr[mid] == 0)
//         {
//             answer = mid;
//             right = mid - 1;
//         }

//         if(arr[mid] == 1)
//         {
//             left = mid + 1;
//         }
//     }

//     cout << answer << endl;

//     return 0;
// }

// #include<bits/stdc++.h>


// // int count1s(int a[], int n){

// //     int low = 0;
// //     int high = n - 1;
// //     int key = 0;

// //     while (low<=high)
// //     {
// //         int mid = (low+high)/2;
// //         if(a[mid]==key){
// //             high=mid-1;
// //         }
// //         if(a[mid]>key){
// //             low=mid+1;
// //         }

// //     }

// //     return low;
// // }

// // int main(){

// //     int n = 5; 
// //     int a[n]={1,0,0,0,0};

// //     int numofone = count1s(a,n);

// //     // if(numofone>n){
// //     //     std::cout << numofone - 1 << "\n";
// //     // }
// //     // else{
// //         std :: cout << numofone << "\n";
// //     // }

// // }

// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int n;
//     cin >> n;

//     int a[n];

//     for(int i=0;i<n;i++)
//     {
//         cin >> a[i];
//     }

//     int left, right, mid;
//     left = 0;
//     right = n - 1;

//     while(left <= right)
//     {
//         mid = (left+right) / 2;

//         if(a[mid] == 0)
//         {
//             right = mid - 1;
//         }

//         if(a[mid] == 1)
//         {
//             left = mid + 1;
//         }
//     }

//     cout << left << endl;


//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;

    int a[n];

    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }

    sort(a,a+n);

    int left, right, mid1, mid2, key;
    cin >> key;
    left = 0;
    right = n - 1;

    while(left <= right)
    {
        mid1 = left + ((right - left) / 3);
        mid2 = right - ((right - left) / 3);

        if(a[mid1] == key || a[mid2] == key)
        {
            cout << "paisi" << endl;
            break;
        }

        if(key > a[mid1] && key < a[mid2])
        {
            left = mid1 + 1;
            right = mid2 - 1;
        }
        else if(key < a[mid1])
        {
            right = mid1 - 1;
        }
        else if(key > a[mid2])
        {
            left = mid2 + 1;
        }
    }


    return 0;
}