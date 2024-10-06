#include <bits/stdc++.h>
using namespace std;
int front = -1;
int rear = -1;
const int mx = 5;
int que[mx];

void insert() {
	if(rear + 1 == front || (rear == mx - 1 && front == 1)) {
		cout << "Overflow" << "\n";
	} else {
		if(front == -1) {
			front = 1;
		}
		if(rear == -1) {
			rear = 0;
		}
        cout << "Enter value: ";
		int val;
		cin >> val;
		if(rear == mx - 1) {
			rear = 1;
		} else {
			rear++;
		}
		que[rear] = val;
	}
}

void Delete() {
	if (front == -1) {
		cout << "Underflow\n";
		return;
	}

	cout << "Deleted element: " << que[front] << "\n";

	if (front == rear) {  // If there was only one element
		front = -1;
		rear = -1;
	} else {
		front = front + 1;
		if(front == mx) {
			front = 1;
		}
	}
}
void display() {
	if (front == -1) {
		cout << "No elements\n";
		return;
	}

	cout << "Queue elements: ";
	if (rear >= front) {
		for (int i = front; i <= rear; i++) {
			cout << que[i] << " ";
		}
	} else {
		for (int i = front; i < mx; i++) {
			cout << que[i] << " ";
		}
		for (int i = 1; i <= rear; i++) {
			cout << que[i] << " ";
		}
	}
	cout << "\n";
}
int main() {
	int choice;
	while (1) {
		cout << "\n1. Insert\n";
		cout << "2. Delete\n";
		cout << "3. Display\n";
		cout << "4. Exit\n";
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
		case 1:
			insert();
			break;
		case 2:
			Delete();
			break;
		case 3:
			display();
			break;
		case 4:
			exit(0);  // Normal exit
		default:
			cout << "Invalid choice\n";
		}
	}
}