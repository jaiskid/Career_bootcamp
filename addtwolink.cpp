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
ListNode* addTwoNumber(ListNode	*l1, ListNode*l2) {
	stack<int> stk1, stk2;
	while (l1) {
		stk1.emplace(l1->val);
		l1 = l1->next;
	}
	while (l2) {
		stk2.emplace(l2->val);
		l2 = l2->next;
	}
	int sum = 0;
	ListNode*prev = NULL, *head = NULL;
	while (!stk1.empty() and !stk2.empty()) {
		sum /= 10;
		if (!stk1.empty()) {
			sum += stk1.top();
			stk1.pop();
		}
		if (!stk2.empty()) {
			sum += stk2.top();
			stk2.pop();
		}
		head = new ListNode(sum % 10);
		head->next = prev;
		prev = head;
	}
	if (sum >= 10) {
		head = new ListNode(sum / 10);
		head->next = prev;
	}
	return head;
}
int main() {
	ListNode*n1 = NULL;
	buildlist(n1);
	ListNode* n2 = NULL;
	buildlist(n2);
	ListNode* result = addTwoNumber(n1, n2);
	print(result);
}