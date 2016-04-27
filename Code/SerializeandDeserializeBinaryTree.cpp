// Reference: https://leetcode.com/discuss/66147/recursive-preorder-python-and-c-o-n

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <climits>
#include <sstream>

using namespace std;

struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


/*********  construct binary tree based on vector of integers *********/
TreeNode* constructor_helper(vector<int> &nums, int start) {
    if (start >= nums.size() || nums[start] == INT_MIN)
        return NULL;
    TreeNode *node = new TreeNode(nums[start]);
    node->left = constructor_helper(nums, start*2);
    node->right = constructor_helper(nums, start*2+1);
    return node;
}

// nums is 1-based
TreeNode* construct(vector<int> &nums) {
    if (nums.size() <= 1)
        return NULL;
    return constructor_helper(nums, 1);
}
/************************************************************************/

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ret;
        ostringstream os(ret);
        serialize_helper(root, os);
        return os.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream is(data);
        return deserialize_helper(is);
    }

private:
    void serialize_helper(TreeNode *root, ostringstream& os) {
        if (root == NULL) {
            os << "# ";
            return;
        }
        os << root->val << " ";
        serialize_helper(root->left, os);
        serialize_helper(root->right, os);
    }

    TreeNode* deserialize_helper(istringstream& is) {
        string s;
        is >> s;
        if (s == "#")
            return NULL;
        TreeNode *node = new TreeNode(stoi(s));
        node->left = deserialize_helper(is);
        node->right = deserialize_helper(is);
        return node;
    }
};

int main(int argc, char *argv[])
{
    Codec sol;
    vector<int> nums = {INT_MIN, 1, 2, 3, 4, 5, 6, 7, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, 8, 9};
    TreeNode *head = construct(nums);
    string result = sol.serialize(head);
    cout << result << endl;
}













