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

void TailInserter(Node * &head, Node * &tail, int val)
{
    Node * NewNode = new Node(val);

    if(head == NULL)
    {
        head = NewNode;
        tail = NewNode;
        return;
    }

    tail->next = NewNode;
    tail = NewNode;
}

void HeadInserter(Node * &head, int val)
{
    Node * NewNode = new Node(val);

    if(head == NULL)
    {
        head = NewNode;
        return;
    }

    NewNode->next = head;
    head = NewNode;
}

void printer(Node * head)
{
    Node * tmp = head;
   
    while(tmp != NULL)
    {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
}

void ulta(Node * head)
{
    if(head == NULL)
    {
        return;
    }
    ulta(head->next);
    cout << head->val << " ";
}

int sz(Node * head)
{
    int saiz = 0;
    Node * tmp = head;

    while(tmp != NULL)
    {
        saiz++;
        tmp = tmp->next;
    }
    return saiz;
}

void mucha(Node * &head, int pos, int saiz)
{
    if(pos > saiz)
    {
        cout << "Bab Bye" << endl;
        return;
    }

    if(pos == 1)
    {
        Node * DelNode = head;
        if(head->next != NULL)
        {
            head = head->next;
        }
        delete DelNode;
        return;
    }

    Node * tmp = head;

    for(int i=1;i<pos-1;i++)
    {
        tmp = tmp->next;
    }

    Node * DelNode = tmp->next;
    tmp->next = tmp->next->next;
    delete DelNode;
}

void sorter(Node * head)
{
    for(Node * i=head;i->next!=NULL;i=i->next)
    {
        for(Node * j=i->next;j!=NULL;j=j->next)
        {
            if(i->val > j->val)
            {
                swap(i->val,j->val);
            }
        }
    }
}

void InsertAtPosition(Node * &head, int val, int pos)
{
    if(pos > sz(head))
    {
        cout << "Bab bye" << endl;
        return;
    }

    Node * NewNode = new Node(val);
    Node * tmp = head;

    if(pos == 1)
    {
        NewNode->next = head;
        head = NewNode;
        return;
    }

    for(int i=1;i<pos-1;i++)
    {
        tmp = tmp->next;
    }

    NewNode->next = tmp->next;
    tmp->next = NewNode;
}
// 1st group er problem
void DupliRemover(Node * &head)
{
    Node * tmp = head;

    while(tmp->next != NULL)
    {
        if(tmp->next->val == tmp->val)
        {
            tmp->next = tmp->next->next;
        }

        if(tmp->next->val == tmp->val)
        {
            continue;
        }
        else
        {
            tmp = tmp->next;
        }
    }
}

void DupliRemoverUnsorted(Node * &head)
{
    // Node * tmp = head;

    for(Node * i=head;i->next!=NULL;i=i->next)
    {
        for(Node * j=i->next;j!=NULL;j=j->next)
        {
            if(i->val == j->val)
            {
                i->next = j->next;
            }
        }
    }

}

// 3rd group er problem
void Swapper(Node * head, int k)
{
    int akar = sz(head);
    int SizeFromTheBack = akar - k;

    Node * tmp1 = head;

    for(int i=1;i<k;i++)
    {
        tmp1 = tmp1->next;
    }

    Node * tmp2 = head;

    for(int i=1;i<=SizeFromTheBack;i++)
    {
        tmp2 = tmp2->next;
    }
    
    swap(tmp1->val,tmp2->val);
}

// 5th group er problem
void Merger(Node * head1, Node * head2)
{
    Node * tmp = head1;

    while(tmp->next != NULL)
    {
        tmp = tmp->next;
    }

    tmp->next = head2;
}

// 7th group er problem
void LoopChecker(Node * head)
{
    Node * fast = head;
    Node * slow = head;

    bool paisi = false;

    while(fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;

        if(fast->val == slow->val)
        {
            paisi = true;
            break;
        }
    }

    if(paisi == false)
    {
        cout << "loop nai" << endl;
    }
    else
    {
        cout << "loop founded" << endl;
    }
}

// 8th group er problem
void MiddleNodeFinder(Node * head)
{
    Node * fast = head;
    Node * slow = head;

    while(fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    cout << slow->val << endl;
}

// 9th group er problem
void ArrayToLinkedList(Node * &head, int * arr, int n)
{
    Node * matha = new Node(arr[0]);

    if(head == NULL)
    {
        head = matha;
    }

    Node * tmp = head;

    for(int i=1;i<n;i++)
    {
        Node * NewNode = new Node(arr[i]);
        tmp->next = NewNode;
        while(tmp->next != NULL)
        {
            tmp = tmp->next;
        }
    }

}

// 12th group er problem
vector <int> v1;
vector <int> v2;
void Reverser(Node * head)
{
    if(head == NULL)
    {
        return;
    }
    Reverser(head->next);
    v2.push_back(head->val);
}
void PalindromeChecker(Node * head)
{
    Reverser(head);

    bool signal = true;

    Node * tmp = head;

    while(tmp != NULL)
    {
        v1.push_back(tmp->val);
        tmp = tmp->next;
    }

    for(int i=0;i<sz(head);i++)
    {
        if(v1[i] != v2[i])
        {
            signal = false;
            break;
        }
    }

    if(signal == true)
    {
        cout << "Palindrome" << endl;
    }
    else
    {
        cout << "Not Palindrome" << endl;
    }
}

int main()
{
    Node * head = NULL;
    Node * tail = NULL;

    while(true)
    {
        int val;
        cin >> val;

        if(val != -1)
        {
            TailInserter(head,tail,val);
        }
        else
        {
            break;
        }
    }

    DupliRemoverUnsorted(head);
    printer(head);

    return 0;
}
