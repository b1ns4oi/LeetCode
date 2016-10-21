#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

struct TreeNode {
 	int val;
 	TreeNode *left;
 	TreeNode *right;
 	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;

        if (root == NULL)
        	return sum;
        sumOfLeftLeaves_recur(root, sum);
        return sum;
    }
private:
	void sumOfLeftLeaves_recur(TreeNode* root, int& sum) {
		if (root->left) {
			if (!root->left->left && !root->left->right)
				sum += root->left->val;
			else
				sumOfLeftLeaves_recur(root->left, sum);
		}

		if (root->right)
			sumOfLeftLeaves_recur(root->right, sum);
	}
};

int main() {
	Solution sol;
	TreeNode t1(3);
	TreeNode t2(9);
	TreeNode t3(20);
	TreeNode t4(15);
	TreeNode t5(7);
	TreeNode t6(1);
	TreeNode t7(2);

	t1.left = &t2;
	t1.right = &t3;

	t2.left = &t6;
	t2.right = &t7;

	t3.left = &t4;
	t3.right = &t5;

	cout << sol.sumOfLeftLeaves(&t1) << endl;; 
}
