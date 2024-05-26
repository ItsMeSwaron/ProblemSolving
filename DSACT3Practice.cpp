// #include<bits/stdc++.h>
// using namespace std;

// int n;
// int arr[100] = {-1000};
// int top1 = -1;
// int top2;

// void Top2Setter(int n)
// {
//     top2 = (n/2) - 1;
// }


// class MyStack
// {
//     public:

//     void push1(int val)
//     {
//         if(top1 == (n/2) - 1)
//         {
//             cout << "Stack1 overflow" << endl;
//         }
//         else
//         {
//             top1++;
//             arr[top1] = val;
//         }
//     }

//     void push2(int val)
//     {
//         if(top2 == n - 1)
//         {
//             cout << "Stack2 overflow" << endl;
//         }
//         else
//         {
//             top2++;
//             arr[top2] = val;
//         }
//     }

//     int pop1()
//     {
//         if(top1 == -1)
//         {
//             cout << "Stack1 underflow" << endl;
//             return -1;
//         }
//         else
//         {
//             int val;
//             val = arr[top1];
//             arr[top1] = INT_MIN;
//             top1--;
//             return val;
//         }
//     }

//     int pop2()
//     {
//         if(top2 == (n/2) - 1)
//         {
//             cout << "Stack2 underflow" << endl;
//             return -1;
//         }
//         else
//         {
//             int val;
//             val = arr[top2];
//             arr[top2] = INT_MIN;            
//             top2--;
//             return val;
//         }
//     }

// };

// int main()
// {
//     cin >> n;
//     Top2Setter(n);

//     MyStack stk;

//     stk.push1(100);
//     stk.push1(200);
//     stk.push1(300);
//     stk.push2(10);
//     stk.push2(20);
//     stk.push2(30);
//     stk.pop1();
//     // stk.pop1();
//     // stk.pop1();
//     // stk.pop1();
//     stk.pop2();
//     // stk.pop2();
//     // stk.pop2();
//     // stk.pop2();

//     // cout << arr[5] << endl;
//     // cout << arr[6] << endl;
//     // cout << arr[7] << endl;
//     // cout << arr[8] << endl;
//     // cout << arr[9] << endl;

//     for(int i=0;i<n;i++)
//     {
//         if(arr[i] > 0)
//         {
//             cout << arr[i] << " ";
//         }
//         else
//         {
//             cout << " - ";
//         }
//     }

//     return 0;
// }


////////////////////////////////////////////////////


// #include<bits/stdc++.h>
// using namespace std;

// class Node
// {
//     public:

//     int val;
//     Node * next;
//     Node * prev;

//     Node(int val)
//     {
//         this->val = val;
//         this->next = NULL;
//         this->prev = NULL;
//     }
// };

// Node * head = NULL;
// Node * tail = NULL;
// Node * mid = NULL;
// int x = 1;
// int y = 0;
// int cnt = 0;

// class MyStack
// {
//     public:

//     void push(int val)
//     {
//         cnt++;

//         Node * NN = new Node(val);

//         if(head == NULL)
//         {
//             head = NN;
//             tail = NN;
//             mid = NN;
//             return;
//         }

//         tail->next = NN;
//         NN->prev = tail;
//         tail = NN;

//         if(x == 1)
//         {
//             mid = mid->next;
//         }

//         if(x == 0)
//         {
//             x = 1;
//         }
//         else
//         {
//             x = 0;
//         }
//     }

//     void pop()
//     {
//         if(head == NULL)
//         {
//             cout << "Stack underflow" << endl;
//             return;
//         }

//         cnt--;

//         if(head->next == NULL)
//         {
//             Node * DN = head;
//             head = NULL;
//             tail = NULL;
//             mid = NULL;
//             delete DN;
//             return;
//         }

//         Node * DN = tail;
//         tail = tail->prev;
//         delete DN;

//         if(y == 0)
//         {
//             mid = mid->prev;
//         }

//         if(y == 0)
//         {
//             y = 1;
//         }
//         else
//         {
//             y = 0;
//         }
//     }
    
//     void DeleteMid()
//     {
//         // if(head == NULL)
//         // {

//         // }

//         // if(head->next == NULL)
//         // {

//         // }

//         if(cnt%2 == 0)
//         {
//             Node * DN = mid;
//             mid = mid->prev;
//             mid->next = mid->next->next;
//             mid->next->prev = mid;
//             delete DN;
//             cnt--;
//         }
//         else
//         {
//             Node * DN = mid;
//             mid = mid->next;
//             mid->prev = mid->prev->prev;
//             mid->prev->next = mid;
//             delete DN;   
//             cnt--;
//         }
//     }

//     void display()
//     {
//         Node * tmp = head;
//         while(tmp != NULL)
//         {
//             cout << tmp->val << " ";
//             tmp = tmp->next;
//         }
//     }

// };

// int main()
// {
//     MyStack stk;

//     stk.push(10);
//     stk.push(20);
//     stk.push(30);
//     stk.push(40);
//     stk.push(50);
//     stk.push(60);
//     // stk.DeleteMid();
//     stk.DeleteMid();

//     stk.display();
//     cout << endl;
//     cout << mid->val << endl;

//     return 0;
// }


////////////////////////////////////////////

// Binary queue
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;

    queue <string> q;
    q.push("1");

    while(n!=0)
    {
        string s1 = q.front();
        q.pop();

        cout << s1 << endl;

        string s2 = s1;

        q.push(s1.append("0"));
        q.push(s2.append("1"));
        n--;
    }

    return 0;
}


//////////////////////////////////////////////////////


// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     string s;
//     getline(cin,s);

//     cout << strlen(s) << endl;

//     // for(int i=0;i<len(s);i=i+2)
//     // {

//     // }

//     // stack <int> stk;



//     return 0;
// }