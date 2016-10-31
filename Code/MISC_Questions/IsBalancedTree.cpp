// Check if a binary tree is balanced
// A binary tree is balanced if height diff of all left/right subtrees <= 1
#include <iostream>
#include <algorithm>

using namespace std;

struct TreeNode {
	int data;
	TreeNode *l;
	TreeNode *r;

	TreeNode(int d) : data(d) { l = NULL; r = NULL; }
};

int get_height(TreeNode *root) {
	if (!root)
		return 0;
	return 1 + std::max(get_height(root->l), get_height(root->r));
}

// solved by definition
// O(N^2) where 'N' is number of nodes
bool isBlanced(TreeNode *root) {
	if (!root)
		return true;

	int l_height = get_height(root->l);
	int r_height = get_height(root->r);
	if (abs(l_height - r_height) > 1)
		return false;

	return isBlanced(root->l) && isBlanced(root->r);
}

// check if balanced while compute height
// O(N)
int check_height(TreeNode *root) {
	if (!root)
		return 0;

	int l_height = get_height(root->l);
	if (l_height == -1)
		return -1;

	int r_height = get_height(root->r);
	if (r_height == -1)
		return -1;

	if (abs(l_height - r_height) > 1)
		return -1;

	return 1 + std::max(l_height, r_height);
}

int isBlanced_2(TreeNode *root) {
	return check_height(root) != -1;
}


int main() {
	TreeNode n1(1);
	TreeNode n2(1);
	TreeNode n3(1);

	n1.l = &n2;
	n2.r = &n3;

	cout << isBlanced(&n1) << endl;
	cout << isBlanced_2(&n1) << endl;
}