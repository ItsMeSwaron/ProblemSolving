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

    if(root != NULL)
    {
        q.push(root);
    }

    while(!q.empty())
    {
        // 1. Queue theke ber korte hobe

        Node * parent = q.front();
        q.pop();

        // 2. Ja kaaj ase

        int l, r;
        cin >> l >> r;

        Node * BamSide = new Node(l);
        Node * DanSide = new Node(r);

        if(l != -1)
        {
            parent->left = BamSide;
        }

        if(r != -1)
        {
            parent->right = DanSide;
        }

            // nicher way teo uporer moto same kaaj kora jai

            // int l, r;
            // cin >> l >> r;

            // Node * BamSide;
            // Node * DanSide;

            // if(l == -1)
            // {
            //     BamSide = NULL;
            // }
            // else
            // {
            //     BamSide = new Node(l);
            // }

            // if(r == -1)
            // {
            //     DanSide = NULL;
            // }
            // else
            // {
            //     DanSide = new Node(r);
            // }

            // parent->left = BamSide;
            // parent->right = DanSide;

        // 3. Children gula ke push korte hobe

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

void TreePrinterLevelOrder(Node * root)
{
    if(root == NULL)
    {
        cout << "Bab-bye" << endl;
        return;
    }
    
    queue <Node *> q;
    q.push(root);

    while(!q.empty())
    {
        // 1. ber korte hobe from queue
        Node * parent = q.front();
        q.pop();

        // 2. ja kaaj kora lagbe

        cout << parent->val << " ";

        // 3. queue te abar childs gula pushsing

        if(parent->left)
        {
            q.push(parent->left);
        }
        
        if(parent->right)
        {
            q.push(parent->right);
        }

    }

}

void PreOrderTreeTraversal(Node * root)
{
    if(root == NULL)
    {
        return;
    }

    cout << root->val << " ";
    PreOrderTreeTraversal(root->left);
    PreOrderTreeTraversal(root->right);
}

void PostOrderTreeTraversal(Node * root)
{
    if(root == NULL)
    {
        return;
    }

    PostOrderTreeTraversal(root->left);
    PostOrderTreeTraversal(root->right);
    cout << root->val << " ";
}

void InOrderTreeTraversal(Node * root)
{
    if(root == NULL)
    {
        return;
    }

    PostOrderTreeTraversal(root->left);
    cout << root->val << " ";
    PostOrderTreeTraversal(root->right);
}

int Counter(Node * root)
{
    if(root == NULL)
    {
        return 0;
    }

    int LeftSubTree = Counter(root->left);
    int RightSubTree = Counter(root->right);

    return LeftSubTree + RightSubTree + 1;

}

int LeafCounter(Node * root)
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
       int LeftSubTree = LeafCounter(root->left);
       int RightSubTree = LeafCounter(root->right);

       return LeftSubTree + RightSubTree;
    }
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

int SmallFinder(Node * root)
{
    Node * tmp = root;

    while(tmp->left != NULL)
    {
        tmp = tmp->left;
    }

    return tmp->val;
}

int main()
{
    cout << "0. Break\n" << "1. Input\n" << "2. Level Order printer\n" << "3. PreOrder printer\n" << "4. PostOrder printer\n" << "5. InOrder printer\n" << "6. Count nodes\n" << "7. Count leaves\n" << "8. Max Height\n";

    Node * root;

    while(true)
    {   
        int N;
        cin >> N;

        if(N == 0)
        {
            break;
        }
        else if(N == 1)
        {
            root = TreeInserter();
        }
        else if(N == 2)
        {
            TreePrinterLevelOrder(root);
        }
        else if(N == 3)
        {
            PreOrderTreeTraversal(root);
        }
        else if(N == 4)
        {
            PostOrderTreeTraversal(root);
        }
        else if(N == 5)
        {
            InOrderTreeTraversal(root);
        }
        else if(N == 6)
        {
            cout << Counter(root) << endl;
        }
        else if(N == 7)
        {
            cout << LeafCounter(root) << endl;
        }
        else if(N == 8)
        {
            cout << MaxHeight(root) << endl;
        }
    }

    // cout << SmallFinder(root) << endl;
    

    return 0;
}