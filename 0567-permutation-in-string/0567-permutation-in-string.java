class Solution {
    public boolean checkEqual(int[] origPerm, int[] winString){
        for (int i=0; i<26; i++){
            if (origPerm[i] != winString[i]){
                return false;
            }
        }
        return true;
    }
    public boolean checkInclusion(String s1, String s2) {
        int[] permS1 = new int[26];
        int[] permS2 = new int[26];
        if (s1.length() > s2.length()){
            return false;
        }
        for (int i=0; i<s1.length(); i++){
            permS1[s1.charAt(i) - 'a'] += 1;
            permS2[s2.charAt(i) - 'a'] += 1;
        }
        int winSize = s1.length();
        for (int i=s1.length(); i<s2.length(); i++){
            if (checkEqual(permS1, permS2)){
                return true;
            }
            permS2[s2.charAt(i - winSize) - 'a'] -= 1;
            permS2[s2.charAt(i) - 'a'] += 1;
        }
        return checkEqual(permS1, permS2);


    }
}