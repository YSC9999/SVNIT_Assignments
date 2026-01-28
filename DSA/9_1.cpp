#include <iostream>
#include <vector>
using namespace std;
#define SIZE 5

class priorityqueue
{
    int size;
    int *arr;
    int front;
    int rear;
    vector<int> priority; 
public:
    priorityqueue(int size)
    {
        this->size = size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    ~priorityqueue() {
        delete[] arr;
    }

    void enqueue(priorityqueue &q, int x, int prio)
    {
        if (rear == size - 1) {
            cout << "Queue is Full" << endl;
            return;
        }

        priority.push_back(prio);
        
        if(front == -1)
        {
            front = rear = 0;
        }
        else
        {
            rear++;
        }
        arr[rear] = x;

        int j = priority.size() - 1;
        while(j > 0 && priority[j] < priority[j-1])
        {
            swap(q.arr[j], q.arr[j-1]);
            swap(priority[j], priority[j-1]);
            j--;
        }
    }

    void dequeue()
    {
        if (front == -1)
        {
            cout << "Queue is Empty" << endl;
        }
        else if (front == rear)
        {
            front = rear = -1;
            priority.clear();
        }
        else
        {
            for (int i = 0; i < rear; i++) {
                arr[i] = arr[i+1];
            }
            priority.erase(priority.begin());
            rear--;
        }
    }

    int peek()
    {
        if (front == -1)
        {
            cout << "Queue is Empty" << endl;
            return -1;
        }
        return arr[front];
    }

    bool isEmpty()
    {
        return front == -1;
    }

    bool isFull()
    {
        return rear == size-1;
    }

    void display()
    {
        if (isEmpty()) {
            cout << "Queue is Empty" << endl;
            return;
        }
        
        cout << "     Queue: ";
        for(int i = front; i <= rear; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
        
        cout << "Priorities: ";
        for(int i = 0; i < priority.size(); i++){
            cout << priority[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    priorityqueue pq(SIZE);
    pq.enqueue(pq, 3, 2);
    pq.enqueue(pq, 2, 4);
    pq.enqueue(pq, 4, 1);
    pq.enqueue(pq, 5, 5);
    pq.enqueue(pq, 1, 3);
    pq.display();
    pq.dequeue();
    pq.display();
    return 0;
}