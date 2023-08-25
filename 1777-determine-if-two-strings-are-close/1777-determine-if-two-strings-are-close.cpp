class Solution {
public:
    unordered_map<int, vector<char>> invertmap(unordered_map<char, int>& g){
        unordered_map<int, vector<char>> q;
        for (auto p: g){
            q[p.second].push_back(p.first);
        }
        return q;
    }
    bool closeStrings(string word1, string word2) {
        vector<int> m1(26, 0), m2(26, 0);
        for (char s: word1){
            m1[s - 'a']++;
        }
        for (char s: word2){
            m2[s - 'a']++;
        }
        for (int i=0; i<26; ++i){
            if (!m1[i] && m2[i]){
                return false;
            } else if (m2[i] && !m1[i]){
                return false;
            }
        }
        sort(m1.begin(), m1.end());
        sort(m2.begin(), m2.end());
        return m1 == m2;

    }
};