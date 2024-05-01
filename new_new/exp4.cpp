//Student Name : Aniruddha Avinash Joshi

#include <iostream>
#include <climits>
#include <stack>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int data){
        left = NULL;
        right = NULL;
        this->data = data;
    }
};

class Tree{
public:
    TreeNode *root;

    Tree(){
        root = NULL;
    }

    void insert(TreeNode *root, TreeNode *node);
    TreeNode *create();
    void PrintInorder(TreeNode *root);
    void PrintPostorder(TreeNode *root);
    void PrintPreorder(TreeNode *root);
    void search(TreeNode *root, int key);
    int longestPath(TreeNode *root);
    int MinInTree(TreeNode *root);
    void Mirror(TreeNode *root);
    void PrintInorderNonRecursive(TreeNode *root);
    void PrintPreorderNonRecursive(TreeNode *root);
    void PrintPostorderNonRecursive(TreeNode *root);
    int Max(int a, int b);
    int Min(int a, int b);
};

int Tree::Max(int a, int b)
{
    int max = (a > b) ? a : b;
    return max;
}

int Tree::Min(int a, int b)
{
    int min = (a < b) ? a : b;
    return min;
} 

void Tree::insert(TreeNode *root, TreeNode *node)
{
    if (root == NULL)
    {
        return;
    }

    if (root->data > node->data)
    {
        if (root->left == NULL)
            root->left = node;
        else
        {
            insert(root->left, node);
            return;
        }
    }
    else
    {
        if (root->right == NULL)
            root->right = node;
        else
        {
            insert(root->right, node);
            return;
        }
    }
}

TreeNode* Tree::create()
{
    char ch;
    ch = 'y';
    do
    {
        cout << "Enter the data for the node: " << endl;
        int newdata;
        cin >> newdata;
        TreeNode *newNode = new TreeNode(newdata);

        if (root == NULL)
            root = newNode;

        else
        {
            insert(root, newNode);
        }

        cout << "Do you want to continue?(y|n) :  ";
        cin >> ch;
    } while (ch != 'n');

    return this->root;
}

void Tree::PrintInorder(TreeNode *root)
{
    if (root == NULL)
        return;

    PrintInorder(root->left);
    cout << root->data << "\t";
    PrintInorder(root->right);
}

void Tree::PrintPostorder(TreeNode *root)
{
    if (root == NULL)
        return;

    PrintPostorder(root->left);
    PrintPostorder(root->right);
    cout << root->data << "\t";
}

void Tree::PrintPreorder(TreeNode *root)
{
    if (root == NULL)
        return;

    cout << root->data << "\t";
    PrintPreorder(root->left);
    PrintPreorder(root->right);
}

void Tree::search(TreeNode *root, int key)
{
    if (root == NULL)
    {
        cout << "key is not present\n";
        return;
    }

    if (key < root->data) search(root->left, key);
    else if (key > root->data)  search(root->right, key);
    else{
        cout << "key is present\n";
        return;
    }
}

int Tree::longestPath(TreeNode *root)
{
    if (root == NULL)
        return 0;

    int leftPath = longestPath(root->left);
    int rightPath = longestPath(root->right);

    return Max(leftPath, rightPath) + 1;
}

int Tree::MinInTree(TreeNode *root)
{
    if (root == NULL)
        return INT_MAX;

    int smallestInLeft = MinInTree(root->left);
    int smallestInRight = MinInTree(root->right);

    return Min(root->data, Min(smallestInLeft, smallestInRight));
}

