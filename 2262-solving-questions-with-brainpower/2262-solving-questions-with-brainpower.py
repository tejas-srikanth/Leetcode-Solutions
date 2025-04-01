class Solution:
    def mostPoints(self, questions: List[List[int]]) -> int:
        dp = [0 for i in questions]
        dp[-1] = questions[-1][0]
        for i in range(len(dp)-2, -1, -1):
            q = questions[i]
            p, b = q[0], q[1]
            if i + b + 1 >= len(dp):
                dp[i] = max(p, dp[i + 1])
            else:
                dp[i] = max(p + dp[i + b + 1], dp[i + 1])
        return dp[0]
        