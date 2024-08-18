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
    pair<int, int> diameterHelper(TreeNode* root){
        if (!root){
            return {-1, 0};
        } else {
            pair<int, int> pl = diameterHelper(root->left);
            pair<int, int> pr = diameterHelper(root->right);
            return {max(pl.first, pr.first) + 1, max({pl.second, pr.second, pl.first + pr.first + 2})};
        }
    }
    int diameterOfBinaryTree(TreeNode* root) {
        return diameterHelper(root).second;
    }
};