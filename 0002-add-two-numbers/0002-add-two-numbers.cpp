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
    ListNode* addTwoNumbersHelper(ListNode* l1, ListNode* l2, int carry) {
        if (!l1 && !l2){
            if (carry){
                return new ListNode(carry, nullptr);
            } else {
                return nullptr;
            }
        }
        else if (!l1){
            int j = l2->val + carry;
            return new ListNode(j % 10, addTwoNumbersHelper(l1, l2->next, j / 10));
        }
        else if (!l2){
            int j = l1->val + carry;
            return new ListNode(j % 10, addTwoNumbersHelper(l1->next, l2, j / 10));
        }
        else {
            int j = (l1->val+l2->val+carry);
            return new ListNode(j % 10, addTwoNumbersHelper(l1->next, l2->next, j / 10));
        }
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
        return addTwoNumbersHelper(l1, l2, 0);
    }
};