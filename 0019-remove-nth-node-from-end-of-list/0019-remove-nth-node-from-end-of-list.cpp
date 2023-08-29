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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<ListNode*> theStack;
        ListNode* curr = head;
        while (curr){
            theStack.push_back(curr);
            curr = curr->next;
        }
        for (int i=0; i<n-1; ++i){
            theStack.pop_back();
        }
        ListNode* x = theStack.back();
        theStack.pop_back();
        if (theStack.empty()){
            head = x->next;
            return head;
        }
        else{
            ListNode* prev = theStack.back();
            prev->next = x->next;
            return head;
        }
    }
};