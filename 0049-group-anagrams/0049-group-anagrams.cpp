class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> um;
        for (string st: strs){
            string x = st;
            sort(st.begin(), st.end());
            if (um.find(st) != um.end()){
                um[st].push_back(x);
            } else {
                um[st] = {x};
            }
        }
        vector<vector<string>> res;
        for (auto it = um.begin(); it != um.end(); it++){
            vector<string> anagrams;
            for (string k: it->second){
                anagrams.push_back(k);
            }
            res.push_back(anagrams);
        }
        return res;
    }
};