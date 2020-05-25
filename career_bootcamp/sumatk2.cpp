#include<bits/stdc++.h>
using namespace std;
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* tree_build(TreeNode* root) {
	int d, n;
	cin >> d >> n;
	root = new TreeNode(d);
	if (n == 0) {
		return root;
	}
	if (n == 1) {
		root->left = tree_build(root->left);
		return root;
	}
	else {
		root->left = tree_build(root->left);
		root->right = tree_build(root->right);
		return root;
	}
}
int sumofnodes(TreeNode* root, int k) {
	if (root == NULL) {
		return 0;
	}
	queue<TreeNode*> que;
	int flag = 0;
	int level = 0;
	int sum = 0;
	que.push(root);
	while (!que.empty()) {
		int size = que.size();
		while (size--) {
			TreeNode* f = que.front();
			que.pop();
			if (level == k) {
				sum += f->val;
			} else {
				if (f->left) {
					que.push(f->left);
				}
				if (f->right) {
					que.push(f->right);
				}
			}
		}
		level++;
		if (flag == 1)
			break;
	}
	return sum;
}

int main() {
	TreeNode* root = tree_build(root);
	int k;
	cin >> k;

	cout << sumofnodes(root, k);
}