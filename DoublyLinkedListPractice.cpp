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

void StraightlyPrinter(Node * Head)
{
    Node * tmp = Head;

    cout << "Straight Doubly Linked List: ";

    while(tmp != NULL)
    {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }

    cout << endl << endl;

}

void ReversedlyPrinter(Node * Head)
{
    Node * tmp = Head;

    cout << "Reversed Doubly Linked List: ";

    while(tmp->next != NULL)
    {
        tmp = tmp->next;
    }

    while(tmp != NULL)
    {
        cout << tmp->val << " ";
        tmp = tmp->previous;
    }

    cout << endl << endl;

}

void TailInserter(Node * &Head, Node * &Tail, int val)
{
    Node * NotunNode = new Node(val);

    if(Head == NULL)
    {
        Head = NotunNode;
        Tail = NotunNode;
        return;
    }

    Node * tmp = Head;

    while(tmp->next != NULL)
    {
        tmp = tmp->next;
    }

    tmp->next = NotunNode;
    NotunNode->previous = tmp;
    Tail = NotunNode;

}

void HeadInserter(Node * &Head, Node * &Tail, int val)
{   
    Node * NotunNode = new Node(val);

    if(Head == NULL)
    {
        Head = NotunNode;
        Tail = NotunNode;
        return;
    }

    NotunNode->next = Head;
    Head->previous = NotunNode;
    Head = NotunNode;

}

void Reverser(Node * Head, Node * Tail)
{
    Node * Matha = Head;    
    Node * Lej = Tail;    

    while(Matha != Lej && Matha->next != Lej)
    {
        swap(Matha->val,Lej->val);
        Matha = Matha->next;
        Lej = Lej->previous;
    }

    swap(Matha->val,Lej->val);

}

void PalindromeChecker(Node * Head, Node * Tail)
{
    Node * tmpHead = Head;
    Node * tmpTail = Tail;

    int signal = 0;

    while(tmpHead != tmpTail && tmpHead->next != tmpTail)
    {
        if(tmpHead->val != tmpTail->val)
        {
            signal++;
            break;   
        }
        tmpHead = tmpHead->next;
        tmpTail = tmpTail->previous;
    }

    if(tmpHead->val != tmpTail->val)
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

void Sorter(Node * Head)
{
    for(Node * i=Head;i->next!=NULL;i=i->next)
    {
        for(Node * j=i->next;j!=NULL;j=j->next)
        {
            if(i->val > j->val)
            {
                swap(i->val,j->val);
            }
        }
    }

    cout << endl;

}

int main()
{
    Node * Head = NULL;   
    Node * Tail = NULL;   

    while(true)
    {
        cout << "1. Terminate " << endl; 
        cout << "2. insert at tail " << endl; 
        cout << "3. insert at head " << endl; 
        cout << "4. Straightly Print doubly linked list " << endl; 
        cout << "5. Reversedly Print doubly linked list " << endl; 
        cout << "6. Reverse linked list " << endl; 
        cout << "7. Palindrome Checker of the linked list " << endl; 
        cout << "8. Sort the linked list " << endl; 
        
        int Option;
        cin >> Option;

        if(Option == 1)
        {
            break;
        }
        else if(Option == 2)
        {
            cout << "value to insert at tail: ";
            int val;
            cin >> val;
            TailInserter(Head,Tail,val);
        }
        else if(Option == 3)
        {
            cout << "value to insert at head: ";
            int val;
            cin >> val;            
            HeadInserter(Head,Tail,val);
        }
        else if(Option == 4)
        {
            StraightlyPrinter(Head);
        }
        else if(Option == 5)
        {
            ReversedlyPrinter(Head);
        }
        else if(Option == 6)
        {
            Reverser(Head,Tail);
        }
        else if(Option == 7)
        {
            PalindromeChecker(Head,Tail);
        }
        else if(Option == 8)
        {
            Sorter(Head);
        }
    }


    return 0;
}