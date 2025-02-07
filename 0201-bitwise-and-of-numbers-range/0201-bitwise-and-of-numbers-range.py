class Solution:
    def rangeBitwiseAnd(self, left: int, right: int) -> int:
        pwrTwo = 1
        total_bitcount = 0
        while pwrTwo <= right:
            total_bitcount += pwrTwo * (right // pwrTwo == left // pwrTwo) * (right % (2 * pwrTwo) // pwrTwo == 1)
            pwrTwo *= 2
        return total_bitcount
        