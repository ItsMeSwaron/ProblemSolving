#include<bits/stdc++.h>
using namespace std;

int stk[100];
int top = -1;

void push(int val)
{
    top++;
    stk[top] = val;
}

int pop()
{
    if(top == -1)
    {
        cout << "Empty" << endl;
        return -1;
    }

    int x;
    x = stk[top];
    top--;
    return x;
}

int peak()
{
    if(top != -1)
    {
        return stk[top];
    }
    else
    {
        return -1;
    }
}

void printer()
{
    while(top != -1)
    {
        cout << pop() << " ";
    }
    cout << endl;
}

int size()
{
    return top+1;
}

bool empty()
{
    if(top == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);

    // for(int i=0;i<4;i++)
    // {
    //     cout << stk[i] << " ";
    //     cout << top << endl;
    // }

    // cout << pop() << " ";
    // cout << pop() << " ";
    // cout << pop() << " ";
    // cout << pop() << " ";
    // cout << pop() << " ";
    // cout << pop() << " ";
    
    cout << peak() << endl;
    cout << size() << endl;
    cout << empty() << endl;
    printer();

    return 0;
}