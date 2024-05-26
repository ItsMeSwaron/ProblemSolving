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

class AmarStack
{
    public:

    void push(int val)
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

    int pop()
    {
        if(head == NULL)
        {
            cout << "Stack underflow" << endl;
            return -1;
        }

        if(head->next == NULL)
        {
            int x;
            x = tail->val;
            Node * DN = tail;
            tail = NULL;
            head = NULL;            
            delete DN; 
            return x;           
        }
    
        int x;
        x = tail->val;

        Node * DN = tail;
        tail = tail->prev;
        tail->next = NULL;
        delete DN;
        return x;
    }

    int peek()
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
    AmarStack stk;

    stk.push(10);
    stk.push(20);
    stk.push(30);
    stk.push(40);
    stk.push(50);
    cout << stk.pop() << endl;
    cout << stk.peek() << endl;
    cout << stk.size() << endl;
    stk.display();
    
    return 0;
}