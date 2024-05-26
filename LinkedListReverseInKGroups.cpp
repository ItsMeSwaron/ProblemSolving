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
    tail = NewNode;
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

int sz(Node * head)
{
    int saiz = 0;
    Node * tmp = head;

    while(tmp != NULL)
    {
        saiz++;
        tmp = tmp->next;
    }
    return saiz;
}

Node * FinalHead = NULL;
Node * FinalTail = NULL;
vector <int> v;

void VectorToLinkedList(int k)
{
    for(int i=0;i<k;i++)
    {
        TailInserter(FinalHead,FinalTail,v[i]);
    }
    v.clear();
}

void reverser(int k)
{
    reverse(v.begin(),v.begin()+k);
    VectorToLinkedList(k);
}

void Solver(Node * head, int k)
{
    int i = 0;
    int time = sz(head) / k;
    int count = 0;
    Node * tmp = head;

    while(time--)
    {
        while(i<k)
        {
            v.push_back(tmp->val);
            tmp = tmp->next;
            i++;
        }

        reverser(k);
        i = 0;
        count = count + k;
    }

    if(count < sz(head))
    {
        int T = sz(head) - count;
        Node * temp = head;
        int i = 0;

        while(T--)
        {
            while(i<count-1)
            {
                temp = temp->next;
                i++;
            }
            FinalTail->next = temp->next;
            i = count;
        }
    }
}

int main()
{
    Node * head = NULL;
    Node * tail = NULL;

    while(true)
    {
        int val;
        cin >> val;

        if(val != -1)
        {
            TailInserter(head,tail,val);
        }
        else
        {
            break;
        }
    }

    int k;
    cin >> k;

    Solver(head,k);

    printer(FinalHead);

    return 0;
}