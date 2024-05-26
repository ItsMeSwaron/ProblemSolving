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

// Node * TreeInserter()
// {
//     int val;
//     cin >> val;

//     Node * root;

//     if(val == -1)
//     {
//         root = NULL;
//     }
//     else
//     {
//         root = new Node(val);
//     }
    
//     queue <Node *> q;

//     if(root != NULL)
//     {
//         q.push(root);
//     }

//     while(q.empty() == false)
//     {
//         Node * par = q.front();
//         q.pop();

//         int l, r;
//         cin >> l >> r;

//         Node * bam = new Node(l);
//         Node * dan = new Node(r);

//         if(l != -1)
//         {
//             par->left = bam;
//         }

//         if(r != -1)
//         {
//             par->right = dan;
//         }

//         if(par->left)
//         {
//             q.push(par->left);
//         }

//         if(par->right)
//         {
//             q.push(par->right);
//         }
//     }

//     return root;
// }

Node * TreeBuilder(Node * root)
{
    int data;
    cin >> data;

    root = new Node(data);

    if(data == -1)
    {
        return NULL; 
    }

    cout << "for left of " << data << " ";
    root->left = TreeBuilder(root->left);
    cout << "for right of " << data << " ";    
    root->right = TreeBuilder(root->right);

    return root;
}

void InOrder(Node * root)
{
    if(root == NULL)
    {
        return;
    }

    InOrder(root->left);
    cout << root->val << " ";
    InOrder(root->right);
}

void PreOrder(Node * root)
{
    if(root == NULL)
    {
        return;
    }

    cout << root->val << " ";
    PreOrder(root->left);
    PreOrder(root->right);
}

void PostOrder(Node * root)
{
    if(root == NULL)
    {
        return;
    }

    PostOrder(root->left);
    PostOrder(root->right);
    cout << root->val << " ";
}


int main()
{
    // Node * shikor;
    Node * root;

    root = TreeBuilder(root);
    InOrder(root);
    cout << endl;
    // PreOrder(shikor);
    // cout << endl;
    // PostOrder(shikor);
    // cout << endl;

    return 0;
}