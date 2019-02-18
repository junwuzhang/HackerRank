class Node:
    def __init__(self,data):
        self.data = data
        self.next = None 
class Solution: 
    def display(self,head):
        current = head
        while current:
            print(current.data,end=' ')
            current = current.next

    def insert(self,head,data): 
    #Complete this method
        # if there is no head of linked list
        if head is None:
            # create a linked list
            head = Node(data)
        # if there is only head
        elif head.next is None:
            # create a node at the next of head
            head.next = Node(data)
        # if there is more than one next beyond head
        else:
            # recursively add node after head
            Solution.insert(self, head.next, data)
        # return the head of the linked list
        return head

mylist= Solution()
T=int(input())
head=None
for i in range(T):
    data=int(input())
    head=mylist.insert(head,data)    
mylist.display(head); 	  