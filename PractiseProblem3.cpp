#include<bits/stdc++.h>
using namespace std;

class Student
{
    public:

    char name[100];
    int roll;
    char section;
    float math_marks;
    int cls;

    Student(int roll, char section, float marks, int cls)
    {
        this->roll = roll;
        this->section = section;
        math_marks = marks;
        this->cls = cls;
    }
};


int main()
{
    Student * Fowad = new Student(10,'K',96,2);
    char tmp1[100] = "Fowad";
    strcpy(Fowad->name,tmp1);

    Student * Amirul = new Student(18,'G',98,2);
    char tmp2[100] = "Amirul";
    strcpy(Amirul->name,tmp2);
 
    
    Student * Shohan = new Student(7,'I',99,2);
    char tmp3[100] = "Shohan";
    strcpy(Shohan->name,tmp3);


    if(Fowad->math_marks > Amirul->math_marks && Fowad->math_marks > Shohan->math_marks)
    {
        cout << "Fowad";
    }

    if(Amirul->math_marks > Fowad->math_marks && Amirul->math_marks > Shohan->math_marks)
    {
        cout << "Amirul";
    }

    if(Shohan->math_marks > Amirul->math_marks && Shohan->math_marks > Fowad->math_marks)
    {
        cout << "Shohan";
    }   


    return 0;
}

     


    // if(marks1 > marks2 && marks1 > marks3)
    // {
    //     return marks1;
    // }

    // if(marks2 > marks1 && marks2 > marks3)
    // {
    //     return marks2;
    // }

    // if(marks2 > marks1 && marks2 > marks3)
    // {
    //     return marks2;
    // }

    // if(marks3 > marks1 && marks3 > marks2)
    // {
    //     return marks3;
    // }

    //     if(Fowad->math_marks > Amirul->math_marks && Fowad->math_marks > Shohan->math_marks)
    // {
    //     return Fowad->math_marks;
    // }

    // if(Amirul->math_marks > Fowad->math_marks && Amirul->math_marks > Shohan->math_marks)
    // {
    //     return Amirul->math_marks;
    // }

    // if(Shohan->math_marks > Amirul->math_marks && Shohan->math_marks > Fowad->math_marks)
    // {
    //     return Shohan->math_marks;
    // }