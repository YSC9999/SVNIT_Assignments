#include <iostream>
using namespace std;
#define SIZE 5
int arr[SIZE];
int front = -1, rear = -1;

void insertFront(int x)
{
    if (front == 0 && rear == SIZE - 1)
    {
        cout << "Queue is Full" << endl;
    }
    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
        arr[front] = x;
    }
    else if (front == 0)
    {
        front = SIZE - 1;
        arr[front] = x;
    }
    else
    {
        front--;
        arr[front] = x;
    }
}

void insertRear(int x)
{
    if (front == 0 && rear == SIZE - 1)
    {
        cout << "Queue is Full" << endl;
    }
    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
        arr[rear] = x;
    }
    else if (rear == SIZE - 1)
    {
        rear = 0;
        arr[rear] = x;
    }
    else
    {
        rear++;
        arr[rear] = x;
    }
}

void deleteFront()
{
    if (front == -1)
    {
        cout << "Queue is Empty" << endl;
    }
    else if (front == rear)
    {
        front = rear = -1;
    }
    else if (front == SIZE - 1)
    {
        front = 0;
    }
    else
    {
        front++;
    }
}

void deleteRear()
{
    if (front == -1)
    {
        cout << "Queue is Empty" << endl;
    }
    else if (front == rear)
    {
        front = rear = -1;
    }
    else if (rear == 0)
    {
        rear = SIZE - 1;
    }
    else
    {
        rear--;
    }
}

void isEmpty()
{
    if (front == -1)
    {
        cout << "Queue is Empty" << endl;
    }
    else
    {
        cout << "Queue is not Empty" << endl;
    }
}

void isFull()
{
    if ((front == 0 && rear == SIZE - 1) || (front == rear + 1))
    {
        cout << "Queue is Full" << endl;
    }
    else
    {
        cout << "Queue is not Full" << endl;
    }
}

void display()
{
    if (front == -1)
    {
        cout << "Queue is Empty" << endl;
    }
    else
    {
        cout << "     Queue: ";
        for (int i = front; i != rear; i = (i + 1) % SIZE)
        {
            cout << arr[i] << " ";
        }
        cout << arr[rear] << endl;
    }
}

int main()
{
    cout << "ENter your choice: " << endl;
    cout << "1. Insert an element at Front" << endl;
    cout << "2. Insert an element at Rear" << endl;
    cout << "3. Delete an element from Front" << endl;
    cout << "4. Delete an element from Rear" << endl;
    cout << "5. Check Empty" << endl;
    cout << "6. Check Full" << endl;
    cout << "7. Display" << endl;
    cout << "8. Exit" << endl;
    int choice, x;
    while (1)
    {
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter the element to insert: ";
            cin >> x;
            insertFront(x);
            break;
        case 2:
            cout << "Enter the element to insert: ";
            cin >> x;
            insertRear(x);
            break;
        case 3:
            deleteFront();
            break;
        case 4:
            deleteRear();
            break;
        case 5:
            isEmpty();
            break;
        case 6:
            isFull();
            break;
        case 7:
            display();
            break;
        case 8:
            exit(0);
        default:
            cout << "Invalid Choice" << endl;
        }
    }
    return 0;
}