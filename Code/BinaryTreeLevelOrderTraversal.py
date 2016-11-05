from collections import deque

class TreeNode(object):
    def __init__(self, val, left = None, right = None):
        self.val = val
        self.left = left
        self.right = right

    def __repr__(self):
        return str(self.val)

    __str__ = __repr__


def levelOrder(self, root):
    res = []

    if root is not None:
        q = deque([root])   # queue
        while q:
            n = len(q)
            row = []
            while n > 0:
                e = q.popleft()
                # print(str(e), end=' ')
                row.append(e.val)
                if e.left is not None:
                    q.append(e.left)
                if e.right is not None:
                    q.append(e.right)
                n -= 1
            res.append(row)
    return res

