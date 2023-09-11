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
    pair<int, int> fastCalc(TreeNode* root){
        if (!root){
            return {0, 0};
        } else {
            pair<int, int> left = fastCalc(root->left);
            pair<int, int> right = fastCalc(root->right);
            return {max(left.first, right.first) + 1, max(max(left.first+ right.first, left.second), right.second)};
        }
    }
    int diameterOfBinaryTree(TreeNode* root) {
        return fastCalc(root).second;
    }
};