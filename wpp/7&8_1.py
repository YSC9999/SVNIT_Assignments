class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None

    def display(self):
        current = self.head
        while current:
            print(current.data, end=" -> ")
            current = current.next
        print("None")

    def insert(self, data):
        new_node = Node(data)
        if not self.head:
            self.head = new_node
            return
        last = self.head
        while last.next:
            last = last.next
        last.next = new_node

    def delete(self, key):
        current = self.head
        if current and current.data == key:
            self.head = current.next
            current = None
            return

        prev = None
        while current and current.data != key:
            prev = current
            current = current.next

        if current is None:
            return

        prev.next = current.next
        current = None

ll = LinkedList()

while True:
    print("\n1. Insert node")
    print("2. Delete node")
    print("3. Display linked list")
    print("4. Exit")
    choice = int(input("Enter your choice: "))

    if choice == 1:
        data = int(input("Enter data to insert: "))
        ll.insert(data)
    elif choice == 2:
        key = int(input("Enter data to delete: "))
        ll.delete(key)
    elif choice == 3:
        ll.display()
    elif choice == 4:
        break
    else:
        print("Invalid choice")