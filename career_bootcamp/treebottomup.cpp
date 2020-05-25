#include<bits/stdc++.h>
using namespace std;
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	int hd;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
/*
vector<int> inorderTraversal(TreeNode*root) {
	stack<TreeNode*>s;
	TreeNode *curr = root;
	vector<int> res;
	while (curr != NULL || s.empty() == false) {
		while (curr != NULL) {
			s.push(curr);
			curr = curr->left;
		}
		curr = s.top();
		s.pop();
		res.emplace_back(curr->val);
		curr = curr->right;
	}
	return res;
}
*/
void print(TreeNode* root) {
	if (root == NULL) {
		return;
	}
	cout << root->val << " ";
	print(root->left);
	print(root->right);
}
TreeNode* tree_build() {
	int d;
	cin >> d;
	TreeNode* root = new TreeNode(d);
	queue<TreeNode*> q;
	q.push(root);
	while (!q.empty()) {
		TreeNode*f = q.front();
		q.pop();
		int c1, c2;
		cin >> c1 >> c2;
		if (c1 != -1) {
			f->left = new TreeNode(c1);
			q.push(f->left);
		}
		if (c2 != -1) {
			f->right = new TreeNode(c2);
			q.push(f->right);
		}

	}
	return root;
}
/*
TreeNode* tree_build() {
	int x;
	cin >> x;
	if (x == -1) {
		return NULL;
	}
	TreeNode* curr = new TreeNode(x);
	curr->left = tree_build();
	curr->right = tree_build();
	return curr;
}
*/
void bottomup(TreeNode* root ) {
	if (root == NULL) {
		return;
	}
	int hd = 0;

	queue<TreeNode*> q;
	map<int, int> m;

	root->hd = hd;
	q.push(root);
	while (!q.empty()) {
		TreeNode* temp = q.front();
		q.pop();
		hd = temp->hd;
		m[hd] = temp->val;
		if (temp->left != NULL) {
			temp->left->hd = hd - 1;
			q.push(temp->left);
		}
		if (temp->right != NULL)
		{
			temp->right->hd = hd + 1;
			q.push(temp->right);
		}
	}
	for (auto i = m.begin(); i != m.end(); ++i) {
		cout << i->second << " ";
	}
}
int main() {
	TreeNode* root = tree_build();
	//print(root);
	bottomup(root);
}