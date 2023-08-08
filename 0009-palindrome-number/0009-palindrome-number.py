class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        c = 0
        m = x
        if (x < 0):
            return False
        else:
            while x > 0:
                c *= 10
                c += x%10
                x = x // 10
            return m == c