#include<bits/stdc++.h>
using namespace std;
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
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

void getverticalorder(TreeNode* root, int hd, map<int, vector<int>>&m) {
	if (!root)
		return;
	m[hd].push_back(root->val);
	getverticalorder(root->left, hd - 1, m);
	getverticalorder(root->right, hd + 1, m);
}
void printvertical(TreeNode* root) {
	map<int, vector<int>> m;
	int hd = 0;
	getverticalorder(root, hd, m);
	map<int, vector<int>> :: iterator it;
	for (it = m.begin(); it != m.end(); it++) {
		for (int i = 0; i < it->second.size(); ++i) {
			cout << it->second[i] << " ";
		}
		cout << endl;
	}
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
int main() {

	int n;
	cin >> n;
	TreeNode* root = tree_build();
	printvertical(root);
}