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
vector<vector<int>> zigzaglevel(TreeNode* root) {
	if (root == NULL)
		return {};
	vector<vector<int>> zigzag;
	stack<TreeNode*> curr;
	stack<TreeNode*> next;
	next.emplace(root);
	while (!curr.empty() || !next.empty()) {
		if (curr.empty()) {
			swap(curr, next);
			zigzag.emplace_back();
		}
		TreeNode* temp = curr.top();
		curr.pop();
		zigzag.back().emplace_back(temp->val);
		auto left_child = (zigzag.size() % 2 == 0) ? temp->right : temp->left;
		auto right_child = (zigzag.size() % 2 == 0) ? temp->left : temp->right;
		if (left_child)  next.emplace(left_child);
		if (right_child)  next.emplace(right_child);
	}
	return zigzag;
}
int main() {
	TreeNode* root = tree_build("true");
	vector<vector<int>> result;
	result = zigzaglevel(root);
	for (int i = 0; i < result.size(); i++)
		for (int j = 0; j < result[i].size(); j++)
			cout << result[i][j] << " ";
}