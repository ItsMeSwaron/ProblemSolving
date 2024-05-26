#include<bits/stdc++.h>
using namespace std;


class Node
{
    public:

    int val;
    Node * next;
    Node * prev;

    Node(int val)
    {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

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

void TailInserter(Node * &head, Node * &tail, int val)
{
    Node * NewNode = new Node(val);

    if(head == NULL)
    {
        head = NewNode;
        tail = NewNode;
        return;
    }

    tail->next = NewNode;
    NewNode->prev = tail;
    tail = NewNode;
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

void deleter(Node * &tail)
{
    tail = tail->prev;
    delete tail->next;
    tail->next = NULL;
}

int main()
{
    Node * head = NULL;
    Node * tail = NULL;

    int count = 0;

    TailInserter(head,tail,10);
    count++;
    TailInserter(head,tail,20);
    count++;
    TailInserter(head,tail,30);
    count++;

    cout << count << endl;

    // deleter(tail);

    // Printer(head);

    return 0;
}