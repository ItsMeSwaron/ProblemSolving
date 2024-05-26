#include<bits/stdc++.h>
using namespace std;

class Student
{
    public:

    string nm;
    int cls;
    char s;
    int id;
    int math_marks;
    int eng_marks;

};

bool tulona(Student A, Student B)
{
    int totalA = A.math_marks + A.eng_marks;
    int totalB = B.math_marks + B.eng_marks;

    if(totalA > totalB)
    {
        return true;
    }
    else if(totalA < totalB)
    {
        return false;
    }
    else
    {
        if(A.id < B.id)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

}

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
        cin >> N[i].math_marks;
        cin >> N[i].eng_marks;
    }

    sort(N,N+n,tulona);

    for(int i=0;i<n;i++)
    {
        cout << N[i].nm << " ";
        cout << N[i].cls << " ";
        cout << N[i].s << " ";
        cout << N[i].id << " ";
        cout << N[i].math_marks << " ";
        cout << N[i].eng_marks << endl;
    }


    return 0;
}