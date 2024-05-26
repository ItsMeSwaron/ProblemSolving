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

class MaxStack
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

        int Boro = INT_MIN;

        Node * tmp = head;

        while(tmp != NULL)
        {
            if(Boro < tmp->val)
            {
                Boro = tmp->val;
            }
            tmp = tmp->next;
        }

        if(NN->val > Boro)
        {
            tail->next = NN;
            NN->prev = tail;
            tail = NN;
        }
        else
        {
            if(head->next == NULL)
            {
                NN->next = head;
                head->prev = NN;
                head = NN;
                tail = head->next;
            }
            else
            {
                NN->next = tail;
                tail->prev->next = NN;
                NN->prev = tail->prev;
                tail->prev = NN;
            }
        }
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

        int Boro = INT_MIN;

        Node * tmp = head;

        while(tmp != NULL)
        {
            if(Boro < tmp->val)
            {
                Boro = tmp->val;
            }
            tmp = tmp->next;
        }

        tmp = head;
        Node * BN;

        while(tmp != NULL)
        {
            if(Boro == tmp->val)
            {
                BN = tmp;
            }
            tmp = tmp->next;
        }

        swap(BN->val,tail->val);

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
    MaxStack stk;

    stk.push(10);
    stk.push(20);
    stk.push(15);

    stk.push(30);
    stk.push(40);
    stk.push(25);
    // stk.push(50);
    // stk.push(13);
    // stk.push(17);
    // stk.push(30);
    // stk.push(35);
    // stk.pop();
    // stk.pop();
    // stk.pop();
    // stk.pop();
    // stk.pop();
    // stk.pop();
    // stk.push(60);
    // cout << stk.pop() << endl;
    // cout << stk.peek() << endl;
    // cout << stk.size() << endl;
    stk.display();
    
    return 0;
}