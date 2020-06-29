# do edge cases for all

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
        if self.head == None:
            print("Empty!")

    def insert_front(self, data):
        temp = node(data)
        temp.link = self.head
        self.head = temp

    def insert_back(self, data):
        temp = node(data)
        if self.head == None:
            self.insert_front(data)
            return

        p = self.head
        while p.link is not None:
            p = p.link
        p.link = temp

    def insert_mid(self, data):
        temp = node(data)
        if self.head == None:
            self.insert_back(data)
            return

        if self.non == 1:
            if self.head.data > data:
                self.insert_front(data)
                return
            else:
                self.insert_back(data)
            return

        p = self.head
        q = self.head
        while p != None and p.data < data:
            q = p
            p = p.link

        if p == None:
            q.link = temp
            return

        q.link = temp
        temp.link = p


list1 = LinkedList()
list1.head = node(2)
# list1.insert_front(1)
# list1.insert_back(3)
# list1.insert_back(4)
# list1.insert_back(5)
# list1.insert_back(6)

list1.insert_mid(0)


list1.display()
