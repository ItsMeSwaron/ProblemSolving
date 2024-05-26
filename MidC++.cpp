#include<bits/stdc++.h>
using namespace std;

class Student
{   
    public:

    int ID;
    char name[101];
    char section;
    int TotalMarks;

}; 

int main()
{
    int T;
    cin >> T;

    for(int i=1;i<=T;i++)
    {
        Student * A = new Student();

        int id1;
        cin >> id1;
        A->ID = id1;

        char Name1[101];
        cin >> Name1;
        strcpy(A->name,Name1);

        char sec1;
        cin >> sec1;
        A->section = sec1;
        
        int TotMarks1;
        cin >> TotMarks1;
        A->TotalMarks = TotMarks1;

        Student * B = new Student();

        int id2;
        cin >> id2;
        B->ID = id2;

        char Name2[101];
        cin >> Name2;
        strcpy(B->name,Name2);

        char sec2;
        cin >> sec2;
        B->section = sec2;
        
        int TotMarks2;
        cin >> TotMarks2;
        B->TotalMarks = TotMarks2;

        Student * C = new Student();

        int id3;
        cin >> id3;
        C->ID = id3;

        char Name3[101];
        cin >> Name3;  
        strcpy(C->name,Name3);

        char sec3;
        cin >> sec3;
        C->section = sec3;
        
        int TotMarks3;
        cin >> TotMarks3;
        C->TotalMarks = TotMarks3;

        if(A->TotalMarks > B->TotalMarks && A->TotalMarks > C->TotalMarks)
        {
            cout << A->ID << " " << A->name << " " << A->section << " " << A->TotalMarks << endl;
        }

        if(B->TotalMarks > A->TotalMarks && B->TotalMarks > C->TotalMarks)
        {
            cout << B->ID << " " << B->name << " " << B->section << " " << B->TotalMarks << endl;
        }

        if(C->TotalMarks > A->TotalMarks && C->TotalMarks > B->TotalMarks)
        {
            cout << C->ID << " " << C->name << " " << C->section << " " << C->TotalMarks << endl;
        }

        if(A->TotalMarks == B->TotalMarks && A->TotalMarks > C->TotalMarks)
        {
            if(A->ID < B->ID)
            {
                cout << A->ID << " " << A->name << " " << A->section << " " << A->TotalMarks << endl;
                continue;
            }
            else
            {
                cout << B->ID << " " << B->name << " " << B->section << " " << B->TotalMarks << endl;
                continue;
            }
        }

        if(A->TotalMarks == C->TotalMarks && A->TotalMarks > B->TotalMarks)
        {
            if(A->ID < C->ID)
            {
                cout << A->ID << " " << A->name << " " << A->section << " " << A->TotalMarks << endl;
                continue;
            }
            else
            {
                cout << C->ID << " " << C->name << " " << C->section << " " << C->TotalMarks << endl;
                continue;
            }
        }        

        if(B->TotalMarks == A->TotalMarks && B->TotalMarks > C->TotalMarks)
        {
            if(B->ID < A->ID)
            {
                cout << B->ID << " " << B->name << " " << B->section << " " << B->TotalMarks << endl;
                continue;
            }
            else
            {
                cout << A->ID << " " << A->name << " " << A->section << " " << A->TotalMarks << endl;
                continue;
            }            
        }

        if(B->TotalMarks == C->TotalMarks && B->TotalMarks > A->TotalMarks)
        {
            if(B->ID < C->ID)
            {
                cout << B->ID << " " << B->name << " " << B->section << " " << B->TotalMarks << endl;
                continue;
            }
            else
            {
                cout << C->ID << " " << C->name << " " << C->section << " " << C->TotalMarks << endl;
                continue;
            }            
        }

        if(C->TotalMarks == A->TotalMarks && C->TotalMarks > B->TotalMarks)
        {
            if(C->ID < A->ID)
            {
                cout << C->ID << " " << C->name << " " << C->section << " " << C->TotalMarks << endl;
                continue;
            }
            else
            {
                cout << A->ID << " " << A->name << " " << A->section << " " << A->TotalMarks << endl;
                continue;
            }            
        }

        if(C->TotalMarks == B->TotalMarks && C->TotalMarks > A->TotalMarks)
        {
            if(C->ID < B->ID)
            {
                cout << C->ID << " " << C->name << " " << C->section << " " << C->TotalMarks << endl;
                continue;
            }
            else
            {
                cout << B->ID << " " << B->name << " " << B->section << " " << B->TotalMarks << endl;
                continue;
            }            
        }        

        if(A->TotalMarks == B->TotalMarks && A->TotalMarks == C->TotalMarks)
        {
                cout << A->ID << " " << A->name << " " << A->section << " " << A->TotalMarks << endl;
        }

        delete A;
        delete B;
        delete C;

    }

    return 0;
}