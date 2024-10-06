#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node *left;
    node *right;
};

// Function to create a new node
node *createNode(int val) {
    node *newNode = new node();
    newNode->data = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a new value in the BST
node *insert(node *ptr, int val) {
    if (ptr == NULL) {
        return createNode(val);  // Corrected here
    }
    if (val < ptr->data) {
        ptr->left = insert(ptr->left, val);
    } else if (val > ptr->data) {
        ptr->right = insert(ptr->right, val);
    } else {
        cout << "Element already exists\n";
    }
    return ptr;
}

// Pre-order Traversal
void preOrder(node *ptr) {
    if (ptr != NULL) {
        cout << ptr->data << " ";
        preOrder(ptr->left);
        preOrder(ptr->right);
    }
}

// In-order Traversal
void inOrder(node *ptr) {
    if (ptr != NULL) {
        inOrder(ptr->left);
        cout << ptr->data << " ";
        inOrder(ptr->right);
    }
}

// Post-order Traversal
void postOrder(node *ptr) {
    if (ptr != NULL) {
        postOrder(ptr->left);
        postOrder(ptr->right);
        cout << ptr->data << " ";
    }
}

int main() {
    node *root = NULL;
    int com;
    int x;

    while (1) {
        cout << "\nPress 1 to insert data\nPress 2 to display tree and quit\n";
        cin >> com;
        switch (com) {
            case 1:
                cout << "Enter number: ";
                cin >> x;
                root = insert(root, x);  // Fixed the parameter order
                break;
            case 2:
                cout << "\nPre-order Traversal: ";
                preOrder(root);
                cout << "\nIn-order Traversal: ";
                inOrder(root);
                cout << "\nPost-order Traversal: ";
                postOrder(root);
                return 0;
            default:
                cout << "Invalid option. Please try again.\n";
        }
    }

    return 0;
}
