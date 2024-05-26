#include<bits/stdc++.h>
using namespace std;
int main()
{
    int N, E;
    cin >> N >> E;

    int Mat[N][N];
    memset(Mat,0,sizeof(Mat));

    while(E--)
    {
        int a, b;
        cin >> a >> b;

        Mat[a][b] = 1;
    }

    int Q;
    cin >> Q;

    for(int i=1;i<=Q;i++)
    {
        int A, B;
        cin >> A >> B;

        if(A == B)
        {
            cout << "YES" << endl;
        }
        else if(Mat[A][B] == 1)
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