class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string s = "";
        int pt1 = 0;
        int pt2 = 0;
        while (pt1 < word1.length() || pt2 < word2.length()){
            if (pt1 < word1.length() && pt2 < word2.length()){
                s += word1[pt1];
                s += word2[pt2];
                pt1++;
                pt2++;
            }

            else if (pt1 < word1.length()){
                s += word1[pt1];
                pt1++;
            }

            else {
                s += word2[pt2];
                pt2++;
            }
        }
        return s;
    }
};