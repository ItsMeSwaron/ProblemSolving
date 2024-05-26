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

void Sweeper(Node * Head)
{
    Node * JarShatheCompareKorbo = Head;
    Node * BakiValueGula = Head;

    while(BakiValueGula->next != NULL)
    {
        if(JarShatheCompareKorbo->val == BakiValueGula->next->val)
        {
            Node * DelNode = BakiValueGula->next;
            BakiValueGula->next = BakiValueGula->next->next;
            delete DelNode;
        }
        else
        {
            BakiValueGula = BakiValueGula->next;
        }
    }
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

    int val;

    while(true)
    {   
        cin >> val;

        if(val != -1)
        {
            TailInserter(Head,val);
        }
        else
        {
            break;
        }
    }

    Node * tmp = Head;

    while(tmp != NULL)
    {
        Sweeper(tmp);
        tmp = tmp->next;
    }

    Printer(Head);

    return 0;
}