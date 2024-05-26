#include<bits/stdc++.h>
using namespace std;

class Student
{
    public:

    string name;
    int roll;
    int marks;
};

// bool cmp(Student A, Student B)
// {
//     if(A.marks > B.marks)
//     {
//         return true;
//     }
//     else if(A.marks < B.marks)
//     {
//         return false;
//     }

//     if(A.marks == B.marks)
//     {
//         if(A.roll < B.roll)
//         {
//             return true;
//         }
//         else
//         {
//             return false;
//         }
//     }
// }

int main()
{
    int N;
    cin >> N;

    Student * stu = new Student[N];

    for(int i=0;i<N;i++)
    {
        getchar();
        cin >> stu[i].name;
        cin >> stu[i].roll;
        cin >> stu[i].marks;
    }

    for(int i=N-1;i>=0;i--)
    {
        cout << stu[i].name << " ";
        cout << stu[i].roll << " ";
        cout << stu[i].marks << endl;
    }


    return 0;
}