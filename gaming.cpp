#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
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

    void TI(Node * &head, Node * &tail, int val)
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

    vector <int> v;

    void game(Node * &head, int k, int n)
    {
        Node * tmp = head;
        int tmpK = 1;
        int process = 1;

        while(process != n)
        {
            while(tmpK != k - 1)
            {
                tmp = tmp->next;
                tmpK++;
            }

            v.push_back(tmp->next->val);
            tmp->next = tmp->next->next;
            // delete tmp->next;
            tmp = tmp->next;

            process++;
            tmpK = 1;
        }

        v.push_back(tmp->val);
    }

    int findTheWinner(int n, int k) 
    {
        Node * head = NULL;
        Node * tail = NULL;

        int players = 1;

        while(players != n + 1)
        {
            TI(head,tail,players);
            players++;
        }

        tail->next = head;

        game(head,k,n);

        for(int x : v)
        {
            cout << x << " ";
        } 

    }
    
};


int main()
{
    Solution s;
    s.findTheWinner(5,3);

    return 0;
}