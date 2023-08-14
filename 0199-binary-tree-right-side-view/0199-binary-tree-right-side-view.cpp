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
        queue<pair<TreeNode*, int>> pq;
        vector<int> nodes;
        pq.push({root, 1});
        int maxLvl = 0;
        TreeNode* f;
        int lvl;
        while (!pq.empty()){
            pair<TreeNode*, int> p = pq.front();
            pq.pop();
            f = p.first;
            lvl = p.second;
            if (f == nullptr){
                continue;
            }
            if (lvl > maxLvl){
                maxLvl = lvl;
                nodes.push_back(f->val);
            }
            if (f->right){
                pq.push({f->right, lvl+1});
            }
            if (f->left){
                pq.push({f->left, lvl+1});
            }
        }
        return nodes;
    }
};