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
int depth(TreeNode*root) {
	if (root == NULL)
		return 0;
	int ls = depth(root->left);
	int rs = depth(root->right);
	return (ls, rs) + 1;
}
void kthlevel(TreeNode* root, int k) {
	if (root == NULL)
		return;
	if (k == 1)
		cout << root->val << " ";
	kthlevel(root->left, k - 1);
	kthlevel(root->right, k - 1);
}
void bfs(TreeNode*root) {
	if (root == NULL)
		return;
	queue<TreeNode*> q;
	q.push(root);
	q.push(NULL);
	while (!q.empty()) {
		TreeNode*f = q.front();
		if (f == NULL) {
			cout << endl;
			q.pop();
			if (!q.empty()) {
				q.push(NULL);
			}
		} else {
			cout << f->val << " ";
			q.pop();
			if (f->left) {
				q.push(f->left);
			}
			if (f->right) {
				q.push(f->right);
			}
		}

	}

}
TreeNode* createTreefrom(int *in, int *pre, int s, int e) {
	static int i = 0;
	//base case
	if (s > e) {
		return NULL;
	}
	TreeNode *root = new TreeNode(pre[i]);
	int index = -1;
	for (int j = s; j <= e; j++) {
		if (in[j] == pre[i]) {
			index = j;
			break;
		}
	}
	i++;
	root->left = createTreefrom(in, pre, s, index - 1);
	root->right = createTreefrom(in, pre, index + 1, e);
	return root;
}
int main() {
	int in[] = {3, 2, 8, 4, 1, 6, 7, 5};
	int pre[] = {1, 2, 3, 4, 8, 5, 6, 7};
	int n = sizeof(in) / sizeof(int);
	TreeNode* root = createTreefrom(in, pre, 0, n - 1);
	//kthlevel(root, 3);
	/*int h = depth(root);
	for (int i = 1; i <= h; i++) {
		kthlevel(root, i);
		cout << endl;
	}
	*/
	bfs(root);
}