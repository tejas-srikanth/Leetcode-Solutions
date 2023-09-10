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
    ListNode* append(ListNode* list1, ListNode* list2){
        if (!list1){
            return list2;
        } else {
            list1->next = list2;
            return list2;
        }
    }
    void prtList(ListNode* list){
        while (list){
            cout << list->val << " ";
            list = list->next;
        }
        cout << endl;
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = nullptr;
        ListNode* curr = head;
        while (list1 || list2){
            if (!list1){
                curr = append(curr, list2);
                list2 = list2->next;
            } else if (!list2){
                curr = append(curr, list1);
                list1 = list1->next;
            } else {
                if (list1->val < list2->val){
                    curr = append(curr, list1);
                    list1 = list1->next;
                } else {
                    curr = append(curr, list2);
                    list2=list2->next;
                }
            }
            if (head == nullptr){
                head = curr;
            }
        }
        return head;
    }
};