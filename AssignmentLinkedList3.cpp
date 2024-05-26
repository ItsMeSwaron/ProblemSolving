#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:

    int val;
    Node * next;

    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }

};

void TailInserter(Node * &Head, Node * &Tail, int val)
{
    Node * NotunNode = new Node(val);

    if(Head == NULL)
    {
        Head = NotunNode;
        Tail = NotunNode;
        return;
    }

    Tail->next = NotunNode;
    Tail = NotunNode;
}

void MirrorChecker(Node * Head1, Node * Head2)
{
    Node * tmp1 = Head1;
    Node * tmp2 = Head2;

    int signal = 0;

    while(tmp1 != NULL)
    {
        if(tmp1->val != tmp2->val)
        {
            signal++;
            break;
        }

        tmp1 = tmp1->next;
        tmp2 = tmp2->next;
    }

    if(signal == 0)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }

}

int SizeChecker(Node * Head1, Node * Head2)
{
    Node * tmp1 = Head1;
    int count1 = 0;

    Node * tmp2 = Head2;
    int count2 = 0;

    while(tmp1 != NULL)
    {
        count1++;
        tmp1 = tmp1->next;
    }

    while(tmp2 != NULL)
    {
        count2++;
        tmp2 = tmp2->next;
    }

    if(count1 == count2)
    {
        return 1;
    }
    else
    {
        return 0;
    }

}

int main()
{
    Node * Head1 = NULL;
    Node * Tail1 = NULL;
    Node * Head2 = NULL;
    Node * Tail2 = NULL;

    int val;

    while(true)
    {
        cin >> val;

        if(val != -1)
        {
            TailInserter(Head1,Tail1,val);
        }
        else
        {
            break;
        }

    }

    while(true)
    {
        cin >> val;

        if(val != -1)
        {
            TailInserter(Head2,Tail2,val);
        }
        else
        {
            break;
        }

    }

    int size = SizeChecker(Head1,Head2);

    if(size == 0)
    {
        cout << "NO" << endl;
    }
    else
    {
        MirrorChecker(Head1,Head2);
    }

    

    return 0;
}