void Tree::Mirror(TreeNode *root)
{
    if (root == NULL)
        return;

    TreeNode *temp = root->left;
    root->left = root->right;
    root->right = temp;

    Mirror(root->left);
    Mirror(root->right);
}
void Tree::PrintInorderNonRecursive(TreeNode *root)
{
    stack<TreeNode*> s;
    TreeNode* curr = root;
    while(curr!=NULL || s.empty() == false)
    {
        while(curr!=NULL)
        {
            s.push(curr);
            curr=curr->left;
        }
        curr=s.top();
        s.pop();
        cout<<curr->data<<"\t";
        curr=curr->right;
    }
}
void Tree::PrintPreorderNonRecursive(TreeNode *root)
{
    if(root==NULL)
        return;
    stack<TreeNode*> s;
    s.push(root);
    
    while(s.empty() == false)
    {
        TreeNode* curr = s.top();
        cout<<curr->data<<"\t";
        s.pop();
        if(curr->right)  
            s.push(curr->right);
        if(curr->left)  
            s.push(curr->left);
    }
}
void Tree::PrintPostorderNonRecursive(TreeNode *root)
{
    if(root==NULL)
        return;
    stack<TreeNode*> s;
    TreeNode* prev = NULL;    
    while(root || !s.empty())
    {   
        while(root)
        {
            s.push(root);
            root=root->left;
        }
        root = s.top();
        if(!root->right ||root->right == prev)
        {
            cout<<root->data<<"\t";
            s.pop();
            prev=root;
            root=NULL;
        }
        else
        {
            root=root->right;
        }
    }
}
int main()
{

    char ch;
    cout<<".....MENU.....\n";
    cout<<"1. Create a tree\n";
    cout<<"2. Display Tree\n";
    cout<<"3. Search a value\n";
    cout<<"4. To find the number of nodes in the Longest Path\n";
    cout<<"5. To find Node with Minimum data\n";
    cout<<"6. To Mirror the Tree\n";
    cout<<"7. Exit\n";
    cout<<"Enter Your Choice : ";
    cin >> ch;
    TreeNode *root;
    Tree Mytree;
    while (ch != '7')
    {

        if (ch == '1')
        {
            root = Mytree.create();
        }
        else if (ch == '2')
        {
            cout<<"\nPreorder Tree(Recursive):";cout<<"\t";
            Mytree.PrintPreorder(root);cout<<endl;
            cout<<"\nPreorder Tree(Iterative):";cout<<"\t";
            Mytree.PrintPreorderNonRecursive(root);cout<<endl;
        	cout<<"\nInorder Tree(Recursive):";cout<<"\t";
            Mytree.PrintInorder(root);cout<<endl;
            cout<<"\nInorder Tree(Iterative):";cout<<"\t";
            Mytree.PrintInorderNonRecursive(root);cout<<endl;
            cout<<"\nPostorder Tree(Recursive):";cout<<"\t";
            Mytree.PrintPostorder(root);cout<<endl;
            cout<<"\nPostorder Tree(Iterative):";cout<<"\t";
            Mytree.PrintPostorderNonRecursive(root);cout<<endl;
        }
        else if (ch == '3')
        {
            cout << "Enter the key that want to find in the Tree\n";
            int key;
            cin >> key;
            Mytree.search(root, key);
        }
        else if (ch == '4')
        {
            cout << Mytree.longestPath(root);
        }
        else if (ch == '5')
        {
            cout << Mytree.MinInTree(root);
        }
        else if (ch == '6')
        {
            Mytree.Mirror(root);
            cout<<"Mirroring The Inorder Tree:";
            Mytree.PrintInorder(root);cout<<endl;
            cout<<"\nMirroring The Postorder Tree:";
            Mytree.PrintPostorder(root);cout<<endl;
            cout<<"\nMirroring The Preorder Tree:";
            Mytree.PrintPreorder(root);cout<<endl;
        }
        cout<<"\n1. Create a tree\n";
		cout<<"2. Display Tree\n";
		cout<<"3. Search a value\n";
		cout<<"4. To find the number of nodes in the Longest Path\n";
		cout<<"5. To find Node with Minimum data\n";
		cout<<"6. To Mirror the Tree\n";
		cout<<"7. Exit\n";
		cout<<"Enter Your Choice : ";
        cin >> ch;
    }
    cout << "Thank You!!\n";
}
