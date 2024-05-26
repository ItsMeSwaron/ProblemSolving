// #include<bits/stdc++.h>
// using namespace std;

// class Node
// {
//     public:

//     int val;
//     Node * next;
    
//     Node(int val)
//     {
//         this->val = val;
//         this->next = NULL;
//     }
// };

// void TailInserter(Node * &head, Node * &tail, int val)
// {
//     Node * NewNode = new Node(val);

//     if(head == NULL)
//     {
//         head = NewNode;
//         tail = NewNode;
//         return;
//     }

//     tail->next = NewNode;
//     tail = NewNode;
// }

// void printer(Node * head)
// {
//     Node * tmp = head;
   
//     while(tmp != NULL)
//     {
//         cout << tmp->val << " ";
//         tmp = tmp->next;
//     }
// }

// void merger(Node * head1, Node * head2)
// {
//     Node * tmp = head1;

//     while(tmp->next != NULL)
//     {
//         tmp = tmp->next;
//     }

//     tmp->next = head2;
// }

// void sorter(Node * head1)
// {
//     for(Node * i=head1;i->next!=NULL;i=i->next)
//     {
//         for(Node * j=i->next;j!=NULL;j=j->next)
//         {
//             if(i->val > j->val)
//             {
//                 swap(i->val,j->val);
//             }
//         }
//     }
// }

// int main()
// {
//     Node * head1 = NULL;
//     Node * tail1 = NULL;
//     Node * head2 = NULL;
//     Node * tail2 = NULL;

//     while(true)
//     {
//         int val;
//         cin >> val;

//         if(val != -1)
//         {
//             TailInserter(head1,tail1,val);
//         }
//         else
//         {
//             break;
//         }
//     }

//     while(true)
//     {
//         int val;
//         cin >> val;

//         if(val != -1)
//         {
//             TailInserter(head2,tail2,val);
//         }
//         else
//         {
//             break;
//         }
//     }

//     merger(head1,head2);
//     sorter(head1);
//     printer(head1);

//     return 0;
// }


// #include<bits/stdc++.h>
// using namespace std;

// class Node
// {
//     public:

//     int val;
//     Node * next;
    
//     Node(int val)
//     {
//         this->val = val;
//         this->next = NULL;
//     }
// };

// void TailInserter(Node * &head, Node * &tail, int val)
// {
//     Node * NewNode = new Node(val);

//     if(head == NULL)
//     {
//         head = NewNode;
//         tail = NewNode;
//         return;
//     }

//     tail->next = NewNode;
//     tail = NewNode;
// }

// void printer(Node * head)
// {
//     Node * tmp = head;
   
//     while(tmp != NULL)
//     {
//         cout << tmp->val << " ";
//         tmp = tmp->next;
//     }
// }

// int sz(Node * head)
// {
//     int saiz = 0;
//     Node * tmp = head;

//     while(tmp != NULL)
//     {
//         saiz++;
//         tmp = tmp->next;
//     }
//     return saiz;
// }

// int x[100];

// void PalindromeChecker(Node * head)
// {
//     Node * tmp = head;

//     for(int i=0;i<sz(head);i++)
//     {
//         x[i] = tmp->val;
//         tmp = tmp->next;
//     }

//     int i = 0;
//     int j = sz(head) - 1;
//     int signal = 0;

//     while(i<j)
//     {
//         if(x[i] != x[j])
//         {
//             signal++;
//             break;
//         }
//         i++;
//         j--;
//     }

//     if(signal == 0)
//     {
//         cout << "Palindrome" << endl;
//     }
//     else
//     {
//         cout << "bab bye" << endl;
//     }
// }

// int main()
// {
//     Node * head = NULL;
//     Node * tail = NULL;

//     while(true)
//     {
//         int val;
//         cin >> val;

//         if(val != -1)
//         {
//             TailInserter(head,tail,val);
//         }
//         else
//         {
//             break;
//         }
//     }

//     PalindromeChecker(head);

//     return 0;
// }


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

void printer(Node * head)
{
    Node * tmp = head;
   
    while(tmp != NULL)
    {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
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

void MiddleBerKorchi(Node * head)
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

    MiddleBerKorchi(head);

    return 0;
}
