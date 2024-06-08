#include<bits/stdc++.h>
using namespace std;

class ListNode
{
    public:

    long long int val;
    ListNode * next;

    ListNode(long long int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

void TailInserter(ListNode * &head, ListNode * &tail, long long int val)
{
    ListNode * NN = new ListNode(val);

    if(head == NULL)
    {
        head = NN;
        tail = NN;
        return;
    }

    tail->next = NN;
    tail = NN;
}

void Printer(ListNode * head)
{
    ListNode * tmp = head;

    while(tmp!=NULL)
    {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

vector <long long int> v1;
vector <long long int> v2;
vector <long long int> FinalV;

void Solver1(ListNode * head)
{
    ListNode * tmp = head;

    while(tmp != NULL)
    {
        v1.push_back(tmp->val);
        tmp = tmp->next;
    }
}

void Solver2(ListNode * head)
{
    ListNode * tmp = head;

    while(tmp != NULL)
    {
        v2.push_back(tmp->val);
        tmp = tmp->next;
    }
}

void FinalSolver()
{
    reverse(v1.begin(),v1.end());
    long long int Total1 = 0;
    long long int cnt1 = 0;

    for(long long int x : v1)
    {
        cnt1++;

        if(cnt1 == v1.size())
        {
            Total1 = Total1 + x;
            break;
        }

        Total1 = (Total1 + x) * 10;
    }

    reverse(v2.begin(),v2.end());
    long long int Total2 = 0;
    long long int cnt2 = 0;
    
    for(long long int x : v2)
    {
        cnt2++;

        if(cnt2 == v2.size())
        {
            Total2 = Total2 + x;
            break;
        }

        Total2 = (Total2 + x) * 10;
    }    

    long long int FinalTotal = Total1 + Total2;

    if(FinalTotal == 0)
    {
        FinalV.push_back(0);
    }

    while(FinalTotal != 0)
    {
        FinalV.push_back(FinalTotal%10);
        FinalTotal = FinalTotal / 10;
    }

}


int main()
{
    ListNode * head1 = NULL;   
    ListNode * tail1 = NULL;

    TailInserter(head1,tail1,2);
    TailInserter(head1,tail1,4);
    TailInserter(head1,tail1,3);

    ListNode * head2 = NULL;   
    ListNode * tail2 = NULL;   

    TailInserter(head2,tail2,5);
    TailInserter(head2,tail2,6);
    TailInserter(head2,tail2,4);

    Solver1(head1);
    Solver2(head2);
    FinalSolver();

    ListNode * head = NULL;
    ListNode * tail = NULL;

    for(long long int i=0;i<FinalV.size();i++)
    {
        TailInserter(head,tail,FinalV[i]);
    }

    Printer(head);


    return 0;
}

