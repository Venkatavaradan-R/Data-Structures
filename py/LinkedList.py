
#  delete key is buggy and need to verify edge for delete pos

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
        print(f"No of elements in the list are:{self.non}")
        while p is not None:
            print(p.data, end=" ")
            p = p.link
        print("")
        if self.head == None:
            print("Empty!")

    def insert_front(self, data):
        temp = node(data)
        temp.link = self.head
        self.head = temp
        self.non = self.non + 1

    def insert_back(self, data):
        temp = node(data)
        if self.head == None:
            self.insert_front(data)
            return

        p = self.head
        while p.link is not None:
            p = p.link
        p.link = temp
        self.non = self.non + 1

    def insert_mid(self, data):
        if self.non == 0:
            self.insert_front(data)
            return

        if self.non == 1:
            if self.head.data > data:
                self.insert_front(data)
                return
            else:
                self.insert_back(data)
                return

        temp = node(data)
        p = self.head
        q = None
        while p != None and p.data < data:
            q = p
            p = p.link

        if p == None:
            q.link = temp
            self.non = self.non + 1
            return

        if q == None:
            self.insert_front(data)
            return
        q.link = temp
        temp.link = p
        self.non = self.non + 1

    def destroy(self):
        if self.non == 0:
            return

        if self.non == 1:
            del self.head
            return

        p = self.head
        q = None

        while p is not None:
            del q
            q = p
            p = p.link
        del q
        return

    def delete_front(self):
        if self.non == 0:
            return
        p = self.head
        self.head = p.link
        del p
        self.non = self.non-1

    def delete_back(self):
        if self.non == 0:
            return

        if self.non == 1:
            self.delete_front()
            return
        p = self.head
        q = None

        while p.link is not None:
            q = p
            p = p.link

        q.link = None
        del p
        self.non = self.non-1

    def delete_key(self, data):
        if self.non == 0:
            return

        if self.non == 1:
            if self.head.data == data:
                self.delete_front()
                return
            else:
                return

        if self.head.data == data:
            self.delete_front()
            return

        p = self.head
        q = None

        while p is not None and p.data != data:
            q = p
            p = p.link

        if p == None:
            return

        q.link = p.link
        del p
        self.non = self.non-1

    def delete_pos(self, pos):

        if self.non == 0:
            return

        if self.non == 1:
            if pos == 1:
                self.delete_front()
                return
            else:
                return

        p = self.head
        q = None

        if pos == 1:
            self.delete_front()
            return
        count = 1
        while count is not pos and p is not None:
            q = p
            p = p.link
            count = count+1

        if p == None:
            return

        q.link = p.link
        del p
        self.non = self.non - 1

    def search(self, data):
        if self.non == 0:
            return -1

        if self.non == 1:
            if self.head.data == data:
                return 1
            else:
                return -1

        if self.head.data == data:
            return 1

        p = self.head
        count = 1

        while p is not None and p.data != data:
            p = p.link
            count = count+1

        if p is None:
            return -1

        return count

    def duplicate(self, newlist):
        if self.non == 1:
            return

        if self.non == 1:
            newlist.head = node(self.head.data)
            newlist.non = newlist.non+1
            return

        p = self.head

        while p is not None:
            newlist.insert_back(p.data)
            p = p.link


list1 = LinkedList()
list1.head = None
list1.insert_front(1)
list1.insert_back(3)
list1.insert_back(4)
list1.insert_back(5)
list1.insert_back(6)
list1.insert_mid(0)


list1.display()

data = 4

print(f"data = {data} can be found at pos {list1.search(data)}")

list2 = LinkedList()

list1.duplicate(list2)

list2.display()


list1.destroy()
del list1
