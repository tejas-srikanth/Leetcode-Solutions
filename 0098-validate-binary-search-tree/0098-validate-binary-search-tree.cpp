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
    tuple<bool, long, long> isValidBSTHelper(TreeNode* root){
        if (!root){
            return {true, (long)INT_MAX + 1, (long)INT_MIN - 1};
        } else {
            tuple<bool, long, long> lt = isValidBSTHelper(root->left);
            tuple<bool, long, long> rt = isValidBSTHelper(root->right);
            bool isValid = std::get<0>(lt) && std::get<0>(rt) && (std::get<2>(lt) < root->val) && (std::get<1>(rt) > root->val);
            long maxTree = max((long)root->val, std::get<2>(rt));
            long minTree = min((long)root->val, std::get<1>(lt));
            return {isValid, minTree, maxTree};
        }
    }
    bool isValidBST(TreeNode* root) {

        return std::get<0>(isValidBSTHelper(root));
        
    }
};