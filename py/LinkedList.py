class node:
    def __init__(self, data=None):
        self.data = data
        self.link = None


class LinkedList:
    def __init__(self, head=None):
        self.head = head
        self.non = 0

    def display(self):
        p = self.head
        while p is not None:
            print(p.data, end=" ")
            p = p.link

    def insert_front(self, data):
        temp = node(data)
        temp.link = self.head
        self.head = temp

    def insert_back(self, data):
        temp = node(data)
        p = self.head
        while p is not None:
            p = p.link
        p.link = temp


list1 = LinkedList()
list1.head = node("ananth")
list1.insert_front("venkat")
list1.insert_front("raghu")
list1.insert_front("priya")
list1.insert_front("ranga")

list1.display()
