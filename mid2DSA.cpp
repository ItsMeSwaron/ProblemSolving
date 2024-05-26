#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:

    int val;
    Node * next;
    Node * previous;

    Node(int val)
    {
        this->val = val;
        this->next = NULL;
        this->previous = NULL;
    }
};

int sz(Node * Head)
{
    if(Head == NULL)
    {
        return 0;
    }
    
    Node * tmp = Head;
    int doirgho = 0;

    while(tmp != NULL)
    {
        doirgho++;
        tmp = tmp->next;
    }
    
    return doirgho;

}

void StraightPrinter(Node * Head)
{
    Node * tmp = Head;

    cout << "L -> ";

    while(tmp != NULL)
    {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }

    cout << endl;

}

void ReversedlyPrinter(Node * Head)
{
    Node * tmp = Head;

    cout << "R -> ";

    while(tmp->next != NULL)
    {
        tmp = tmp->next;
    }

    while(tmp != NULL)
    {   
        cout << tmp->val << " ";
        tmp = tmp->previous;
    }

    cout << endl;

}

void HeadInserter(Node * &Head, Node * &Tail, int val)
{   
    Node * NewNode = new Node(val);

    if(Head == NULL)
    {
        Head = NewNode;
        Tail = NewNode;
        return;
    }

    NewNode->next = Head;
    Head->previous = NewNode;
    Head = NewNode;

}

void PositionwiseInserter(Node * &Head, int pos, int value)
{
    Node * NewNode = new Node(value);

    if(Head == NULL)
    {
        Head = NewNode;
        return;
    }

    Node * tmp = Head;

    if(tmp->next == NULL)
    {
        Node * tmp = Head;
        NewNode->next = tmp->next;
        NewNode->previous = tmp;
        return;
    }    

    for(int i=0;i<pos-1;i++)
    {
        tmp = tmp->next;
    }

    NewNode->next = tmp->next;
    NewNode->previous = tmp;
    tmp->next->previous = NewNode;
    tmp->next = NewNode;
}

void TailInserter(Node * Head, int val)
{
    Node * NewNode = new Node(val);
    Node * tmp = Head;

    while(tmp->next != NULL)
    {
        tmp = tmp->next;
    }

    tmp->next = NewNode;
    NewNode->previous = tmp;
}

int main()
{
    Node * Head = NULL;
    Node * Tail = NULL;

    int Q;
    cin >> Q;

    for(int i=1;i<=Q;i++)
    {
        int X, V;
        cin >> X >> V;

        if(X == 0)
        {
            HeadInserter(Head,Tail,V);
            StraightPrinter(Head);
            ReversedlyPrinter(Head);
        }

        int size = sz(Head);

        if(X > size)
        {
            cout << "Invalid" << endl;
        }
        else if(X == size)
        {
            TailInserter(Head,V);
            StraightPrinter(Head);
            ReversedlyPrinter(Head);
        }
        else if(X != 0)
        {
            PositionwiseInserter(Head,X,V);
            StraightPrinter(Head);
            ReversedlyPrinter(Head);
        }

    }

    return 0;
}