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

void HeadInserter(Node * &Head, int val)
{
    Node * NotunNode = new Node(val);

    if(Head == NULL)
    {
        Head = NotunNode;
        return;
    }

    NotunNode->next = Head;
    Head = NotunNode;
}

void TailInserter(Node * &Head, int val)
{
    Node * NotunNode = new Node(val);

    if(Head == NULL)
    {
        Head = NotunNode;
        return;
    }

    Node * tmp = Head;

    while(tmp->next != NULL)
    {
        tmp = tmp->next;
    }

    tmp->next = NotunNode;

}

int Size(Node * Head)
{
    Node * tmp = Head;

    int cnt = 0;

    while(tmp != NULL)
    {
        cnt++;
        tmp = tmp->next;
    }

    return cnt;
}

void Cleaner(Node * &Head, int pos)
{
    Node * tmp = Head;

    if(pos == 0)
    {
        Node * DelNode = Head;
        Head = Head->next;
        delete DelNode;
        return;
    }

    for(int i=0;i<pos-1;i++)
    {
        tmp = tmp->next;
    }

    Node * DelNode = tmp->next;
    tmp->next = tmp->next->next;
    delete DelNode;

}

void Printer(Node * Head)
{
    Node * tmp = Head;

    while(tmp != NULL)
    {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

int main()
{
    Node * Head = NULL;

    int Q;
    cin >> Q;

    for(int i=1;i<=Q;i++)
    {
        int X;
        cin >> X;

        if(X == 0)
        {
            int val;
            cin >> val;

            HeadInserter(Head,val);
        }
        else if(X == 1)
        {    
            int val;
            cin >> val;

            TailInserter(Head,val);
        }
        else if(X == 2)
        {
            int V;
            cin >> V;

            int akar = Size(Head);

            if(V < akar)
            {
                Cleaner(Head,V);
            }
        } 
        Printer(Head);
    }

    

    return 0;
}