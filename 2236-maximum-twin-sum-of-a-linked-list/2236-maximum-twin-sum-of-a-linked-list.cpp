/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
        vector<ListNode*> v;
        ListNode* sp = head;
        ListNode* fp = head;
        int tS = -1;
        while (fp && fp->next){
            v.push_back(sp);
            sp = sp->next;
            fp = fp->next->next;
        }
        while (!v.empty()){
            fp = v.back();
            tS = max(tS, fp->val + sp->val);
            sp = sp->next;
            v.pop_back();
        }
        return tS;
        
    }
};