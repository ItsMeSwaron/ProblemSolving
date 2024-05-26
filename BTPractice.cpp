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

    queue <Node*> q;
    
    if(root)
    {
        q.push(root);
    }

    while(!q.empty())
    {
        Node * par = q.front();
        q.pop();

        int l, r;
        cin >> l >> r;

        Node * bam;
        Node * dan;

        if(l == -1)
        {
            bam = NULL;
        }
        else
        {
            bam = new Node(l);
        }

        if(r == -1)
        {
            dan = NULL;
        }
        else
        {
            dan = new Node(r);
        }

        par->left = bam;
        par->right = dan;

        if(par->left)
        {
            q.push(par->left);
        }

        if(par->right)
        {
            q.push(par->right);
        }
    }

    return root;
}

void LevelOrder(Node * root)
{
    queue <Node*> q;
    q.push(root);

    while(!q.empty())
    {
        Node * par = q.front();
        q.pop();

        cout << par->val << " ";

        if(par->left)
        {
            q.push(par->left);
        }

        if(par->right)
        {
            q.push(par->right);
        }
    }
}

int NodeCounter(Node * root)
{
    queue <Node*> q;
    q.push(root);

    int cnt = 0;

    while(!q.empty())
    {
        Node * par = q.front();
        q.pop();

        cnt++;

        if(par->left)
        {
            q.push(par->left);
        }

        if(par->right)
        {
            q.push(par->right);
        }
    }
    return cnt;
}

int NodeCounterrecur(Node * root)
{
    if(root == NULL)
    {
        return 0;
    }

    int l = NodeCounterrecur(root->left);
    int r = NodeCounterrecur(root->right);

    return l + r + 1;
}

vector <int> v;

int LeafCounter(Node * root)
{
    queue <Node*> q;
    q.push(root);

    int cnt = 0;

    while(!q.empty())
    {
        Node * par = q.front();
        q.pop();

        if(par->left == NULL && par->right == NULL)
        {
            cnt++;
            v.push_back(par->val);
        }

        if(par->left)
        {
            q.push(par->left);
        }

        if(par->right)
        {
            q.push(par->right);
        }
    }
    return cnt;
}

int LeafCounterrecur(Node * root)
{
    if(root == NULL)
    {
        return 0;
    }

    if(root->left == NULL && root->right == NULL)
    {
        return 1;
    }
    else
    {
        int l = LeafCounterrecur(root->left);
        int r = LeafCounterrecur(root->right);
        return l + r;
    }
}

int Uchchota(Node * root)
{
    // Risky method. Do not attempt

    queue <Node*> q;
    q.push(root);

    int lev = 0;

    while(!q.empty())
    {
        Node * par = q.front();
        q.pop();

        if(q.empty())
        {
            lev++;
        }

        if(par->left)
        {
            q.push(par->left);
        }

        if(par->right)
        {
            q.push(par->right);
        }
    }
    return lev;
}

int Uchchotarecur(Node * root)
{
    if(root == NULL)
    {
        return 0;
    }

    int l = Uchchotarecur(root->left);
    int r = Uchchotarecur(root->right);
    int h = max(l,r) + 1;
    return h;
}

void NodeChecker(Node * root, int x)
{
    queue <Node*> q;
    q.push(root);

    int signal = 0;

    while(!q.empty())
    {
        Node * par = q.front();
        q.pop();

        if(x == par->val)
        {
            signal = 1;
            break;
        }

        if(par->left)
        {
            q.push(par->left);
        }

        if(par->right)
        {
            q.push(par->right);
        }        
    } 

    if(signal == 0)
    {
        cout << "Nai" << endl;
    }
    else
    {
        cout << "Exists" << endl;
    }
}

void NodeLevel(Node * root,int x)
{
    queue <pair<Node*,int>> q;
    q.push({root,1});

    while(!q.empty())
    {
        pair <Node*,int> p = q.front();
        Node * obj = p.first;
        int lev = p.second;
        q.pop();

        if(obj->val == x)
        {
            cout << obj->val << " level -> " << lev << endl;
        }
 
        if(obj->left)
        {
            q.push({obj->left,lev+1});
        }

        if(obj->right)
        {
            q.push({obj->right,lev+1});
        }        
    }
}

void LeftView(Node * root)
{
    queue <pair<Node*,int>> q;
    q.push({root,1});
    int PrevLevel = 1;

    cout << root->val << " ";

    while(!q.empty())
    {
        pair<Node*,int> pr = q.front();
        Node * obj = pr.first;
        int level = pr.second;
        q.pop();

        if(PrevLevel != level)
        {
            cout << obj->val << " ";
        }

        PrevLevel = level;

        if(obj->left)
        {
            q.push({obj->left,level+1});
        }

        if(obj->right)
        {
            q.push({obj->right,level+1});
        }
    }
}

int mx = 0;

int Diameter(Node * root)
{
    if(root == NULL)
    {
        return 0;
    }

    int l = Diameter(root->left);
    int r = Diameter(root->right);
    int d = l + r;
    mx = max(mx,d);
    return max(l,r) + 1;
}

void SpecialChecker(Node * root)
{
    queue <Node*> q;
    q.push(root);

    int signal = 0;

    while(!q.empty())
    {
        Node * par = q.front();
        q.pop();

        if(par->left == NULL && par->right != NULL)
        {
            signal = 1;
            break;
        }

        if(par->right == NULL && par->left != NULL)
        {
            signal = 1;
            break;
        }

        if(par->left)
        {
            q.push(par->left);
        }

        if(par->right)
        {
            q.push(par->right);
        }
    }

    if(signal)
    {
        cout << "normal" << endl;
    }
    else
    {
        cout << "Special" << endl; 
    }
}

int main()
{
    Node * root = TreeBuilder();
    // LevelOrder(root);
    // cout << endl;
    // cout << NodeCounter(root) << endl;
    // cout << NodeCounterrecur(root) << endl;
    // cout << LeafCounter(root) << endl;

    // for(int x : v)
    // {
    //     cout << x << " ";
    // }

    // cout << endl;

    // cout << LeafCounterrecur(root) << endl;
    // cout << Uchchota(root) << endl;
    // cout << Uchchotarecur(root) - 1 << endl;
    // NodeChecker(root,90);

    // NodeLevel(root,50);
    // LeftView(root);
    // cout << DiameterLeft(root->left) + DiameterRight(root->right) << endl;

    // int diam = Diameter(root);
    // cout << max(diam,mx);

    SpecialChecker(root);

    return 0;
}