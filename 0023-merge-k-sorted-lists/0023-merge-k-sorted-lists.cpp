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
    struct{
        bool operator()(const ListNode* l, const ListNode* r){ return l->val > r->val; }
    } customLess;

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<ListNode*> v;
        int listCount = 0;
        for (ListNode* list: lists){
            if (list != nullptr){
                v.push_back(list);
                listCount++;
            }
        }
        priority_queue minQ(v.begin(), v.end(), customLess);
        ListNode* head = nullptr;
        ListNode* curr = head;
        while (listCount > 0){
            ListNode* t = minQ.top();
            minQ.pop();
            if (head == nullptr){
                head = new ListNode(t->val);
                curr = head;
            } else {
                curr->next = new ListNode(t->val);
                curr = curr->next;
            }
            t = t->next;
            if (t == nullptr){
                listCount --;
            } else {
                minQ.push(t);
            }
        }
        return head;

    }
};