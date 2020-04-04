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
class solution {
	vector<int> v;
	int max_level = -1;
public:
	void helper(TreeNode* root, int level) {
		if (root == NULL)
			return ;
		if (level > max_level) {
			max_level = level;
			v.push_back(root->val);
		}
		helper(root->right, level + 1);
		helper(root->left, level + 1);
	}
	vector<int> rightView(TreeNode* root) {
		helper(root, 0);
		return v;
	}
};
int main() {
	TreeNode* root = tree_build();
	//print(root);
	cout << endl;
	solution s;
	vector<int> res = s.rightView(root);
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << " ";

}