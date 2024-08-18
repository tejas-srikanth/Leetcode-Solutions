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
    int goodNodes(TreeNode* root) {
        if (!root) return 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, root->val});
        int numGood = 0;
        while (!q.empty()){
            TreeNode* k = q.front().first;
            int mx = q.front().second;
            q.pop();
            if (mx <= k->val) numGood++;
            if (k->left) q.push({k->left, max(mx, k->val)});
            if (k->right) q.push({k->right, max(mx, k->val)});
        }
        return numGood;
    }
};