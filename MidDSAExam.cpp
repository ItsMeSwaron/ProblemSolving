#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:

    string websites;
    Node * next;
    Node * previous;

    Node(string websites)
    {
        this->websites = websites;
        this->next = NULL;
        this->previous = NULL;
    }
};

void TailInserter(Node * &Head, Node * &Tail, string websites)
{
    Node * NewNode = new Node(websites);

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

// void StraightPrinter(Node * Head)
// {
//     Node * tmp = Head;

//     while(tmp != NULL)
//     {
//         cout << tmp->websites << " ";
//         tmp = tmp->next; 
//     }

//     cout << endl;
// }

// void ReversePrinter(Node * Head)
// {
//     Node * tmp = Head;

//     while(tmp->next != NULL)
//     {
//         tmp = tmp->next; 
//     }

//     while(tmp != NULL)
//     {
//         cout << tmp->websites << " ";
//         tmp = tmp->previous;
//     }
// }

int WebsiteAcheNakiNaiDekhchi(Node * Head, string web)
{
    Node * tmp = Head;

    int signal = 0;

    while(tmp != NULL)
    {
        if(tmp->websites == web)
        {
            signal++;
            break;
        }
        tmp = tmp->next;
    }

    if(signal == 0)
    {
        cout << "Not Available" << endl;
        return 0;
    }
    else
    {
        return 1;
    }

}

int WebsiteFinder(Node * Head, string web)
{
    Node * tmp = Head;

    int count = 1;
    int signal = 0;

    tmp = Head;
    
    while(tmp != NULL)
    {
        if(tmp->websites == web)
        {
            signal++;
            break;
        }
        count++;
        tmp = tmp->next;
    }

    if(signal == 0)
    {
        cout << "Not Available" << endl;
    }
    else
    {
        cout << tmp->websites << endl;
    }

    return count;

}

int MoveForward(Node * Head, int position)
{
    Node * tmp = Head;

    for(int i=1;i<position;i++)
    {
        tmp = tmp->next;
    }

    if(tmp->next == NULL)
    {
        cout << "Not Available" << endl;
    }   
    else
    {
        tmp = tmp->next;
        position++;
        cout << tmp->websites << endl;
    } 

    return position;
}

int MoveBackward(Node * Head, int position)
{
    Node * tmp = Head;

    for(int i=1;i<position;i++)
    {
        tmp = tmp->next;
    }

    if(tmp->previous == NULL)
    {
        cout << "Not Available" << endl;
    }   
    else
    {
        tmp = tmp->previous;
        position--;
        cout << tmp->websites << endl;
    } 

    return position;

}

int main()
{
    Node * Head = NULL;
    Node * Tail = NULL;

    string websites;
    
    while(true)
    {
        cin >> websites;

        if(websites != "end")
        {
            TailInserter(Head,Tail,websites);
        }
        else
        {
            break;
        }
    }

    int Q;
    cin >> Q;

    for(int i=1;i<=Q;i++)
    {
        getchar();
        string queries;
        cin >> queries;

        int position;

        if(queries == "visit")
        {
            getchar();
            string web;
            cin >> web;

            int WebsiteAseOrNai = WebsiteAcheNakiNaiDekhchi(Head,web);

            if(WebsiteAseOrNai == 1)
            {
                position = WebsiteFinder(Head,web);
            }
        }
        else if(queries == "next")
        {
            position = MoveForward(Head,position);
        }
        else if(queries == "prev")
        {
            position = MoveBackward(Head,position);
        }
    }

    // StraightPrinter(Head);
    // ReversePrinter(Head);
    
    return 0;
}