// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int line;
//     cin >> line;

//     int space;
//     space = line - 2;

//     char slash1, slash2;
//     slash1 = '\\';
//     slash2 = '/';

//     int SpacePrintKorsi = 0;

//     if(line == 1)
//     {
//         cout << "X" << endl;
//     }
//     else
//     {
//         for(int i=1;i<=line;i++)
//         {
//             if(SpacePrintKorsi == 0)
//             {
//                 cout << slash1;
//             }
            
//             for(int j=1;j<=space;j++)
//             {
//                 cout << " ";
//                 SpacePrintKorsi = 1;
//             }
            
//             if(SpacePrintKorsi == 1)
//             {
//                 cout << slash2;
//                 SpacePrintKorsi = 0;
//             }

//             if(i > (line/2) + 1)
//             {
//                 space++;
//                 slash1 = '/';
//                 slash2 = '\\';
//             }
//             else if(i == (line/2) + 1)
//             {
//                 cout << "X" << endl;
//             }
//             else
//             {
//                 space--;
//             }

//             cout << endl;

//         }

//     }



//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    cin >> N;

    int row, col;

    row = N;
    col = N;

    char X[row][col] = {0};

    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            if(i == j)
            {
                X[i][j] = '\\';
            }

            if(i+j == N-1)
            {
                X[i][j] = '/';
            }

            if(i != j && i+j != N-1) 
            {
                X[i][j] = ' ';
            }
        }
    }

    int middleR = (row / 2);
    int middleC = (col / 2);

    X[middleR][middleC] = 'X'; 
    
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            cout << X[i][j];
        }
        cout << endl;
    }

    return 0;
}