/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root)
            return 0;
        int min_l = minDepth(root->left);
        int min_r = minDepth(root->right);
        
        int min;
        if (min_l == 0)
            min = min_r;
        else if (min_r == 0)
            min = min_l;
        else
            min = std::min(min_l, min_r);
        return min + 1;
    }
};