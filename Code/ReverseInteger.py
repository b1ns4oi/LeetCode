class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        # TODO: overflow

        return int(str(x)[::-1])