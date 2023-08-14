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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        q.push({root, 1});
        int currLevel = 0;
        int lvl;
        TreeNode* f;
        vector<double> avg;
        int numNodes = 0;
        double totalNodes = 0;
        while (!q.empty()){
            pair<TreeNode*, int> p = q.front();
            q.pop();
            lvl = p.second;
            f = p.first;
            if (lvl > currLevel){
                currLevel = lvl;
                if (lvl != 1){
                    avg.push_back(totalNodes/numNodes);
                }
                numNodes = 1;
                totalNodes = f->val;
            } else {
                numNodes++;
                totalNodes += f->val;
            }

            if (f->right){
                q.push({f->right, lvl+1});
            }

            if (f->left){
                q.push({f->left, lvl+1});
            }

        }
        avg.push_back(totalNodes/numNodes);
        return avg;
    }
};