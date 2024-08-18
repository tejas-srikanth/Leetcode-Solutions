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
    bool isHeightBalanced = true;
    pair<int, bool> isBalancedPair(TreeNode* root){
        if (!root){
            return {0, true};
        }
        pair<int, bool> pl = isBalancedPair(root->right);
        pair<int, bool> pr = isBalancedPair(root->left);
        bool isBalanced = (pl.second && pr.second && abs(pl.first - pr.first) <= 1);
        int h = max(pl.first, pr.first) + 1;
        return {h, isBalanced};
    }
    bool isBalanced(TreeNode* root) {
        return isBalancedPair(root).second;
    }
};