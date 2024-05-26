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

Node * head = NULL;
Node * tail = NULL;

class MyStack
{
    public:

    void Push(int val)
    {
        Node * NN = new Node(val);

        if(head == NULL)
        {
            head = NN;
            tail = NN;
            return;
        }

        tail->next = NN;
        tail = NN;
    }

    int Pop()
    {
        if(head == NULL)
        {
            cout << "Stack underflow" << endl;
            return -1;
        }

        if(head->next == NULL)
        {
            int value = head->val;
            delete head;
            head = NULL;
            return value;
        }

        int x;
        Node * tmp = head;

        while(tmp->next->next != NULL)
        {
            tmp = tmp->next;
        }

        x = tmp->next->val;
        delete tmp->next;
        tmp->next = NULL;
        return x;
    }

    void Printer()
    {
        Node * tmp = head;

        while(tmp != NULL)
        {
            cout << tmp->val << " ";
            tmp = tmp->next;
        }
    }

    int Top()
    {
        return tail->val;
    }

    int sz()
    {
        Node * tmp = head;
        int count = 0;

        while(tmp != NULL)
        {
            count++;
            tmp = tmp->next;
        }
        return count;
    }

    bool Empty()
    {
        if(head == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

};

void StackUlter(Node * head)
{
    if(head == NULL)
    {
        return;
    }

    StackUlter(head->next);
    cout << head->val << " ";
}

int main()
{

    // MyStack stk;

    stack <int> stk;

    stk.Push(10);
    stk.Push(20);
    stk.Push(30);
    stk.Push(40);
    stk.Push(50);

    // stk.Printer();
    // but this function works properly.

    // StackUlter(head);

    // cout << endl;

    // cout << stk.Top() << endl;
    // cout << stk.sz() << endl;
    // cout << stk.Empty() << endl;

    // stk.Printer();


    string Postfix;
    getline(cin,Postfix);

    stringstream ss(Postfix);
    string word;

    // while(ss >> word)
    // {
    //     cout << word << endl;
    // }

    while(ss >> word)
    {
        if(word == "*" || word == "/" || word == "+" || word == "-")
        {
            if(stk.empty() == false)
            {
                int x, y;
                x = stk.top();
                stk.pop();

                if(stk.empty() == false)
                {
                    y = stk.top();
                    stk.pop();
                }
                else
                {
                    cout << "Invalid expression" << endl;
                    break;
                }

                if(word == "*")
                {
                    stk.push(x * y);
                }
                else if(word == "/")
                {
                    stk.push(y / x);
                }
                else if(word == "+")
                {
                    stk.push(x + y);
                }
                else if(word == "-")
                {
                    stk.push(y - x);
                }
            }
            else
            {
                cout << "Invalid expression" << endl;
                break;                
            }
        }
        else
        {
            // cout << word << endl;
            stk.push(stoi(word));
            // cout << stk.top() << endl;
        }
    }

    if(stk.empty() == false)
    {
        cout << stk.top() << endl;
    }

    return 0;
}