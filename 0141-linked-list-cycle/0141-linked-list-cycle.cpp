/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head || !head->next){
            return false;
        }
        ListNode* sp = head;
        ListNode* fp = head;
        while (fp && fp->next){
            sp = sp->next;
            fp = fp->next->next;
            if (sp == fp){
                return true;
            }
        }
        return false;
    }
};