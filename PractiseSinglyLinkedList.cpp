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

void TailInserter(Node * &Head, int val)
{
    Node * newnode = new Node(val);

    if(Head == NULL)
    {
        Head = newnode;
        return;
    }

    Node * tmp = Head;

    while(tmp->next != NULL)
    {
        tmp = tmp->next;
    }

    tmp->next = newnode;

}

void SpecificInserter(Node * Head, int pos, int val)
{
    Node * newnode = new Node(val);
    Node * tmp = Head;

    for(int i=0;i<pos;i++)
    {
        tmp = tmp->next;
    }

    newnode->next = tmp->next;
    tmp->next = newnode; 
    
}

void printer(Node * Head)
{
    Node * tmp = Head;

    while(tmp != NULL)
    {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }

    cout << endl << endl;
}

int counter(Node * Head)
{
    int cnt = 0;

    Node * tmp = Head;

    while(tmp != NULL)
    {
        tmp = tmp->next;
        cnt++;
    }
    // cout << cnt << endl << endl;
    return cnt;
}

void DupliChecker(Node * &Head)
{
    Node * tmp = Head;

    int all[100] = {0};

    while(tmp != NULL)
    {
        int val = tmp->val;
        all[val]++;
        tmp = tmp->next;
    }    

    int signal = 0;

    for(int i=0;i<100;i++)
    {
        if(all[i] > 1)
        {
            signal++;
            break;
        }
    }

    if(signal == 0)
    {
        cout << "NO" << endl << endl;
    }
    else
    {
        cout << "YES" << endl << endl;
    }

}

void MiddleFinder(Node * Head, int count)
{
    Node * tmp = Head;

    if(count%2 != 0)
    {
        for(int i=1;i<(count/2)+1;i++)
        {
            tmp = tmp->next;
        }
        cout << tmp->val << endl << endl;
    }
    else
    {
        for(int i=1;i<(count/2);i++)
        {
            tmp = tmp->next;
        }
        cout << tmp->val << " " << tmp->next->val << endl << endl;
    }
}

void Reverser(Node * Head)
{
    if(Head == NULL)
    {
        return;
    }

    Reverser(Head->next);
    cout << Head->val << " ";

} 

void SortChecker(Node * Head)
{
    Node * tmp = Head;

    int signal = 0;

    while(tmp->next != NULL)
    {
        if(tmp->val > tmp->next->val)
        {
            signal++;
            break;
        }
        tmp = tmp->next;
    }

    if(signal == 0)
    {
        cout << "YES" << endl << endl;
    }
    else
    {
        cout << "NO" << endl << endl;
    }    

}

void DescendingSorter(Node * Head)
{
    // Node * i = Head;
    Node * tmp;

    for(Node * i=Head;i->next!=NULL;i=i->next)
    {
        for(Node * j=i->next;j!=NULL;j=j->next)
        {
            if(i->val < j->val)
            {
                swap(i->val,j->val);
            }
        }
    }

    printer(Head);

}

void MaxFinder(Node * Head)
{
    int Max = INT_MIN;

    for(Node * i=Head;i!=NULL;i=i->next)
    {
        if(Max < i->val)
        {
            Max = i->val;
        }
    }

    cout << Max << endl << endl;

}


int main()
{
    Node * Head = NULL;
    // Node * Head2 = NULL;

    int val;

    while(val != -1)
    {
        cin >> val;
        if(val != -1)
        {
            TailInserter(Head,val);
        }
    }

    // int val2;

    // while(val2 != -1)
    // {
    //     cin >> val2;
    //     if(val2 != -1)
    //     {
    //         TailInserter(Head2,val2);
    //     }
    // }    



    // printer(Head);

    // counter(Head);

    // DupliChecker(Head);

    // int count1 = counter(Head1);
    // int count2 = counter(Head2);
    // if(count1 == count2)
    // {
    //     cout << "YES" << endl;
    // }
    // MiddleFinder(Head,count);

    // Reverser(Head);

    // SortChecker(Head);

    // DescendingSorter(Head);

    // MaxFinder(Head);

    
    int q;
    cin >> q;

    for(int i=1;i<=q;i++)
    {
        int pos;
        cin >> pos;

        int val;
        cin >> val;

        SpecificInserter(Head,pos,val);

        printer(Head);
    }


    

    return 0;
}