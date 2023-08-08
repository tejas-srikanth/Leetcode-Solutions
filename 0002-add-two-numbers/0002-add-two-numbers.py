# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        carry = 0
        head = ListNode((l1.val + l2.val + carry) % 10)
        carry = (l1.val + l2.val + carry) // 10
        l1 = l1.next
        l2 = l2.next
        curr = head
        while l1 is not None or l2 is not None:
            if (l1 is None):
                curr.next = ListNode((l2.val + carry) % 10)
                carry = (l2.val + carry) // 10
                curr = curr.next
                l2 = l2.next
            elif (l2 is None):
                curr.next = ListNode((l1.val + carry) % 10)
                carry = (l1.val + carry) // 10
                curr = curr.next
                l1 = l1.next
            else:
                curr.next = ListNode((l1.val + l2.val + carry) % 10)
                carry = (l1.val + l2.val + carry) // 10  
                curr = curr.next
                l1 = l1.next
                l2 = l2.next
        while carry > 0:
            curr.next = ListNode(carry % 10)
            carry = carry // 10  
            curr = curr.next
        return head    
        