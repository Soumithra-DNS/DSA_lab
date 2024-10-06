#include <bits/stdc++.h>
using namespace std;

const int N = 100; // Array size for BST storage
int arr[N]; // Array to store BST

void BST(int data, int root){
    if(root >= N){
        cout << "No space available in the Array." << endl;
    } else {
        if(arr[root] == -1){ // If the position is empty, insert data
            arr[root] = data;
        } else if(arr[root] == data){ // If the data is already present
            cout << "The element " << data << " is already inserted at location: " << root << "." << endl;
        } else if(arr[root] < data){ // Insert into right subtree
            BST(data, (root * 2) + 1);
        } else { // Insert into left subtree
            BST(data, (root * 2));
        }
    }
}
// Pre-order Traversal: Visit -> Left -> Right
void preOrder(int idx) {
    if(arr[idx] != -1) {
        cout << arr[idx] << " ";
        preOrder(idx * 2);        // Left subtree
        preOrder((idx * 2) + 1);  // Right subtree
    }
}

// In-order Traversal: Left -> Visit -> Right
void inOrder(int idx) {
    if(arr[idx] != -1) {
        inOrder(idx * 2);         // Left subtree
        cout << arr[idx] << " ";
        inOrder((idx * 2) + 1);   // Right subtree
    }
}

// Post-order Traversal: Left -> Right -> Visit
void postOrder(int idx) {
    if(arr[idx] != -1) {
        postOrder(idx * 2);       // Left subtree
        postOrder((idx * 2) + 1); // Right subtree
        cout << arr[idx] << " ";
    }
}

int main() {
    fill(arr, arr + N, -1); // Initialize the array with -1 (empty)
    
    cout << "How many data elements you want to insert in BST: ";
    int n; 
    cin >> n;
    
    int root = 1;
    for(int i = 1; i <= n; i++){
        int data; 
        cin >> data;
        BST(data, root);
    }
    
    preOrder(1);
    cout << endl;
    inOrder(1);
    cout << endl;
    postOrder(1);

    return 0;
}
