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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1 && !list2){
            return nullptr;
        }
        ListNode* newlist = new ListNode();
        ListNode* head = newlist;

        while (list1 && list2){
            if (list1->val < list2->val){
                newlist->val = list1->val;
                newlist->next = new ListNode();
                list1 = list1->next;
                newlist = newlist->next;
            }
            else {
                newlist->val = list2->val;
                newlist->next = new ListNode();
                list2 = list2->next;
                newlist = newlist->next;
            }
        }

        if (!list1 && list2){
            newlist->val = list2->val;
            newlist->next = list2->next;
        }
        else if (!list2 && list1){
            newlist->val = list1->val;
            newlist->next = list1->next;
        }
        else {
            newlist = nullptr;
        }
        return head;
    }
};