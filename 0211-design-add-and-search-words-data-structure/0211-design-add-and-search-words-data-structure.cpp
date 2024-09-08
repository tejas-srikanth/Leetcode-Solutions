class TrieNode {
    public:
    vector<TrieNode*> children;
    TrieNode(): children(27, nullptr){};
};

class WordDictionary {
public:
    TrieNode* root;
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* curr = root;
        for (char c: word){
            if (!curr->children[c - 'a']){
                curr->children[c - 'a'] = new TrieNode();
            }
            curr = curr->children[c - 'a'];
        }
        curr->children[26] = new TrieNode();
    }

    bool helper(string word, TrieNode* curr){
        if (!curr){
            return false;
        }
        if (word.length() == 0){
            return curr->children[26];
        }
        char c = word[0];
            if (c == '.'){
                bool fin = false;
                for (int i=0; i<26; ++i){
                    
                    fin = fin || helper(word.substr(1, word.size() - 1), curr->children[i]);
                }
                return fin;
            } else {
                return helper(word.substr(1, word.size() - 1), curr->children[c - 'a']);
            }
    }
    
    bool search(string word) {
        return helper(word, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */