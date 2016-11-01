// convert binary tree to linked-list of each level
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <queue>

using namespace std;

struct TreeNode {
	int data;
	TreeNode *l;
	TreeNode *r;

	TreeNode(int d) : data(d) { l = NULL; r = NULL; }
};


void convert_to_list_DFS_helper(TreeNode *root, vector<list<TreeNode*> >& res, int level) {
	if (!root)
		return;

	if (res.size() == level) {
		list<TreeNode*> l;
		l.push_back(root);
		res.push_back(l);
	}
	else
		res[level].push_back(root);

	convert_to_list_DFS_helper(root->l, res, level+1);
	convert_to_list_DFS_helper(root->r, res, level+1);
}

// DFS
vector<list<TreeNode*> > convert_to_list_DFS(TreeNode *root) {
	vector<list<TreeNode*> > v;
	convert_to_list_DFS_helper(root, v, 0);
	return v;
}


// BFS
vector<list<TreeNode*> > convert_to_list_BFS(TreeNode *root) {
	vector<list<TreeNode*> > v;
	if (!root)
		return v;

	int n;
	queue<TreeNode*> q;
	q.push(root);
	list<TreeNode*> lis;

	for (n = 1; !q.empty(); ) {
		TreeNode *node = q.front();
		q.pop();
		lis.push_back(node);

		if (node->l)
			q.push(node->l);
		if (node->r)
			q.push(node->r);

		if (--n == 0) {
			v.push_back(lis);
			lis.clear();
			n = q.size();	// 'n' is used to control end point at each level
		}
	}
	return v;
}


int main() {
	TreeNode n1(1);
	TreeNode n2(2);
	TreeNode n3(3);
	TreeNode n4(4);
	TreeNode n5(5);
	TreeNode n6(6);
	TreeNode n7(7);

	n1.l = &n2;
	n1.r = &n3;
	n2.l = &n4;
	n2.r = &n5;
	n3.l = &n6;
	n3.r = &n7;

	vector<list<TreeNode*> > v = convert_to_list_DFS(&n1);

	cout << v.size() << endl;

	for (int i = 0; i < v.size(); ++i) {

		for (list<TreeNode*>::iterator it = v[i].begin(); it != v[i].end(); ++it) {
			cout << (*it)->data << " ";
		}
		cout << endl;
	}
}

