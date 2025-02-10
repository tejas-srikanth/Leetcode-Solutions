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
    int sumNumbers(TreeNode* root) {
        if (!root){
            return 0;
        }
        int totalPathSum = 0;
        queue<pair<TreeNode*, string>> q;
        q.push({root, ""});
        while (q.size()){
            pair<TreeNode*, string> p = q.front();
            q.pop();
            char x = p.first->val + '0';
            if (!p.first->left && !p.first->right){
                totalPathSum += stoi(p.second + x);
            } else {
                if (p.first->left){
                    q.push({p.first->left, p.second + x});
                }

                if (p.first->right){
                    q.push({p.first->right, p.second + x});
                }
            }
        }
        return totalPathSum;
    }
};