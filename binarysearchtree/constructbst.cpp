#include <iostream>
#include <queue>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;
    node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
}; 

void levelOrderTraversal(node* root) {
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty()) {
        node* temp = q.front();
        q.pop();

        if (temp == NULL) { 
            cout << endl;
            if (!q.empty()) {
                q.push(NULL);
            }
        }
        else {
            cout << temp->data << " ";
            if (temp->left) {
                q.push(temp->left);
            }

            if (temp->right) {
                q.push(temp->right);
            }
        }
    }
}

node* insertintobst(node* root, int d) {
    if (root == NULL) {
        root = new node(d);
        return root;
    }
    if (d < root->data) {
        root->left = insertintobst(root->left, d);
    }
    else if (d > root->data) {
        root->right = insertintobst(root->right, d);
    }
    return root;
}

void takeinput(node*& root) {
    int data;
    cin >> data;
    //ager uper input nhi hoga to root phle 0 se start hoga 
    while (data != -1) {
        root = insertintobst(root, data);
        cin >> data;
    }
}

int main() {
    node* root = NULL;
    cout << "Enter the data to create the BST" << endl;
    takeinput(root);
    cout << endl;
    cout << "Printing the level order traversal: "<< endl;
    levelOrderTraversal(root);

    return 0;
}
