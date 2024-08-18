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
    vector<int> rightSideView(TreeNode* root) {
        if (!root){
            return {};
        }
        queue<TreeNode*> q;
        q.push(root);
        vector<int> rview;
        while (!q.empty()){
            int sz = q.size();
            while (sz){
                TreeNode* k = q.front();
                q.pop();
                if (sz == 1) rview.push_back(k->val);
                if (k->left) q.push(k->left);
                if (k->right) q.push(k->right);
                sz--;
            }
        }
        return rview;
    }
};