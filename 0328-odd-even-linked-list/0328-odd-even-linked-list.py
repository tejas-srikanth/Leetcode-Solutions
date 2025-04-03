# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def oddEvenList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head is None:
            return head
        evenlist_head = None
        evenlist_last = None
        currptr = head
        prev = head
        while currptr:
            prev = currptr
            if evenlist_head is None and evenlist_last is None:
                evenlist_head = currptr.next
                evenlist_last = currptr.next
            else:
                evenlist_last.next = currptr.next
                evenlist_last = evenlist_last.next
            if currptr.next:
                currptr.next = currptr.next.next
            currptr = currptr.next
        prev.next = evenlist_head
        return head
