#include <iostream>

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || !p || !q)
        	return NULL;

        if (root == p || root == q)
        	return root;

        bool is_p_in_left = cover(root->left, p);
        bool is_q_in_left = cover(root->left, q);

        if (is_q_in_left != is_p_in_left)
        	return root;
        return is_p_in_left ? lowestCommonAncestor(root->left, p, q) :
        	lowestCommonAncestor(root->right, p, q);
    }

    // if both 'p' and 'q' exist in tree, return their common ancestor
    // if 'p' exists in tree, but not 'q', return 'p'
    // if 'q' exists in tree, but not 'p', return 'q'
    // return NULL if 'p' and 'q' aren't in tree, or tree itself is NULL
    //
    // Attention : this solution makes assumption that both 'p' and 'q' SHOULD exist in tree
    TreeNode* lowestCommonAncestor2(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (!root)
			return NULL;
		if (root == p || root == q)
			return root;

		TreeNode *left = lowestCommonAncestor2(root->left, p, q);
		TreeNode *right = lowestCommonAncestor2(root->right, p, q);

		if (left && right)
			return root;

		return left ? left : right;
	｝

private:
	bool cover(TreeNode *root, TreeNode *p) {
		if (!root || !p)
			return false;
		if (root == p)
			return true;
		return cover(root->left, p) || cover(root->right, p);
	}
};