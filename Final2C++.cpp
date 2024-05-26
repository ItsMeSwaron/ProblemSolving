#include<bits/stdc++.h>
using namespace std;

class Student
{
    public:

    string nm;
    int cls;
    char s;
    int id;
};

int main()
{
    int n;
    cin >> n;

    Student * N = new Student[n];

    for(int i=0;i<n;i++)
    {
        getchar();
        cin >> N[i].nm;
        cin >> N[i].cls;
        cin >> N[i].s;
        cin >> N[i].id;
    }

    int i = 0;
    int j = n-1;

    while(i<j)
    {
        swap(N[i].s,N[j].s);
        i++;
        j--;
    }

    for(int i=0;i<n;i++)
    {
        cout << N[i].nm << " ";
        cout << N[i].cls << " ";
        cout << N[i].s << " ";
        cout << N[i].id << endl;
    }

    

    return 0;
}