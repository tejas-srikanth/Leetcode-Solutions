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
    void heightDecorate(TreeNode* root){
        if (!root){
            return;
        }
        if (!root->left && !root->right){
            root->val = 1;
        } else {
            int currMax = -1;
            if (root->left){
                heightDecorate(root->left);
                if (root->left->val > currMax){
                    currMax = root->left->val;
                }
            }
            if (root->right){
                heightDecorate(root->right);
                if (root->right->val > currMax){
                    currMax = root->right->val;
                }
            }
            root->val = currMax + 1;
            
        }
    }
    bool isBalancedHelper (TreeNode* root){
        if (!root){
            return true;
        } else {
            bool checkBSubt = isBalanced(root->left) && isBalanced(root->right);
            if (root->left){
                if (!root->right){
                    checkBSubt = checkBSubt && root->left->val <= 1;
                } else {
                    checkBSubt = checkBSubt && abs(root->left->val - root->right->val) <= 1;
                }
            } else {
                if (root->right){
                    checkBSubt = checkBSubt && root->right->val <= 1;
                }
            }
            return checkBSubt;
        }
    }
    bool isBalanced(TreeNode* root) {
        heightDecorate(root);
        return isBalancedHelper(root);
    }
};