// Given a binary tree, find next in-order node of a given node
// each node has link to its parent
#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

struct TreeNode {
	int data;
	TreeNode *l;
	TreeNode *r;

	TreeNode *parent;

	TreeNode(int d) : data(d) { l = NULL; r = NULL; parent = NULL; }
};


TreeNode* get_next(TreeNode *node) {
	TreeNode *res = NULL;
	if (node == NULL)
		return res;

	// if right child exists, just get right subtree's leftmost node
	if (node->r) {
		TreeNode *r = node->r;
		while (r) {
			if (r->l == NULL)
				break;
			else
				r = r->l;
		}
		res = r;
	}
	else if (!node->parent)
		res = node;
	else {
		TreeNode *p = node->parent;
		while (p && p->l != node) {
			node = p;
			p = p->parent;
		}
		res = p;
	}
	return res;
}


int main() {
	TreeNode n1(4);
	TreeNode n2(2);
	TreeNode n3(6);
	TreeNode n4(1);
	TreeNode n5(3);
	TreeNode n6(5);
	TreeNode n7(7);

	n1.l = &n2;	n2.parent = &n1;
	n1.r = &n3; n3.parent = &n1;
	n2.l = &n4; n4.parent = &n2;
	n2.r = &n5; n5.parent = &n2;
	n3.l = &n6; n6.parent = &n3;
	n3.r = &n7; n7.parent = &n3;

	TreeNode *node = get_next(&n3);
	if (!node)
		cout << "NULL" << endl;
	else
		cout << node->data << endl;
}

