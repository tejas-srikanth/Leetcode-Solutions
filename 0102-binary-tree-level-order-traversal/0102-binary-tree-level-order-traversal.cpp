/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root){
            return {};
        }
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        int currLevel = 0;
        vector<vector<int>> fin;
        vector<int> acc;
        while (!q.empty()){
            pair<TreeNode*, int> p = q.front();
            q.pop();
            TreeNode* k = p.first;
            int lvl = p.second;
            if (lvl == currLevel){
                acc.push_back(k->val);
            } else {
                currLevel ++;
                fin.push_back(acc);
                acc.clear();
                acc.push_back(k->val);
            }
            if (k->left){
                q.push({k->left, lvl+1});
            } 

            if (k->right){
                q.push({k->right, lvl+1});
            }
        }

        fin.push_back(acc);
        return fin;

    }
};