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
    Node * newnode = new Node(val);

    if(Head == NULL)
    {
        Head = newnode;
        Tail = newnode;
        return;
    }

    Tail->next = newnode;
    Tail = newnode;
    
}

// void Printer(Node * Head)
// {
//     Node * tmp = Head;

//     while(tmp != NULL)
//     {
//         cout << tmp->val << " ";
//         tmp = tmp->next;
//     }

// }

int MaxFinder(Node * Head)
{
    int max = INT_MIN;

    for(Node * i=Head;i!=NULL;i=i->next)
    {
        if(max < i->val)
        {
            max = i->val;
        }
    }

    return max;

}

int MinFinder(Node * Head)
{
    int min = INT_MAX;

    for(Node * i=Head;i!=NULL;i=i->next)
    {
        if(min > i->val)
        {
            min = i->val;
        }
    }

    return min;

}

int main()
{
    Node * Head = NULL;
    Node * Tail = NULL;

    int val;

    while(val != -1)
    {
        cin >> val;
        if(val != -1)
        {
            TailInserter(Head,Tail,val);
        }
    }  

    // Printer(Head);

    int Maximum = MaxFinder(Head);
    int Minimum = MinFinder(Head);

    cout << Maximum - Minimum << endl;

    return 0;
}