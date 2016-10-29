#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
#include <list>
#include <limits>

using namespace std;

struct Node {
	int data;
	Node *left;
	Node *right;

	Node(int d) : data(d) { left = NULL; right = NULL; }
};

void download(Node *root, vector<int>& v) {
    if (root == NULL) return;
    download(root->left, v);
    v.push_back(root->data);
    download(root->right, v);
}

// save all node value into vector, than check if sorted
// this only works if there's no duplicate nodes in the tree
bool checkBST1(Node* root) {
    vector<int> v;
    download(root, v);
    for (int i = 0; i < v.size()-1; ++i)
        if (v[i] > v[i+1])
            return false;
    return true;
}


// each time during recursion, min/max will be updated to respective value for the given tree at 'root'
bool checkBST2_recur(Node *root, int& min, int& max) {
	if (root == NULL)
		return true;

	int l_min, l_max, r_min, r_max;
	bool res = true;

	bool l_valid = checkBST2_recur(root->left, l_min, l_max);
	bool r_valid = checkBST2_recur(root->right, r_min, r_max);
	if (!l_valid || !r_valid)
		return false;

	min = root->left ? l_min : root->data;
	max = root->right ? r_max : root->data;
	return (root->left ? root->data >= l_max : true) && (root->right ? root->data <= r_min : true);
}

bool checkBST2(Node* root) {
	int min, max;
	return checkBST2_recur(root, min, max);
}


// Referenced from <Cracking the coding interview>
bool checkBST3_recur(Node *root, int& min, int& max) {
	if (root == NULL)	return true;
	if (root->data <= min || root->data > max)	return false;

	return checkBST3_recur(root->left, min, root->data) &&
		checkBST3_recur(root->right, root->data, max);
}

bool checkBST3(Node* root) {
	int min = INT_MIN, max = INT_MAX;
	return checkBST3_recur(root, min, max);
}

int main() {
	Node n1(2);
	Node n2(1);
	Node n3(3);
	n1.left = &n2;
	n1.right = &n3;
	cout << checkBST3(&n1) << endl;
}