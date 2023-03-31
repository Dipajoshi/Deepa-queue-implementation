#include <iostream>
using namespace std;

#define max 100

class Queue
{
private:
    int queue[max];
    int front, rear;

public:
    Queue()
    {
        front = rear = -1;
    }

    bool isEmpty()
    {
        return (front == -1 && rear == -1);
    }

    bool isFull()
    {
        return (rear == max - 1);
    }

    void enqueue(int item)
    {
        if (isFull())
        {
            cout << "Queue is full, cannot enqueue item." << endl;
            return;
        }
        else if (isEmpty())
        {
            front = rear = 0;
        }
        else
        {
            rear++;
        }
        queue[rear] = item;
    }

    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty, cannot dequeue item." << endl;
            return -1;
        }
        else if (front == rear)
        {
            int item = queue[front];
            front = rear = -1;
            return item;
        }
        else
        {
            int item = queue[front];
            front++;
            return item;
        }
    }
    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
        }
        else
        {
            cout << "rear";
            for (int i = rear; i >= front; i--)
            {
                cout << " | " << queue[i];
            }
            cout << " |front" << endl;
        }
    }
};

int main()
{
    Queue q;
    int choice, val;
    while (1)
    {
        cout << "Enter 1 for Enqueue" << endl
             << "Enter 2 for Dequeue" << endl
             << "Enter 3 for Display" << endl
             << "enter 4 for Exit" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter the number you want to enqueue " << endl;
            cin >> val;
            q.enqueue(val);
            break;

        case 2:
            val = q.dequeue();
            cout << "The dequeued number is " << val << endl;
            break;

        case 3:
            q.display();
            break;

        case 4:
            exit(1);
            break;

        default:
            cout << "Invalid choice " << endl;
            break;
        }
    }
    return 0;
}