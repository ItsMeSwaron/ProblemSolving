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
    Node * NN = new Node(val);

    if(head == NULL)
    {
        head = NN;
        return;
    }

    Node * tmp = head;

    while(tmp->next != NULL)
    {
        tmp = tmp->next;
    }

    tmp->next = NN;
}

void printer(Node * head)
{
    Node * tmp = head;

    while(tmp != NULL)
    {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
}

void cleaner(Node * head, )
{

}

int main()
{
    Node * head = NULL;

    TailInserter(head,10);
    TailInserter(head,20);
    TailInserter(head,30);
    TailInserter(head,40);
    TailInserter(head,50);
    printer(head);

    cout << endl;


    return 0;
}