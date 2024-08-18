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
    int decorateTree(TreeNode* root){
        if (!root){
            return -1;
        } else {
            int mxlft = decorateTree(root->left);
            int mxright = decorateTree(root->right);
            root->val = max(mxlft, mxright) + 1;
            return root->val;
        }
    }
    int diameterOfBinaryTree(TreeNode* root) {
        decorateTree(root);
        if (!root){
            return 0;
        } else {
            int d1 = diameterOfBinaryTree(root->left);
            int d2 = diameterOfBinaryTree(root->right);
            if (root->left && root->right){
                return max({root->left->val + root->right->val + 2, d1, d2});
            } else {
                return max({root->val, d1, d2});
            }
        }
    }
};