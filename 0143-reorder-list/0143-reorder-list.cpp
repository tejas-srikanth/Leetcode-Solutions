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
    ListNode* reverseList(ListNode* head){
        if (!head){
            return nullptr;
        } else if (!head->next){
            return head;
        } else {
            ListNode* myList = reverseList(head->next);
            head->next->next = head;
            return myList;
        }
    }
    void reorderList(ListNode* head) {
        if (!head){
            return ;
        } else if (!head->next){
            return ;
        }

        ListNode* sp = head;
        ListNode* fp = head->next;
        while (fp && fp->next){
            sp = sp->next;
            fp = fp->next->next;
        }
        bool isOdd;
        if (fp){
            isOdd = false;
        } else {
            isOdd = true;
        }
        ListNode* secList = sp->next;
        secList = reverseList(secList);
        sp->next = nullptr;
        ListNode* curr = head;
        ListNode* nxt = curr->next;
        while (nxt && secList){
            curr->next = secList;
            secList = secList->next;
            curr->next->next = nxt;
            curr = nxt;
            nxt = curr->next;
        }
        // if (secList){
        //     cout << secList->val << " " << curr->val << endl;
        //     curr->next = secList;
        //     curr->next->next = nullptr;
        // }
        // secList = nullptr;
        // cout << "HIII" << endl;

        if (!isOdd){
            curr->next = secList;
            curr->next->next = nullptr;
        }
    }
};