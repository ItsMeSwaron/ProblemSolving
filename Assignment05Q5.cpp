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
        return root;
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

void LeftSidePrinter(Node * root)
{
    if(root == NULL)
    {
        return;
    }

    if(root->left == NULL)
    {
        LeftSidePrinter(root->right);
        cout << root->val << " ";
    }
    else 
    {
        LeftSidePrinter(root->left);
        cout << root->val << " ";
    }


}

void RightSidePrinter(Node * root)
{
    if(root == NULL)
    {
        return;
    }

    if(root->right == NULL)
    {
        cout << root->val << " ";
        RightSidePrinter(root->left);
    }
    else 
    {
        cout << root->val << " ";
        RightSidePrinter(root->right);
    }

}

int main()
{
    Node * root = TreeInserter();

    if(root->left)
    {
        LeftSidePrinter(root->left);
    }
    
    if(root)
    {
        cout << root->val << " ";
    }

    if(root->right)
    {
        RightSidePrinter(root->right);
    }

    return 0;
}