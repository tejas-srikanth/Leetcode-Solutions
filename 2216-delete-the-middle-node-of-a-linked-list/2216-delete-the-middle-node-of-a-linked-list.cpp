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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* fp = head;
        ListNode* sp = head;
        while (fp && fp->next){
            prev = sp;
            sp = sp->next;
            fp = fp->next->next;
        }
        if (!prev){
            return nullptr;
        } else {
            prev->next = sp->next;
            sp = nullptr;
        }
        return head;
    }
};