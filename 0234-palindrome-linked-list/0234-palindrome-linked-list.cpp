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
    bool isPalindrome(ListNode* head) {
        ListNode* sp = head;
        ListNode* fp = head;
        ListNode* prev = nullptr;
        ListNode* next;
        if (!head->next){
            return true;
        }

        while (fp && fp->next){
            fp = fp->next->next;
            next = sp->next;
            sp->next = prev;
            prev = sp;
            sp = next;
        }
        ListNode* st;
        ListNode * st2;
        st = prev;
        if (fp){
            st2 = sp->next;
        } else {
            st2 = sp;
        }

        while (st && st2){
         
            if (st->val != st2->val){
                return false;
            }
            st = st->next;
            st2 = st2->next;
        }
        return true;

        
    }
};