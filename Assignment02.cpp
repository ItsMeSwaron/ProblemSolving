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

    void Push(int val)
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

    void Pop()
    {
        size--;

        Node * DelNode = Tail;
        Tail = Tail->previous;
        if(Tail == NULL)
        {
            Head = NULL;
        }
        delete DelNode;
    }
    
    int Top()
    {
        return Tail->val;
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

class MyQueue
{
    public:

    Node * Head = NULL;
    Node * Tail = NULL;

    int size = 0;

    void Push(int val)
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

    void Pop()
    {
        size--;

        Node * DelNode = Head;
        Head = Head->next;
        if(Head == NULL)
        {
            Tail = NULL;
            delete DelNode;
            return;
        }
        Head->previous = NULL;
        delete DelNode;
    }

    int Front()
    {
        return Head->val;
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
    MyStack A;
    MyQueue B;

    int X1, X2;
    cin >> X1 >> X2;

    for(int i=1;i<=X1;i++)
    {
        int N;
        cin >> N;
        A.Push(N);
    }

    for(int i=1;i<=X2;i++)
    {
        int M;
        cin >> M;
        B.Push(M);
    }

    if(X1 != X2)
    {
        cout << "NO" << endl;
    }
    else
    {
        int signal = 0;

        while(!A.empty())
        {
            if(A.Top() != B.Front())
            {
                signal++;
                break;
            }

            A.Pop();
            B.Pop();

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

}

