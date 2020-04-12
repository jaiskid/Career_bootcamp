#include<bits/stdc++.h>
using namespace std;
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
TreeNode* helper(vector<int>&pre, vector<int>&in, int s, int e, int i) {
	if (s > e or i < 0 ) {
		return NULL;
	}
	TreeNode* root = new TreeNode(pre[i]);
	int index = -1;
	for (int j = s; j <= e; j++) {
		if (in[j] == pre[i]) {
			index = j;
			break;
		}
	}
	root->left = helper(pre, in, s, index - 1, i + 1);
	root->right = helper(pre, in, index + 1, e, i + index - s + 1);
	return root;
}
TreeNode *buildTree(vector<int>&pre, vector<int>&in) {
	if (pre.size() == 0)
		return NULL;
	int s = 0;
	int e = pre.size() - 1;
	return helper(pre, in, s, e, 0);
}
/*
void print(TreeNode *root) {
	if (root == NULL) {
		return;
	}
	if (root->left != NULL && root->right != NULL) {
		cout << root->left->val << " => " << root->val << " <= " << root->right->val << endl;
	}
	if (root->left == NULL && root->right == NULL) {
		cout << "END => " << root->val << " <= END" << endl;
	}
	if (root->left == NULL && root->right != NULL) {
		cout << "END => " << root->val << " <= " << root->right->val << endl;
	}
	if (root->right == NULL && root->left != NULL) {
		cout << root->left->val << " => " << root->val << " <= END" << endl;
	}
	print(root->left);
	print(root->right);

}
*/
bool isbst(TreeNode* root, int minV = INT_MIN, int maxV = INT_MAX) {
	if (!root)
		return true;
	if (root->val >= minV and root->val <= maxV and isbst(root->left, minV, root->val) and isbst(root->right, root->val, maxV)) {
		return true;
	}
	return false;
}
int count(TreeNode* root) {
	if (!root)
		return 0;
	return 1 + count(root->left) + count(root->right);
}
int sizeofmaxbst(TreeNode* root) {
	int maxsize = 0;
	if (root == NULL)
		return 0;
	if (isbst(root)) {
		maxsize = max(maxsize, count(root));
	}
	return max(maxsize, max(sizeofmaxbst(root->left), sizeofmaxbst(root->right)));
}
int main() {
	int n;
	cin >> n;
	vector<int>pre;
	pre.resize(n);
	for (int i = 0; i < n; i++)
		cin >> pre[i];
	vector<int> in;
	in.resize(m);
	for (int i = 0; i < m; i++)
		cin >> in[i];
	TreeNode* root = buildTree(pre, in);
	cout << sizeofmaxbst(root);
}
