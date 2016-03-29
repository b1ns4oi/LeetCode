# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    # @param {TreeNode} root
    # @param {TreeNode} p
    # @param {TreeNode} q
    # @return {TreeNode}
    def lowestCommonAncestor(self, root, p, q):
       	if root is None or p is None or q is None:
       		return None

       	r1 = r2 = ret = root

       	while r1 is not p or r2 is not q:
       		if p.val < r1.val:
       			r1 = r1.left
       		elif p.val > r1.val:
       			r1 = r1.right

       		if q.val < r2.val:
       			r2 = r2.left
       		elif q.val > r2.val:
       			r2 = r2.right

       		if r1 is r2:
       			ret = r1
       		else:
       			break
       	return ret


if __name__ == '__main__':
	root = TreeNode(4)
	root.left = TreeNode(2)
	root.right = TreeNode(6)
	root.left.left = TreeNode(1)
	root.left.right = TreeNode(3)
	root.right.left = TreeNode(5)
	root.right.right = TreeNode(7)

	s = Solution()
	
	p = root.right.right
	q = root.right.right
	ret = s.lowestCommonAncestor(root, p, q)
	if ret is not None:
		print(ret.val)










