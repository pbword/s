#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node *left = nullptr, *right = nullptr;

    Node(int value) : data(value) {}
};

Node* insertNode(Node* root, int val) {
    if(!root) return new Node(val);
    if(val < root->data) root->left = insertNode(root->left, val);
    else if(val > root->data) root->right = insertNode(root->right, val);
    return root;
}

void min(Node* root) {
    while(root && root->left) root = root->left;
    if(root) cout << "Minimum data value is :" << root->data << endl;
}

void mirror(Node* root) {
    if(root) {
        swap(root->left, root->right);
        mirror(root->left);
        mirror(root->right);
    }
}

void inorder(Node* root) {
    if(root) {
        inorder(root->left);
        cout << root->data << " | ";
        inorder(root->right);
    }
}

void search(Node* root, int value) {
    if(!root) cout << "Search is not successful for value :" << value;
    else if (root->data == value) cout << "Search is successful for value :" << value;
    else if (value < root->data) search(root->left, value);
    else search(root->right, value);
}

int findLongestPath(Node* root) {
    if (!root) return 0;
    return max(findLongestPath(root->left), findLongestPath(root->right)) + 1;
}

int main() {
    int ch, val, rootv;
    cout << "Insert root node of the tree :";
    cin >> rootv;
    Node* root = insertNode(nullptr, rootv);
    cout << "1)Insert nodes into the tree :";
    while(true) {
        cout << "\nEnter the data to insert :(-1 to exit) :";
        cin >> val;
        if(val == -1) break;
        insertNode(root, val);
        cout << val << " is inserted";
    }
    while(true) {
        cout << endl << "\n2)Find number of nodes in longest path from root\n3)Minimum data value found in the tree\n4)inorder traversal\n5)mirror tree\n6)Search\n7)Exit";
        cout << "Enter your choice :";
        cin >> ch;
        switch(ch) {
            case 2: cout << "Number of Nodes is longest path are :" << findLongestPath(root); break;
            case 3: min(root); break;
            case 4: cout << "\nInorder tree is :"; inorder(root); break;
            case 5: cout<< "\nMirror Treee"; mirror(root); break;
            case 6:
                cout<<"\nSearch tree";
                cout << "\nEnter the value to search :";
                cin >> val;
                cout << "\nSearch tree";
                search(root, val);
                break;

            case 7: return 0;
            default: cout << "Invalid choice"; break;
        }
    }
    return 0;
}
