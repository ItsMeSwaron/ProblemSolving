#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:

    int val;
    Node * left;
    Node * right;

    Node(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }

};

Node * TreeInserter()
{
    int val;
    cin >> val;

    Node * root;

    if(val == -1)
    {
        root = NULL;
    }
    else
    {
        root = new Node(val);
    }

    queue <Node *> q;
    q.push(root);

    while(!q.empty())
    {
        Node * parent = q.front();
        q.pop();

        int LeftValue, RightValue;
        cin >> LeftValue >> RightValue;

        Node * LeftNode = new Node(LeftValue);
        Node * RightNode = new Node(RightValue);

        if(LeftValue != -1)
        {
            parent->left = LeftNode;
        }

        if(RightValue != -1)
        {
            parent->right = RightNode;
        }

        if(parent->left)
        {
            q.push(parent->left);
        }

        if(parent->right)
        {
            q.push(parent->right);
        }

    }

    return root;

}

int total = 0;

int Adder(Node * root)
{
    if(root == NULL)
    {
        return 0;
    }

    if(root->left == NULL && root->right == NULL)
    {
        return 0;
    }
    else
    {
        total = total + root->val;

        Adder(root->left);
        Adder(root->right);

        return total;
    }
}

int main()
{
    Node * root = TreeInserter();
    cout << Adder(root) << endl;

    return 0;
}