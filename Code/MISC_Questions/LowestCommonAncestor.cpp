// Given a binary tree, find first common ancestor of two nodes
// Attention, this is NOT a binary search tree
// No parent link provided with each node
#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

struct TreeNode {
	int data;
	TreeNode *l;
	TreeNode *r;

	TreeNode(int d) : data(d) { l = NULL; r = NULL; }
};

// O(n) for covers()
bool covers(TreeNode *root, TreeNode *p) {
	if (root == NULL)
		return false;
	if (root == p)
		return true;

	return covers(root->l, p) || covers(root->r, p);
}




////////////////////////////////////////////////////////////////////////////////////////////////
TreeNode* common_ancestor4_helper(TreeNode *root, TreeNode *n1, TreeNode *n2, bool& v1, bool& v2) {
	// implementation is pretty much like common_ancestor3(), plus some set work of v1 and v2
	if (!root)	return NULL;
	if (root == n1) {
		v1 = true;	// we have seen n1, so set v1 to true
		return root;
	}
	if (root == n2) {
		v2 = true;
		return root;
	}

	TreeNode *in_left = common_ancestor4_helper(root->l, n1, n2, v1, v2);
	TreeNode *in_right = common_ancestor4_helper(root->r, n1, n2, v1, v2);

	if (in_left && in_right)
		return root;
	return in_left ? in_left : in_right;
}
//
//  Time complexity: O(n)
//  if v1 and v2 don't get set when doing traversal, covers() will be called
//  each covers() will be O(n)
//  
//  这个方法的复杂度应该也不见得比common_ancestor2() 好多少，取决于实际n1/n2 分布来决定是否需要最终两次covers() 的调用
//  不过相对于common_ancestor3() 的优点是：解决了如果n1/n2 不存在，会直接返回NULL, 这显然更合理。
//  
TreeNode* common_ancestor4(TreeNode *root, TreeNode *n1, TreeNode *n2) {
	bool v1 = false, v2 = false;   // used to indicate whether n1/n2 exist in tree when do traversal

	TreeNode *res = common_ancestor4_helper(root, n1, n2, v1, v2);
	// only return 'res' when both n1 and n2 exist
	// because v1 and v2 are not guaranteed to be set during traversal, and if not, covers() will help us
	if ((v1 && v2) || (v1 && covers(root, n2)) || (v2 && covers(root, n1)))
		return res;
	return NULL;
}
////////////////////////////////////////////////////////////////////////////////////////////////





////////////////////////////////////////////////////////////////////////////////////////////////
// if n1 exists in tree, n2 not, then return n1
// if n2 exists in tree, n1 not, then return n2
// if both n1 and n2 exist in tree, return their common ancestor
// if none of them exists in tree, return NULL
//
// Given the above function description, common_ancestor3 only works if both n1/n2 exist in tree
// If one of them doesn't exist, this function return another node, but it's reasonable to return NULL
// common_ancestor4() will fix this
//
// Time complexity: O(n)
//
// Although common_ancestor2() is O(n), but common_ancestor3() should be faster, because it takes only
// one time traversal of all nodes while common_ancestor2() takes more than two times.
//
TreeNode* common_ancestor3(TreeNode *root, TreeNode *n1, TreeNode *n2) {
	if (root == NULL)
		return NULL;

	if (root == n1 || root == n2)
		return root;

	TreeNode *in_left = common_ancestor3(root->l, n1, n2);
	TreeNode *in_right = common_ancestor3(root->r, n1, n2);

	if (in_left && in_right)
		return root;
	return in_left != NULL ? in_left : in_right;
}
////////////////////////////////////////////////////////////////////////////////////////////////




////////////////////////////////////////////////////////////////////////////////////////////////
// Reference: http://www.geeksforgeeks.org/lowest-common-ancestor-binary-tree-set-1 ////////////
//
// Time complexity for find_path() is O(n)
bool find_path(TreeNode *root, TreeNode *p, vector<TreeNode*>& v) {
	if (!root)
		return false;

	v.push_back(root);
	if (root == p)
		return true;

	if ((root->l && find_path(root->l, p, v)) || (root->r && find_path(root->r, p, v)))
		return true;

	v.pop_back();
	return false;
}
// common_ancestor2() consists of 2 find_path() and compare the paths result
// Time Complexity: O(n)
//
TreeNode* common_ancestor2(TreeNode *root, TreeNode *n1, TreeNode *n2) {
	// find path from root to n1 and n2 respectively
	vector<TreeNode*> path1, path2;
	bool existed1 = find_path(root, n1, path1);
	bool existed2 = find_path(root, n2, path2);

	if (!existed1 || !existed2)
		return NULL;	// n1 or n2 might not exist in tree

	int n = std::min(path1.size(), path2.size());
	int i;

	for (i = 0; i < n; ++i) {
		if (path1[i] != path2[i])
			break;
	}
	return path1[i-1];
}
////////////////////////////////////////////////////////////////////////////////////////////




//////////////////////////////////////////////////////////////////////////////////////
////// refer to <Cracking the coding interview> chapter 4  ///////////////////////////
// 
// Worst performance for common_ancestor1 is O(n) = n + n/2 + n/4 + n/8 + ...
TreeNode* common_ancestor1(TreeNode *root, TreeNode *n1, TreeNode *n2) {
	if (root == NULL)
		return NULL;

	if (root == n1 || root == n2)
		return root;

	if (covers(root->l, n1)) {
		if (covers(root->r, n2))
			return root;
		else
			return common_ancestor1(root->l, n1, n2);
	}
	else if (covers(root->l, n2))
		return root;
	else
		return common_ancestor1(root->r, n1, n2);
}
/////////////////////////////////////////////////////////////////////////////////////



int main() {
	TreeNode n1(4);
	TreeNode n2(2);
	TreeNode n3(6);
	TreeNode n4(1);
	TreeNode n5(3);
	TreeNode n6(5);
	TreeNode n7(7);

	n1.l = &n2;	
	n1.r = &n3; 
	n2.l = &n4; 
	n2.r = &n5; 
	n3.l = &n6; 
	n3.r = &n7; 

	TreeNode *node = common_ancestor2(&n1, &n6, &n2);
	if (node != NULL)
		cout << node->data << endl;
}

