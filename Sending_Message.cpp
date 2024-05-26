#include<bits/stdc++.h>
using namespace std;
int main()
{
    char Word1[1000009], Word2[1000009];

    while(cin >> Word1 && cin >> Word2)
    {
        long long int LenWord2 = strlen(Word2);
        long long int Checker = 0;
        long long int i = 0;
        long long int j = 0;

        while(i<strlen(Word1) && j<strlen(Word2))
        {
            if(Word1[i] == Word2[j])
            {
                Checker++;
                j++;
                i = -1;
            }
            i++;
        }

        if(Checker == LenWord2)
        {
            cout << "Possible" << endl;
        }
        else
        {
            cout << "Impossible" << endl;
        }
    }
    

    return 0;
}