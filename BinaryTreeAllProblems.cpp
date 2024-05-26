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

Node * TreeBuilder()
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

    if(root != NULL)
    {
        q.push(root);
    }

    while(q.empty() == false)
    {
        Node * par = q.front();
        q.pop();

        int l, r;
        cin >> l >> r;

        Node * left;
        Node * right;

        if(l == -1)
        {
            left = NULL;
        }
        else
        {
            left = new Node(l);
        }

        if(r == -1)
        {
            right = NULL;
        }
        else
        {
            right = new Node(r);
        }

        par->left = left;
        par->right = right;

        if(par->left != NULL)
        {
            q.push(par->left);
        }

        if(par->right != NULL)
        {
            q.push(par->right);
        }
    }
    return root;
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

int mx = 0;

int Height(Node * root)
{   
    if(root == NULL)
    {
        return 0;
    }

    int l = Height(root->left);
    int r = Height(root->right);
    int d = l + r;
    mx = max(mx,d);
    return max(l,r) + 1;
}

int frq[1000] = {0};

void Width(Node * root)
{
    queue <pair<Node*,int>> q;
    q.push({root,1});

    while(q.empty() == false)
    {
        pair <Node*,int> pr = q.front();
        Node * obj = pr.first;
        int level = pr.second;
        q.pop();

        frq[level]++;

        if(obj->left != NULL)
        {
            q.push({obj->left,level+1});
        }

        if(obj->right != NULL)
        {
            q.push({obj->right,level+1});
        }
    }
}

void BSTChecker(Node * root)
{
    queue <Node *> q;
    q.push(root);

    int signal = 0;

    while(q.empty() == false)
    {
        Node * par = q.front();
        q.pop();

        if(par->left != NULL)
        {
            if(par->val < par->left->val)
            {
                signal++;
                break;
            }
        }

        if(par->right != NULL)
        {
            if(par->val > par->right->val)
            {
                signal++;
                break;
            }
        }

        if(par->left != NULL)
        {
            q.push(par->left);
        }

        if(par->right != NULL)
        {
            q.push(par->right);
        }
    }
    if(signal == 0)
    {
        cout << "BST" << endl;
    }
    else
    {
        cout << "Nope" << endl;
    }
}

int main()
{
    Node * root = TreeBuilder();
    // PreOrder(root);
    // int diam = Height(root);
    // cout << max(mx,diam) << endl;
    // cout << Height(root->left) + Height(root->right) << endl;
    // Width(root);

    // int Max = INT_MIN;

    // for(int i=0;i<200;i++)
    // {
    //     if(Max < frq[i])
    //     {
    //         Max = frq[i];
    //     }
    // }

    // for(int i=0;i<200;i++)
    // {
    //     if(Max == frq[i])
    //     {
    //         cout << i << endl;
    //         break;
    //     }
    // }

    BSTChecker(root);

    return 0;
}