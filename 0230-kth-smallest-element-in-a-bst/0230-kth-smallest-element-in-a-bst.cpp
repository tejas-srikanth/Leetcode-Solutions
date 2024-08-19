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
    int numNodes(TreeNode* root){
        if (!root){
            return 0;
        } else {
            return numNodes(root->left) + numNodes(root->right) + 1;
        }
    }
    int kthSmallest(TreeNode* root, int k) {
        if (!root){
            return -1;
        } else {
            int numLeft = numNodes(root->left);
            if (numLeft == k-1){
                return root->val;
            } else if (numLeft > k-1){
                return kthSmallest(root->left, k);
            } else {
                return kthSmallest(root->right, k-numLeft-1);
            }
        }
        return -1;
    }
};