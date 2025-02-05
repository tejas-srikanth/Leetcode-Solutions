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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> traversal;
        deque<TreeNode*> dq;
        int lvl = 0;
        if (!root){
            return {};
        }

        dq.push_back(root);
        while (dq.size()){
            vector<int> levelTraversal;
            int sz = dq.size();
            for (int i=0; i<sz; ++i){
                TreeNode* x = dq.front();
                dq.pop_front();
                levelTraversal.push_back(x->val);
                if (x->left){
                    dq.push_back(x->left);
                }

                if (x->right){
                    dq.push_back(x->right);
                }
            }
            if (lvl % 2){
                std::reverse(levelTraversal.begin(), levelTraversal.end());
            }
            lvl++;
            traversal.push_back(levelTraversal);
        }
        return traversal;
    }
};