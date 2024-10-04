#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *insert(int val, Node *ptr){
    Node *new_node = new Node();
    new_node->data = val;
    new_node->next = nullptr;
    ptr->next = new_node;
    return new_node;
}

Node *insert_at_first(int val, Node *ptr){
    Node *new_node = new Node();
    new_node->data = val;
    new_node->next = ptr;
    return new_node;
}

Node *insert_at_last(int val, Node *ptr){
    Node *head = ptr;
    Node *new_node = new Node();
    new_node->data = val;
    new_node->next = NULL;
    while(ptr->next != NULL){
        ptr = ptr->next;
    }
    ptr->next = new_node;
    return head;
}
Node *insert_at_index(int val, int index, Node *ptr){
    Node *head = ptr;
    Node *new_node = new Node();
    new_node->data = val;
    index--;
    while(index != 1){
        ptr = ptr->next;
        index--;
    }
    new_node->next = ptr->next;
    ptr->next = new_node;
    return head;
}

Node *delete_at_frist(Node *ptr){
    Node *temp = ptr;
    Node *head = ptr->next;
    free(temp);
    return head;
}

Node *delete_at_last(Node *ptr){
    Node *head = ptr;
    while(ptr->next->next != NULL){
        ptr = ptr->next;
    }
    free(ptr->next);
    ptr->next = NULL;
    return head;
}
Node *delete_at_index(int index, Node *ptr){
    Node *head = ptr;
    Node *prev = ptr;
    while(index != 1){
        prev = ptr;
        ptr = ptr->next;
        index--;
    }
    Node *temp = ptr;
    prev->next = ptr->next;
    free(temp);
    return head;
}


void print(Node *ptr){
    while(ptr != NULL){
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << "\n";
}

Node *merge_list(Node *head1, Node *head2){
    if(head1 == NULL) return head2;
    if(head2 == NULL) return head1;
    
    Node *merge_head = NULL;
    if(head1->data <= head2->data){
        merge_head = head1;
        merge_head->next = merge_list(head1->next, head2);
    }else{
        merge_head = head2;
        merge_head->next = merge_list(head1, head2->next);
    }
    
    return merge_head;
}
void split_list(Node *head, Node *&front, Node *&back){
    if(head == NULL || head->next == NULL){
        front = head;
        back = NULL;
        return;
    }
    
    Node *slow = head;
    Node *fast = head->next;
    
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    front = head;
    back = slow->next;
    slow->next = NULL;
}

void sort(Node *head){
    Node *current = head;
    while(current != NULL){
        Node *ptr = current->next;
        while(ptr != NULL){
            if(current->data > ptr->data ){
                int temp = current->data;
                current->data = ptr->data;
                ptr->data = temp;
            }
            ptr = ptr->next;
        }
        current = current->next;
    }
}



int main(){
    Node *first = new Node();
    Node *head = first;
    int val;
    while(true){
        cin >> val;
        if(val == -1)break;
        first = insert(val, first);
    }
    first->next = NULL;
    head = head->next;
    
    // second linked list...................
    // Node *first1 = new Node();
    // Node *head1 = first1;
    // int val1;
    // while(true){
    //     cin >> val1;
    //     if(val1 == -1)break;
    //     first1 = insert(val1, first1);
    // }
    // first1->next = NULL;
    // head1 = head1->next;
    
    //insertion...............
    // head = insert_at_first(7, head);
    // head = insert_at_last(9, head);
    // head = insert_at_index(8, 3, head);
    // print(head);
    
    //deletion...............
    // head = delete_at_frist(head);
    // head = delete_at_last(head);
    // head = delete_at_index(3, head);
    // print(head);
    
    //merged two list.................
    // print(head);
    // print(head1);
    // Node *merge_head = merge_list(head, head1);
    // print(merge_head);
    
    //split list ........................
    // Node *front = NULL;
    // Node *back = NULL;
    // split_list(head, front, back);
    // print(front);
    // print(back);
    
    //sorting.....................
    sort(head);
    print(head);
}



