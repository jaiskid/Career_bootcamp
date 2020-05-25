#include<bits/stdc++.h>
using namespace std;
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
TreeNode* tree_build(string s) {
	if (s == "true") {
		int d;
		cin >> d;
		TreeNode *root = new TreeNode(d);
		string l;
		cin >> l;
		if (l == "true") {
			root->left = tree_build(l);
		}
		string r;
		cin >> r;
		if (r == "true") {
			root->right = tree_build(r);
		}
		return root;
	}
	return NULL;
}
bool isSame(TreeNode* p, TreeNode* q) {
	if (!p and !q )
		return true;
	return p and q  and isSame(p->left, q->left) and isSame(p->right, q->right);
}
int main() {
	TreeNode* root1 = tree_build("true");
	TreeNode* root2 = tree_build("true");
	(isSame(root1, root2) == 1) ? cout << "true" : cout << "false";
}