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

Node* doubleIt(Node* head) 
{
    vector <int> v;

    Node * tmp = head;

    while(tmp != NULL)
    {
        v.push_back(tmp->val);
        tmp = tmp->next;
    }    

    int vl = 0;

    while(!v.empty())
    {
        vl = vl * 10 + v[0];
        v.erase(v.begin());
    }

    vl = vl * 2;

    vector <int> vec;

    while(vl != 0)
    {
        int t = vl % 10;
        vec.push_back(t);
        vl = vl / 10;
    }

    reverse(vec.begin(),vec.end());

    Node * Head = new Node(vec[0]);
    Node * Tmp = Head;

    for(int i=1;i<vec.size();i++)
    {
        Node * N = new Node(vec[i]);
        Tmp->next = N;
        Tmp = Tmp->next;
    }

    return Head;
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

    TailInserter(head,9);
    TailInserter(head,9);
    TailInserter(head,9);

    Printer(doubleIt(head));

    return 0;
}
