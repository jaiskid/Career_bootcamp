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
ListNode* appendk(ListNode*head, int k, int n) {
	ListNode*last;
	last = head;
	// node*temp=head;
	ListNode*temp2 = head;
	//All initialized to head
	int i = 0;
	k = k % n;
	//if k is greater than n then - value
	int ok = n - k - 1;
	// 4 in this case
	if (k == 0 || k < 0) {
		return head;
	}

	while (last != NULL && i < ok) {
		last = last -> next;
		i++;
	}
	temp2 = last;
	ListNode*second = temp2->next;
	ListNode*third = second;
	temp2->next = NULL;
	while (second->next != NULL) {
		second = second->next;
	}
	second->next = head;
	last->next = NULL;
	return third;
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
int main() {
	ListNode*n1 = NULL;
	buildlist(n1);
	//print(n1);
	//cout << endl;
	int k;
	cin >> k;
	int n = count(n1);
	ListNode* node = appendk(n1, k, n);
	print(node);
}