#include<bits/stdc++.h>
using namespace std;
int main()
{
    list <int> A(5);

    A.push_front(10);
    A.push_front(20);
    A.push_front(30);
    A.push_front(40);
    A.push_front(50);

    for(int x : A)
    {
        cout << x << " ";
    }

    return 0;
}