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

void TailInserter(Node * &Head, Node * &Tail, int val)
{
    Node * NotunNode = new Node(val);

    if(Head == NULL)
    {
        Head = NotunNode;
        Tail = NotunNode;
        return;
    }

    Tail->next = NotunNode;
    Tail = NotunNode;

}

// void Printer(Node * Head)
// {
//     Node * tmp = Head;

//     while(tmp != NULL)
//     {
//         cout << tmp->val << " ";
//         tmp = tmp->next;
//     }

// }

int Searcher(Node * Head, int X)
{
    Node * tmp = Head;

    int index = 0;
    int signal = 0;

    while(tmp != NULL)
    {
        if(tmp->val == X)
        {
            signal++;
            break;
        }
        else
        {
            index++;
        }
        tmp = tmp->next;
    }

    if(signal == 0)
    {
        return -1;
    }
    else
    {
        return index;
    }
}

int main()
{
    int T;
    cin >> T;

    for(int i=1;i<=T;i++)
    {
        Node * Head = NULL;
        Node * Tail = NULL;
        
        int val;

        while(true)
        {
            cin >> val;

            if(val != -1)
            {
                TailInserter(Head,Tail,val);
            }
            else
            {
                break;
            }
        }

        int X;
        cin >> X;
        
        int index = Searcher(Head,X);
        cout << index << endl;
        // Printer(Head);

    }


    return 0;
}
