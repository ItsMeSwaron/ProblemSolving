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
    if(A.eng_marks > B.eng_marks)
    {
        return true;
    }
    else if(A.eng_marks < B.eng_marks)
    {
        return false;
    }
    else
    {
        if(A.math_marks > B.math_marks)
        {
            return true;
        }
        else if(A.math_marks < B.math_marks)
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