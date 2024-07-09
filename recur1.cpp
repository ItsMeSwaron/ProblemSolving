// #include<bits/stdc++.h>
// using namespace std;

// printing 1 to n

// void printer(int n)
// {
//     if(n == 0)
//     {
//         return;
//     }

//     cout << n << " ";
//     printer(n-1); 
// }

// int main()
// {
//     int n;
//     cin >> n;

//     printer(n);

//     return 0;
// }

// WAP summing

// #include<bits/stdc++.h>
// using namespace std;

// int summer(int n)
// {
//     if(n == 0)
//     {
//         return 1;
//     }

//     return summer(n-1) + 1;
// }

// int main()
// {
//     int n;
//     cin >> n;

//     int tmp;
//     tmp = 0;

//     int sum = 0;

//     while(tmp != n)
//     {
//         sum += summer(tmp);
//         tmp++;
//     }
    
//     cout << sum << endl;

//     return 0;
// }

// array elements printer

// #include<bits/stdc++.h>
// using namespace std;

// void arrPrinter(int * arr, int i, int n)
// {
//     if(i == n)
//     {
//         return;
//     }

//     arrPrinter(arr,i+1,n);
//     cout << arr[i] << " ";
// }

// int main()
// {
//     int n;
//     cin >> n;

//     int arr[n];

//     for(int i=0;i<n;i++)
//     {
//         cin >> arr[i];
//     }

//     arrPrinter(arr,0,n);

//     return 0;
// }

// count digits

// #include<bits/stdc++.h>
// using namespace std;

// int counter(int n)
// {
//     if(n == 0)
//     {
//         return 0;
//     }

//     n = n/10;
//     return counter(n) + 1;
// }

// int main()
// {
//     int n;
//     cin >> n;

//     cout << counter(n) << endl;

//     return 0;
// }

// fib

#include<bits/stdc++.h>
using namespace std;

int fib(int n)
{
    if(n == 0 || n == 1)
    {
        return n;
    }

    return fib(n-1) + fib(n-2);
}

int main()
{
    int n;
    cin >> n;

    int tmp = 0;

    while(tmp != n)
    {
        cout << fib(tmp) << " ";
        tmp++;
    }


    return 0;
}