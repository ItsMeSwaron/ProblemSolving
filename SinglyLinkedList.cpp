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

void TailInserter(Node * &Head, int v)
{
    Node * newnode = new Node(v);

    if(Head == NULL)
    {
        Head = newnode;
        return;
    }

    Node * tmp = Head;    

    while(tmp->next != NULL)
    {
        tmp = tmp->next;
    }

    tmp->next = newnode;

}

void Printer(Node * Head)
{
    Node * tmp = Head;

    cout << "Your linked list: ";
    while(tmp != NULL)
    {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout << endl << endl;
}

void SpecificInserter(Node * Head, int pos, int val)
{
    Node * newnode = new Node(val);

    Node * tmp = Head;

    for(int i=1;i<pos-1;i++)
    {
        tmp = tmp->next;
    }

    newnode->next = tmp->next;
    tmp->next = newnode;

    cout << endl << endl;

}

void HeadInserter(Node * &Head, int val)
{
    Node * headnode = new Node(val);
    headnode->next = Head;
    Head = headnode;
    cout << endl << endl;
}

void Deleter(Node * &Head, int pos)
{
    Node * tmp = Head;

    if(pos == 1)
    {
        Node * newhead = Head;
        Head = Head->next;
        delete newhead;
    }
    else
    {
        for(int i=1;i<pos-1;i++)
        {
            tmp = tmp->next;
        }
        
        Node * DeletingNode = tmp->next;
        tmp->next = tmp->next->next;
        delete DeletingNode;
        cout << endl << endl;
    }

}

void Len(Node * Head)
{
    Node * tmp = Head;
    int sz = 0;

    while(tmp != NULL)
    {
        sz++;
        tmp = tmp->next;
    }

    cout << endl << sz << endl << endl;
}

void src(Node * Head, int SearchVal)
{
    Node * tmp = Head;

    bool paisi = false;

    while(tmp != NULL)
    {
        tmp = tmp->next;

        if(tmp != NULL)
        {
            if(tmp->val == SearchVal)
            {
                cout << "Found" << endl;
                paisi = true;
                break;
            }
        }
    }

    if(paisi == false)
    {
        cout << "Not Found" << endl;
    }
}

void Sorter(Node * Head)
{
    for(Node * i = Head; i->next != NULL; i = i->next)
    {
        for(Node * j = i->next; j != NULL; j = j->next)
        {
            if(i->val < j->val)
            {
                swap(i->val,j->val);
            }
        }
    }
}

int main()
{
    Node * Head = NULL;

    while(true)
    {
        cout << "Please select an option" << endl << endl;
        cout << "1. Insert at the tail" << endl;
        cout << "2. Print Linked List" << endl;
        cout << "3. Insert at a specific position" << endl;
        cout << "4. Insert at the head" << endl;
        cout << "5. Delete specific node" << endl;
        cout << "6. Keep inserting!" << endl;
        cout << "7. Length" << endl;
        cout << "8. Search" << endl;
        cout << "9. Sort" << endl;
        cout << "10. Terminate" << endl;

        int opt;
        cin >> opt;

        if(opt == 1)
        {
            cout << "give the value you want to enter: ";
            int v;
            cin >> v;
            TailInserter(Head,v);
        }
        else if(opt == 2)
        {
            Printer(Head);
        }
        else if(opt == 3)
        {
            cout << "Enter the position and value" << endl;
            int posi, valu;
            cin >> posi >> valu;

            if(posi == 0)
            {
                HeadInserter(Head,valu);
            }
            else
            {
                SpecificInserter(Head,posi,valu);
            }
            
        }
        else if(opt == 4)
        {
            cout << "Enter the value of the head" << endl;
            int headVal;
            cin >> headVal;

            HeadInserter(Head,headVal);
        }
        else if(opt == 5)
        {
            cout << "Enter position to delete" << endl;
            int pos;
            cin >> pos;
            Deleter(Head,pos);
        }
        else if(opt == 6)
        {
            cout << "Keep insert your values!" << endl;
            int val;

            while(val != -1)
            {
                cin >> val;
                if(val != -1)
                {
                    TailInserter(Head,val);
                }
                
            }
        }
        else if(opt == 7)
        {
            Len(Head);
        }
        else if(opt == 8)
        {
            int v;
            cin >> v;
            src(Head,v);
        }
        else if(opt == 9)
        {
            Sorter(Head);
        }
        else if(opt == 10)
        {
            break;
        }
    }
    
    return 0;
}