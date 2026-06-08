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

void tailInserter(Node * &head, int v)
{
    Node * NN = new Node(v);

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

int main()
{
    Node * head = NULL;

    tailInserter(head,5);
    tailInserter(head,10);
    tailInserter(head,15);
    tailInserter(head,20);
    tailInserter(head,25);

    printer(head);

    return 0;
}    

