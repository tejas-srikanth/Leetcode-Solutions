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
        queue<TreeNode*> frontier;
        frontier.push(root);
        vector<vector<int>> res;
        while (!frontier.empty()){
            int sz = frontier.size();
            vector<int> currLevel;
            for (int i=0; i<sz; ++i){
                TreeNode* curr = frontier.front();
                currLevel.push_back(curr->val);
                if (curr->left){
                    frontier.push(curr->left);
                }
                if (curr->right){
                    frontier.push(curr->right);
                }
                frontier.pop();
            }
            res.push_back(currLevel);
        }
        return res;
    }
};