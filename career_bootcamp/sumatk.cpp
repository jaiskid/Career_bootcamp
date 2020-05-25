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
int sum = 0;
void traverse(TreeNode*root, int k) {
	if (root == NULL) {
		return;
	}
	if (k == 0) {
		sum += root->val;
		return;
	}
	traverse(root->left, k - 1);
	traverse(root->right, k - 1);
}
int main() {
	TreeNode* root = tree_build(root);
	int k;
	cin >> k;
	traverse(root, k);
	cout << sum << " ";
}