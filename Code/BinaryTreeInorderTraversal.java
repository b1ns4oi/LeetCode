import java.util.*;

class TreeNode {
 	int val;
 	TreeNode left;
 	TreeNode right;
 	TreeNode(int x) { val = x; }
}

public class Solution {
    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> res = new ArrayList<Integer>();
        inorderTraversalRecur(root, res);
        return res;
    }

    private void inorderTraversalRecur(TreeNode root, List<Integer> res) {
    	if (root == null)
    		return;
    	inorderTraversalRecur(root.left, res);
    	res.add(root.val);
    	inorderTraversalRecur(root.right, res);
    }
}