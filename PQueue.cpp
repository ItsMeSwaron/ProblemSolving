#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:

    char val;
    Node * next;
    Node * prev;

    Node(char val)
    {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

Node * head = NULL;
Node * tail = NULL;

class MyQueue
{
    public:

    void push(char val)
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

    void pop()
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

        int checkerVal = head->val;

        Node * tmp = head->next;

        while(tmp != NULL)
        {
            if(checkerVal < tmp->val)
            {
                checkerVal = tmp->val;
            }
            tmp = tmp->next;
        }

        char X = (char) checkerVal;

        tmp = head;

        while(tmp->next != NULL)
        {
            if(X == tmp->val)
            {
                break;
            }
            tmp = tmp->next;
        }

        Node * DN = tmp;
        if(tmp->prev != NULL)
        {
            tmp->prev->next = tmp->next;
        }
        else
        {
            head = tmp->next;
        }
        if(tmp->next != NULL)
        {
            tmp->next->prev = tmp->prev;
        }
        delete DN;
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
    MyQueue q;

    q.push('T');
    q.push('M');
    q.push('I');
    q.push('X');
    q.push('A');
    q.pop();
    q.pop();
    // q.pop();
    // q.pop();
    // q.pop();

    q.display();
    
    return 0;
}