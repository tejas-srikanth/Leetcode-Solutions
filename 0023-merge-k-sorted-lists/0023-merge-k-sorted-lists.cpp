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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* theList = nullptr;
        ListNode* head = nullptr;
        auto comp = [](ListNode* l, ListNode* r){
            return l->val > r->val;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(comp)> theHeap(comp);
        for (ListNode* l: lists){
            if (l){
                theHeap.push(l);
            }
        }
        while (theHeap.size()){
            ListNode* t = theHeap.top();
            if (!head){
                head = t;
                theList = head;
            } else {
                theList->next = t;
                theList = theList->next;
            }
            theHeap.pop();
            if (t->next){
                theHeap.push(t->next);
            }
        }
        if (head){
            theList->next = nullptr;
        }
        return head;
    }
};