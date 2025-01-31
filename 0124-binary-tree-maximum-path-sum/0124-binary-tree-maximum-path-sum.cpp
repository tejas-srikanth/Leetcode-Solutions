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
    pair<int, int> maxPathHelper(TreeNode* root){
        if (!root){
            return {0, 0};
        } else if (!root->left && !root->right){
            return {root->val, root->val};
        } else if (!root->right){
            pair<int, int> leftRes = maxPathHelper(root->left);
            int maxPathOverall = max({leftRes.first, leftRes.second + root->val, root->val});
            int maxLine = max({leftRes.second + root->val, root->val});
            return {maxPathOverall, maxLine};
        } else if (!root->left){
            pair<int, int> leftRes = maxPathHelper(root->right);
            int maxPathOverall = max({leftRes.first, leftRes.second + root->val, root->val});
            int maxLine = max({leftRes.second + root->val, root->val});
            return {maxPathOverall, maxLine};
        } else {
            pair<int, int> leftRes = maxPathHelper(root->left);
            pair<int, int> rightRes = maxPathHelper(root->right);
            int maxPathOverall = max({leftRes.first, leftRes.second + root->val, root->val, rightRes.first, rightRes.second + root->val, leftRes.second + rightRes.second + root->val});
            int maxLine = max({leftRes.second + root->val, rightRes.second + root->val, root->val});
            return {maxPathOverall, maxLine};
        }
    }
    int maxPathSum(TreeNode* root) {
        return maxPathHelper(root).first;
    }
};