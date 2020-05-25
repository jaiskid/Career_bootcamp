#include<bits/stdc++.h>
using namespace std;
class node {
public:
	int data;
	node*next;
	node(int d) {
		data = d;
		next = NULL;
	}
};
node* insertAthead(node*&head, int d) {
	node*n = new node(d);
	n->next = head;
	head = n;
}
void insertAttail(node*&head, int d) {
	if (head == NULL) {
		head = new node(d);
		return;
	}
	node*tail = head;
	while (tail->next != NULL) {
		tail = tail->next;
	}
	tail->next = new node(d);
	return;
}
void buildlist(node*&head, int n) {
	while (n--) {
		int data;
		cin >> data;
		insertAttail(head, data);
	}
	return;
}
int midPoint(node*head) {
	if (head->next == NULL || head == NULL) {
		return head->data;
	}
	node*slow = head;
	node*fast = head->next;
	while (fast != NULL and fast->next != NULL) {
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow->data;
}
int main() {
	int n;
	cin >> n;
	node *head = NULL;
	buildlist(head, n);
	cout << midPoint(head);
}