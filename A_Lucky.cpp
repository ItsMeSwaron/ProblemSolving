#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin >> T;

    for(int i=1;i<=T;i++)
    {
        int tic;
        cin >> tic;

        int digits[6] = {0}, j = 5;

        int tmp;

        while(tic != 0)
        {
            tmp = tic % 10;
            digits[j] = tmp;
            tic = tic / 10;
            j--;
        }

        int FirstHalf = 0, SecondHalf = 0;

        FirstHalf = digits[0] + digits[1] + digits[2];
        SecondHalf = digits[3] + digits[4] + digits[5];
 
        if(FirstHalf == SecondHalf)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }


    }


    return 0;
}
