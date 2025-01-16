class Solution:
    def intToRoman(self, num: int) -> str:
        d = {1: "I", 5: "V", 10: "X", 50: "L", 100: "C", 500: "D", 1000: "M"}
        subtractiveFour = {1: "IV", 2: "XL", 3: "CD"}
        subtractiveNine = {1: "IX", 2: "XC", 3: "CM"}
        subtractFive = {1: "V", 2: "L", 3: "D"}
        subtractOne = {1: "I", 2: "X", 3: "C", 4: "M"}
        roman = ""
        while num > 0:
            x = str(num)
            pwr10 = (10**(len(x)-1))
            if x[0] == "4":
                roman += subtractiveFour[len(x)]
                num -= pwr10 * 4
            elif x[0] == "9":
                roman += subtractiveNine[len(x)]
                num -= pwr10 * 9
            elif int(x[0]) >= 5:
                roman += subtractFive[len(x)]
                num -= pwr10 * 5
            else:
                roman += subtractOne[len(x)]
                num -= pwr10
        return roman





            