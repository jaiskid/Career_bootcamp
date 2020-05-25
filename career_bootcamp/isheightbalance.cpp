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
		TreeNode* root = new TreeNode(d);
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
class hbpair {
public:
	int height;
	bool balance;
};
hbpair isheight(TreeNode* root) {
	hbpair p;
	if (root == NULL)
	{
		p.height = 0;
		p.balance = true;
		return p;
	}
	//recursive case
	hbpair left = isheight(root->left);
	hbpair right = isheight(root->right);
	p.height = max(left.height, right.height) + 1;
	if (abs(left.height - right.height) <= 1 and left.balance and right.balance) {
		p.balance = true;
	} else {
		p.balance = false;
	}
	return p;
}
int main() {
	TreeNode* root = tree_build("true");
	if (isheight(root).balance) {
		cout << "true" << "\n";
	} else {
		cout << "false" << "\n";
	}
}