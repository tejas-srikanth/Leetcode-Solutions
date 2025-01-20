class Solution {
    public String longestPalindrome(String s) {
        int bestWindow = 1;
        int winZero = 0;
        for (int i=0; i<s.length(); i++){
            int j = i-1;
            int k = i + (i - j);
            while (j >= 0 && k < s.length() && s.charAt(j) == s.charAt(k)){
                int currWindow = k - j + 1;
                bestWindow = Math.max(bestWindow, currWindow);
                if (bestWindow == currWindow){
                    winZero = j;
                }
                j -= 1;
                k += 1;
            }
        }

        for (int i=0; i<s.length()-1; i++){
            int j = i+1;
            int k = i;
            while (k >= 0 && j < s.length() && s.charAt(k) == s.charAt(j)){
                int currWindow = j - k + 1;
                bestWindow = Math.max(bestWindow, currWindow);
                if (bestWindow == currWindow){
                    winZero = k;
                }
                j += 1;
                k -= 1;
            }
        }
        return s.substring(winZero, winZero + bestWindow);
    }
}