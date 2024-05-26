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

int MaxHeight(Node * root)
{
    if(root == NULL)
    {
        return 0;
    }

    int LeftSubTree = MaxHeight(root->left);
    int RightSubTree = MaxHeight(root->right);

    return max(LeftSubTree,RightSubTree) + 1;
}

void LevelFinder(Node * root, int height)
{
    queue <pair<Node *, int>> q;
    q.push({root,0});

    while(!q.empty())
    {
        pair <Node *, int> p = q.front();
        q.pop();

        Node * parent = p.first;
        int level = p.second;

        if(height == level)
        {
            cout << parent->val << " ";
        }

        if(parent->left)
        {
            q.push({parent->left,level+1});
        }

        if(parent->right)
        {
            q.push({parent->right,level+1});
        }
    }    


}

int main()
{
    Node * root = TreeInserter();
    int X;
    cin >> X;

    int ShorbochchoUchchota = MaxHeight(root);

    if(X >= ShorbochchoUchchota)
    {
        cout << "Invalid" << endl;
    }
    else
    {
        LevelFinder(root,X);
    }

    return 0;
}