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
    bool isEqual(TreeNode* p, TreeNode* q){
        if (!p && !q){
            return true;
        }
        else if (!(p && q)){
            return false;
        }
        else{
            return isEqual(p->left, q->left) && isEqual(p->right, q->right) && (p->val == q->val);
        }
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root && !subRoot){
            return true;
        }
        else if (!root){
            return false;
        }
        else {
            return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot) || (root->val == subRoot->val && isEqual(root->left, subRoot->left) && isEqual(root->right, subRoot->right));
        }
    }
};