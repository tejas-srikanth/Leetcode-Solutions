class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        lstS = list(s)
        lstP = []
        for i in range(len(p)):
            if p[i] == "*":
                x = lstP.pop()
                lstP.append(x + "*")
            else:
                lstP.append(p[i])
        dp = [[False for i in range(len(lstS) + 1)] for j in range(len(lstP) + 1)]
        dp[0][0] = True
        for i in range(1, len(lstP) + 1):
            for j in range(len(lstS) + 1):
                if j == 0:
                    if dp[i-1][0] and len(lstP[i-1]) == 2:
                        dp[i][0] = True
                    else:
                        dp[i][0] = False
                else:
                    if len(lstP[i-1]) == 1 and lstP[i-1] != ".":
                        dp[i][j] = dp[i-1][j-1] and lstP[i-1] == lstS[j-1]
                    elif len(lstP[i-1]) == 1 and lstP[i-1] == ".":
                        dp[i][j] = dp[i-1][j-1]
                    else:
                        if lstP[i-1][0] == ".":
                            dp[i][j] = dp[i-1][j-1] or dp[i-1][j] or dp[i][j-1]
                        else:
                            letter = lstP[i-1][0]
                            dp[i][j] = (dp[i-1][j-1] and s[j-1] == letter) or \
                                       (dp[i-1][j]) or \
                                       (dp[i][j-1] and s[j-1] == letter)
        return dp[-1][-1]
        