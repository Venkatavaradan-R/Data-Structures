class node:
    def __init__(self, data=None):
        self.data = data
        self.link = None


class list:
    def __init__(self, head=None):
        self.head = head
        self.non = 0


list1 = list()
list1.head = node("ananth")
print(list1.head.data)
