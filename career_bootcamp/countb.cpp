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
	return max(ls, rs) + 1;
}
void kthlevel(TreeNode* root, int k) {
	if (root == NULL)
		return;
	if (k == 1)
		cout << root->val << " ";
	kthlevel(root->left, k - 1);
	kthlevel(root->right, k - 1);
}
TreeNode* buildfromArr(int *a, int s, int e) {
	if (s > e) {
		return NULL;
	}
	int mid = (s + e) / 2;
	TreeNode* root = new TreeNode(a[mid]);
	root->left = buildfromArr(a, s, mid - 1);
	root->right = buildfromArr(a, mid + 1, e);
	return root;
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
int count(TreeNode*root) {
	int counter = 1;
	if (root == NULL)
		return 0;
	counter += count(root->left);
	counter += count(root->right);
	return counter;
}
int sum_node(TreeNode*root) {
	if (root == NULL)
		return 0;

	return (root->val + sum_node(root->left) +
	        sum_node(root->right));
}
//Diameter is all about max count of number edge in between two nodes
int diameter(TreeNode* root) {
	if (root == NULL)
		return	0;
	int h1 = depth(root->left);
	int h2 = depth(root->right);
	//if it passes through root
	int op1 = h1 + h2;
	//if lies in the 1st part
	int op2 = diameter(root->left);
	int op3 = diameter(root->right);
	return max(op1, max(op2, op3));
}
//fast method for diameter
class Pair {
public:
	int height;
	int diameter;
};

Pair fastDiameter(TreeNode*root) {
	Pair p;
	if (root == NULL) {
		p.diameter = p.height = 0;
		return p;
	}
	//Otherwise
	Pair left = fastDiameter(root->left);
	Pair right = fastDiameter(root->right);

	p.height = max(left.height, right.height) + 1;
	p.diameter = max(left.height + right.height, max(left.diameter, right.diameter));
	return p;
}
int replaceNode(TreeNode* root) {
	if (root == NULL) {
		return 0;
	}
	if (root->left == NULL and root->right == NULL) {
		return root->val;
	}
	int leftSum = replaceNode(root->left);
	int rightSum = replaceNode(root->right);
	int temp = root->val;
	root->val = leftSum + rightSum;
	return temp + root->val;
}
class HBPair {
public:
	int height;
	bool balance;
};

HBPair isHeightBalance(TreeNode *root) {
	HBPair p;
	if (root == NULL) {
		p.height = 0;
		p.balance = true;
		return p;
	}
	//Recurisve Case
	HBPair left = isHeightBalance(root->left);
	HBPair right = isHeightBalance(root->right);

	p.height = max(left.height, right.height) + 1;

	if (abs(left.height - right.height) <= 1 && left.balance && right.balance) {
		p.balance = true;
	}
	else {
		p.balance = false;
	}
	return p;
}
int main() {

	//TreeNode* root = tree_build();
	//kthlevel(root, 3);
	/*int h = depth(root);
	for (int i = 1; i <= h; i++) {
		kthlevel(root, i);
		cout << endl;
	}
	*/
	/*
	cout << count(root);
	cout << endl;
	cout << sum_node(root);
	cout << endl;
	cout << depth(root);
	cout << endl;
	cout << diameter(root);
	cout << endl;
	bfs(root);
	//cout << endl;
	//Pair p = fastDiameter(root);
	//cout << p.height << endl;
	//cout << p.diameter << endl;
	cout << endl;
	replaceNode(root);
	bfs(root);
	if (isHeightBalance(root).balance) {
		cout << "Balanced";
	}
	else {
		cout << "Not a Balanced Tree" << endl;
	}
	*/
	int n;
	cin >> n;
	int a[100];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	TreeNode* root = buildfromArr(a, 0, n - 1);
	bfs(root);
}