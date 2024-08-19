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
    pair<int, int> helper(TreeNode* root){
        if (!root){
            return {0, 0};
        } else if (!root->left && !root->right){
            return {root->val, root->val};
        } else if (!root->left){
            pair<int, int> p2 = helper(root->right);
            int longestPathSum = max(p2.first + root->val, root->val);
            return {longestPathSum, max({p2.second, p2.first + root->val, root->val, p2.first})};
        } else if (!root->right){
            pair<int, int> p2 = helper(root->left);
            int longestPathSum = max(p2.first + root->val, root->val);
            return {longestPathSum, max({p2.second, p2.first + root->val, root->val, p2.first})};
        }
        else {
            pair<int, int> p1 = helper(root->left);
            pair<int, int> p2 = helper(root->right);
            int longestPathSum = max(max(p1.first, p2.first) + root->val, root->val);
            return {longestPathSum, max({p1.second, p2.second, p1.first + p2.first + root->val, p1.first + root->val, p2.first + root->val, root->val, p1.first, p2.first})};
        }
    }
    int maxPathSum(TreeNode* root) {
        if (!root){
            return 0;
        }
        return helper(root).second;
    }
};