#include<bits/stdc++.h>
using namespace std;

char stk[100];
char CopyStk[100];
char PalindromeStk[100];

int top = -1;

void push(char val)
{
    top++;
    stk[top] = val;
}

char pop()
{
    if(top == -1)
    {
        cout << "Empty" << endl;
        return -1;
    }

    char x;
    x = stk[top];
    top--;
    return x;
}

char peak()
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
        cout << pop();
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
    string letters;
    getline(cin,letters);

    for(int i=0;i<letters.size();i++)
    {
        push(letters[i]);
    }

    // int CopySize = 0;

    for(int i=0;i<size();i++)
    {
        CopyStk[i] = stk[i];
        // CopySize++;
    }

    int k = 0;

    while(top != -1)
    {
        PalindromeStk[k] = pop();
        k++;
    }

    // int k = 0;
    // int l = CopySize-1;

    // while(CopySize--)
    // {
    //     PalindromeStk[k] = CopyStk[l];
    //     k++;
    //     l--;
    // }

    int signal = 0;

    for(int i=0;i<size();i++)
    {
        if(CopyStk[i] != PalindromeStk[i])
        {
            signal = 1;
            break;
        }
    }

    for(int i=0;i<size();i++)
    {
        cout << PalindromeStk[i];
    }

    cout << endl;

    for(int i=0;i<size();i++)
    {
        cout << CopyStk[i];
    }

    if(signal == 0)
    {
        cout << "Palindrome" << endl;
    }
    else
    {
        cout << "Not Palindrome" << endl;
    }


    // push(40);
    // push(50);

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
    
    // cout << peak() << endl;
    // cout << size() << endl;
    // cout << empty() << endl;
    // printer();

    return 0;
}