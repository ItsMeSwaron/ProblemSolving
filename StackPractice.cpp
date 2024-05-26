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

class MyStack
{
    public:

    Node * Head = NULL;
    Node * Tail = NULL;

    int size = 0;

    void push(int val)
    {
        size++;

        Node * NewNode = new Node(val);

        if(Head == NULL)
        {
            Head = NewNode;
            Tail = NewNode;
            return;
        }

        Tail->next = NewNode;
        NewNode->previous = Tail;
        Tail = NewNode;
    }

    void pop()
    {
        size--;

        Node * DelNode = Tail;
        Tail = Tail->previous;
        if(Tail == NULL)
        {
            Head = NULL;
            return;
        }
        Tail->next = NULL;
        delete DelNode;
    }

    void printer()
    {
        Node * tmp = Head;

        while(tmp != NULL)
        {
            cout << tmp->val << " ";
            tmp = tmp->next;
        }
    }

    int top()
    {
        return Tail->val;
    }

    int akar()
    {
        return size;
    }

    bool empty()
    {
        if(size == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

};

int main()
{
    MyStack M;
    MyStack N;

    int x1;
    cout << "how many value to enter the stack 1: ";
    cin >> x1;

    for(int i=1;i<=x1;i++)
    {
        int valuz;
        cin >> valuz;
        M.push(valuz);
    }

    int x2;
    cout << "how many value to enter the stack 2: ";
    cin >> x2;

    for(int i=1;i<=x2;i++)
    {
        int valuz;
        cin >> valuz;
        N.push(valuz);
    }

    int size1 = M.akar();
    int size2 = N.akar();


    if(size1 == size2)
    {
        Node * tmp1 = M.Head;
        Node * tmp2 = N.Head;

        int signal = 0;

        while(tmp1 != NULL)
        {
            if(tmp1->val != tmp2->val)
            {
                signal++;
                break;
            }
            tmp1 = tmp1->next;
            tmp2 = tmp2->next;
        }

        if(signal == 0)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    else
    {
        cout << "NO" << endl;
    }
    
    // st.printer();


    return 0;
}