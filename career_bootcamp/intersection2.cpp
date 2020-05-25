#include<bits/stdc++.h>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x): val(x), next(NULL) {}
};
void intail(ListNode*&head, int data) {
	if (head == NULL) {
		head = new ListNode(data);
		return;
	}
	ListNode*tail = head;
	while (tail->next != NULL) {
		tail = tail->next;
	}

	tail->next = new ListNode(data);
	return;
}
void buildlist(ListNode*&head) {
	int n;
	cin >> n;
	while (n--) {
		int data;
		cin >> data;
		intail(head, data);
	}
}
void print(ListNode*n) {
	while (n != NULL) {
		cout << n->val << " ";
		n = n->next;
	}
}
int count(ListNode* head) {
	ListNode* curr = head;
	int count = 0;
	while (curr != NULL) {
		count++;
		curr = curr->next;
	}
	return count;
}
int _getIntersection(int d, ListNode* head1, ListNode*head2) {
	ListNode* curr1 = head1;
	ListNode* curr2 = head2;
	for (int i = 0; i < d; i++) {
		if (curr1 == NULL)
			return -1;
		curr1 = curr1->next;
	}
	while (curr1 != NULL and curr2 != NULL) {
		if (curr1->val == curr2->val)
			return curr1->val;
		curr1 = curr1->next;
		curr2 = curr2->next;
	}
	return -1;
}
int getIntersection(ListNode* head1, ListNode* head2) {
	int c1 = count(head1);
	int c2 = count(head2);
	int d;
	if (c1 > c2 ) {
		d = c1 - c2;
		return _getIntersection(d, head1, head2);
	}
	else {
		d = c2 - c1;
		return _getIntersection(d, head2, head1);
	}
}
int main() {
	ListNode*n1 = NULL;
	ListNode*n2 = NULL;
	buildlist(n1);
	buildlist(n2);
	cout << getIntersection(n1, n2);
}