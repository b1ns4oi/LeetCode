#include <iostream>
#include <string>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    int sumNumbers(TreeNode *root) {
        sum = 0;
        if(root != NULL)
        	foo(root, 0);
        return sum;
    }

private:
	int sum;
	void foo(TreeNode *p, int tmpsum) {
		//assume p is not NULL
		if(p->left == NULL && p->right == NULL) {
			sum += tmpsum*10 + p->val;
			return;
		}
		if(p->left != NULL)
			foo(p->left, tmpsum*10 + p->val);
		if(p->right != NULL)
			foo(p->right, tmpsum*10 + p->val);	
	}
};

int main()
{
	TreeNode t1(1);
	TreeNode t2(2);
	TreeNode t3(3);
	TreeNode t4(4);
	// t1.left = &t2;
	t1.right = &t3;
	t3.right = &t4;

	Solution s;
	cout << s.sumNumbers(&t1) << endl;
}










