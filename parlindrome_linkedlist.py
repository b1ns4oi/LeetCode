# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    # @param {ListNode} head
    # @return {boolean}
    def isPalindrome(self, head):
        auxlist = []
        p = head
        while p is not None:
        	auxlist.append(p.val)
        	p = p.next
        # print(auxlist)

        return self.check(auxlist)

    def check(self, auxlist):
    	if not auxlist:
    		return True

    	for i in range(len(auxlist) // 2):
    		if auxlist[i] != auxlist[-1 * i - 1]:
    			 return False
    	return True

if __name__ == '__main__':
	h = ListNode(1)
	h.next = ListNode(1)
	# h.next.next = ListNode(2)
	# h.next.next.next = ListNode(1)
	# h.next.next.next.next = ListNode(1)

	s = Solution()
	print(s.isPalindrome(h))
