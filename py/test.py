class test:
    def __init__(self, age, name):
        self.age = age
        self.name = name

    def display(self):
        print(f"the age is {self.age}")


x = test(3, 'ananth')
x.display()

del test.age

x.display()
