#
# @lc app=leetcode.cn id=707 lang=python3
#
# [707] 设计链表
#

# @lc code=start
class ListNode:

    def __init__(self, x: int) -> None:
        self.val = x
        self.prior, self.next = None, None


class MyLinkedList:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.size = 0
        self.head, self.tail = ListNode(0), ListNode(0)
        self.head.next = self.tail
        self.tail.prior = self.head

    def get(self, index: int) -> int:
        """
        Get the value of the index-th node in the linked list. If the index is invalid, return -1.
        """
        node = self.head.next
        while node != self.tail and index > 0:
            node = node.next
            index -= 1
        if node != self.tail:
            return node.val
        return -1

    def addAtHead(self, val: int) -> None:
        """
        Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
        """
        node = ListNode(val)
        node.prior, node.next = self.head, self.head.next
        self.head.next.prior = node
        self.head.next = node
        self.size += 1

    def addAtTail(self, val: int) -> None:
        """
        Append a node of value val to the last element of the linked list.
        """
        node = ListNode(val)
        node.prior, node.next = self.tail.prior, self.tail
        self.tail.prior.next = node
        self.tail.prior = node
        self.size += 1

    def addAtIndex(self, index: int, val: int) -> None:
        """
        Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted.
        """
        if index == self.size:
            self.addAtTail(val)
        elif index > self.size:
            return
        elif index <= 0:
            self.addAtHead(val)
        else:
            p = self.head
            while p != self.tail and index > 0:
                p = p.next
                index -= 1
            node = ListNode(val)
            node.prior, node.next = p, p.next
            p.next.prior = node
            p.next = node
            self.size += 1

    def deleteAtIndex(self, index: int) -> None:
        """
        Delete the index-th node in the linked list, if the index is valid.
        """
        if index < 0 or index >= self.size:
            return
        p = self.head.next
        while p != self.tail and index > 0:
            p = p.next
            index -= 1
        p.next.prior = p.prior
        p.prior.next = p.next
        self.size -= 1


# Your MyLinkedList object will be instantiated and called as such:
# obj = MyLinkedList()
# param_1 = obj.get(index)
# obj.addAtHead(val)
# obj.addAtTail(val)
# obj.addAtIndex(index,val)
# obj.deleteAtIndex(index)
# @lc code=end
