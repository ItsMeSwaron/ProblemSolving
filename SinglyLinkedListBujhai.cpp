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

void TailInserter(Node * &head, int val)
{
    Node * NewNode = new Node(val);

    if(head == NULL)
    {
        head = NewNode;
        return;
    }

    Node * tmp = head;

    while(tmp->next != NULL)
    {
        tmp = tmp->next;
    }

    tmp->next = NewNode;
}

void HeadInserter(Node * &head, int val)
{
    Node * NewNode = new Node(val);

    if(head == NULL)
    {
        head = NewNode;
        return;
    }

    NewNode->next = head;
    head = NewNode;
}

void InsideInserter(Node * head, int val, int pos)
{
    Node * NewNode = new Node(val);
    Node * tmp = head;

    for(int i=1;i<2;i++)
    {
        tmp = tmp->next;
    }    

    NewNode->next = tmp->next;
    tmp->next = NewNode;

}

void Printer(Node * head)
{
    Node * tmp = head;

    while(tmp != NULL)
    {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }

}

int main()
{
    Node * head = NULL;

    TailInserter(head,10);
    TailInserter(head,20);
    TailInserter(head,30);
    TailInserter(head,40);
    TailInserter(head,50);

    Printer(head);

    cout << endl;

    HeadInserter(head,5);

    Printer(head);

    cout << "\n";

    InsideInserter(head,100,2);

    Printer(head);

    return 0;
}