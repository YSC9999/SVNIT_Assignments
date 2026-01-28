class Queue:
    def __init__(self):
        self.queue = []

    def enqueue(self, data):
        self.queue.append(data)

    def dequeue(self):
        if self.is_empty():
            return "Queue is empty"
        return self.queue.pop(0)

    def is_empty(self):
        return len(self.queue) == 0

    def display(self):
        if self.is_empty():
            print("Queue is empty")
        else:
            print("Queue:", self.queue)

q = Queue()
while True:
    print("\n1. Enqueue element")
    print("2. Dequeue element")
    print("3. Display queue")
    print("4. Exit")
    choice = int(input("Enter your choice: "))
    if choice == 1:
        data = int(input("Enter data to enqueue: "))
        q.enqueue(data)
    elif choice == 2:
        print("Dequeued:", q.dequeue())
    elif choice == 3:
        q.display()
    elif choice == 4:
        break
    else:
        print("Invalid choice. Please try again.")
