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
    NewNode->prev = tmp;
}

void TailInserter2(Node * &head, Node * &tail, int val)
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

void HeadInserter(Node * &head, int val)
{
    Node * NewNode = new Node(val);

    if(head == NULL)
    {
        head = NewNode;
        return;
    }

    NewNode->next = head;
    head->prev = NewNode;
    head = NewNode;
}

void InsideInserter(Node * head, int val, int pos)
{
    Node * NewNode = new Node(val);

    Node * tmp = head;

    for(int i=1;i<pos;i++)
    {
        tmp = tmp->next;
    }

    NewNode->next = tmp->next;
    NewNode->prev = tmp;
    tmp->next->prev = NewNode;
    tmp->next = NewNode;

}

void Printer(Node * head)
{
    if(head == NULL)
    {
        cout << "Ajk vaat nai" << endl;
        return;
    }

    Node * tmp = head;

    while(tmp != NULL)
    {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }

}

void HeadDeleter(Node * &head)
{
    if(head == NULL)
    {
        cout << "Bab bye" << endl;
        return;
    }

    Node * DelNode = head;
    head = head->next;
    delete DelNode;

}

void PachaCutter(Node * &tail)
{
    if(tail == NULL)
    {
        cout << "Pachai to nai" << endl;
        return;
    }

    Node * PachaGayeb = tail;
    tail = tail->prev;
    tail->next = NULL;
    delete PachaGayeb;

}

void BodyCutter(Node * &head, int pos)
{
    if(head == NULL)
    {
        cout << "jao ga" << endl;
        return;
    }

    Node * tmp = head;

    for(int i=1;i<pos-1;i++)
    {
        tmp = tmp->next;
    }

    Node * DelNode = tmp->next;

    if(tmp->next->next != NULL)
    {
        tmp->next = tmp->next->next;
        tmp->next->next->prev = tmp;
        delete DelNode;
    }
    else
    {
        tmp->next = NULL;
        delete DelNode;
    }
}

void UltaPrinter(Node * head)
{
    if(head == NULL)
    {
        return;
    }

    Node * tmp = head;

    while(tmp->next != NULL)
    {
        tmp = tmp->next;
    }

    while(tmp != NULL)
    {
        cout << tmp->val << " ";
        tmp = tmp->prev;
    }

}

void UltaPrintButWithStyle(Node * head)
{
    if(head == NULL)
    {
        return;
    }

    UltaPrintButWithStyle(head->next);
    cout << head->val << " ";

}

int sz(Node * head)
{
    if(head == NULL)
    {
        return 0;
    }

    int akar = 0;

    Node * tmp = head;

    while(tmp != NULL)
    {
        akar++;
        tmp = tmp->next;
    }

    return akar;

}

void Sorter(Node * head)
{
    if(head == NULL)
    {
        return;
    }

    for(Node * i=head;i->next!=NULL;i=i->next)
    {
        for(Node * j=i->next;j!=NULL;j=j->next)
        {
            if(i->val > j->val)
            {
                swap(i->val,j->val);
            }
        }
    }

}

void PalindromeFinder(Node * head, Node * tail, int sz)
{
    Node * tmp1 = head;
    Node * tmp2 = tail;

    int signal = 0;


    while(tmp1 != tmp2 && tmp1->next != tmp2)
    {
        if(tmp1->val != tmp2->val)
        {
            signal++;
            break;
        }

        tmp1 = tmp1->next;
        tmp2 = tmp2->prev;
    }

    if(tmp1->val != tmp2->val)
    {
        signal++;
    }


    if(signal == 0)
    {
        cout << "Palindrome" << endl;
    }
    else
    {
        cout << "Not Palindrome" << endl;
    }
}

int main()
{
    Node * head = NULL;
    Node * tail = NULL;

    TailInserter2(head,tail,10);
    TailInserter2(head,tail,20);
    TailInserter2(head,tail,30);
    TailInserter2(head,tail,40);
    TailInserter2(head,tail,30);
    TailInserter2(head,tail,20);
    TailInserter2(head,tail,10);

    Printer(head);
    cout << endl;

    // HeadInserter(head,100);
    // HeadInserter(head,200);
    // HeadInserter(head,300);

    // Printer(head);
    // cout << endl;

    // InsideInserter(head,999,4);

    // Printer(head);
    // cout << endl;

    // cout << tail->val << endl;
    // PachaCutter(tail);
    // Printer(head);
    // cout << endl;

    // BodyCutter(head,9);
    // Printer(head);
    // cout << endl;

    // MasterCutter(head,1);
    // Printer(head);
    // cout << endl;

    // MasterCutter(head,1);
    // Printer(head);
    // cout << endl;

    // UltaPrinter(head);
    // cout << endl;

    // UltaPrintButWithStyle(head);
    // cout << endl;

    int akriti = sz(head);
    
    // Sorter(head);
    // Printer(head);
    // cout << endl;

    PalindromeFinder(head,tail,akriti);


    return 0;
}