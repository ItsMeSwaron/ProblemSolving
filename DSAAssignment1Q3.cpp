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

Node * head = NULL;
Node * tail = NULL;

class Deque
{
    public:

    void insertFront(int val)
    {
        Node * NN = new Node(val);

        if(head == NULL)
        {
            head = NN;
            tail = NN;
            return;
        }

        NN->next = head;
        head->prev = NN;
        head = NN;
    }

    void insertRear(int val)
    {
        Node * NN = new Node(val);

        if(head == NULL)
        {
            head = NN;
            tail = NN;
            return;
        }

        tail->next = NN;
        NN->prev = tail;
        tail = NN;
    }

    void deleteFront()
    {
        if(head == NULL)
        {
            cout << "Deque underflow" << endl;
            return;
        }

        if(head->next == NULL)
        {
            Node * DN = head;
            tail = NULL;
            head = NULL;            
            delete DN;          
        }
    
        Node * DN = head;
        head = head->next;
        head->prev = NULL;
        delete DN;
    }

    void deleteRear()
    {
        if(head == NULL)
        {
            cout << "Deque underflow" << endl;
            return;
        }

        if(head->next == NULL)
        {
            Node * DN = tail;
            tail = NULL;
            head = NULL;            
            delete DN;           
        }

        Node * DN = tail;
        tail = tail->prev;
        tail->next = NULL;
        delete DN;
    }

    int getFront()
    {
        if(head != NULL)
        {
            return head->val;
        }
        else
        {
            return -1;
        }
    }

    int getRear()
    {
        if(tail != NULL)
        {
            return tail->val;
        }
        else
        {
            return -1;
        }
    }

    void display()
    {
        Node * tmp = head;

        while(tmp != NULL)
        {
            cout << tmp->val << " ";
            tmp = tmp->next;
        }

        cout << endl;
    }

    int size()
    {
        int count = 0;

        Node * tmp = head;
        
        while(tmp != NULL)
        {
            count++;
            tmp = tmp->next;
        }
        return count;
    }
};

int main()
{
    Deque deq;

    deq.insertFront(10);
    deq.insertFront(20);
    deq.insertFront(30);
    deq.insertRear(40);
    deq.insertRear(50);
    deq.insertRear(60);

    // cout << deq.size() << endl;
    // cout << deq.getFront() << endl;
    // cout << deq.getRear() << endl;

    deq.deleteFront();
    deq.deleteRear();
    deq.display();
    
    return 0;
}