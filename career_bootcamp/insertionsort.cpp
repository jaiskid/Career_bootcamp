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
ListNode *insertProperly( ListNode *head , ListNode *temp )
{
	if ( head == NULL || head -> val >= temp -> val )
	{
		temp -> next = head;
		return temp;
	}

	ListNode *parse = head;

	while ( head -> next != NULL && head -> next -> val < temp -> val  )
	{
		head = head -> next;
	}

	temp -> next = head -> next;
	head -> next = temp;

	return parse;
}

ListNode *insertionSort( ListNode *temp )
{
	ListNode *sorted = NULL;

	while ( temp != NULL )
	{
		ListNode *temp2 = temp -> next;
		sorted = insertProperly( sorted , temp );
		temp = temp2;
	}

	return sorted;
}
int main() {
	ListNode*n1 = NULL;
	buildlist(n1);
	n1 = insertionSort(n1);
	print(n1);

}