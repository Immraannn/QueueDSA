#include <iostream>
using namespace std;

class CircularQueue {
    int *arr;          // Dynamic array to store queue elements
    int front;         // Points to the front element of the queue
    int rear;          // Points to the last element of the queue
    int size;          // Maximum capacity of the queue

public:
    // Constructor: Initialize circular queue with given size
    CircularQueue(int n) {
        size = n;              // Set maximum size
        arr = new int[size];   // Allocate memory for queue
        front = rear = -1;     // Queue is initially empty
    }

    // Enqueue operation: Insert an element into the circular queue
    bool enqueue(int value) {
        // Condition to check if queue is full
        if ((front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1))) {
            cout << "Queue is Full. Cannot enqueue " << value << endl;
            return false;
        }

        // Case 1: Queue is empty (first insertion)
        if (front == -1) {
            front = rear = 0;
        }
        // Case 2: Rear reached end and front is not at 0 (wrap around)
        else if (rear == size - 1 && front != 0) {
            rear = 0;
        }
        // Case 3: Normal case
        else {
            rear++;
        }

        arr[rear] = value;    // Insert element at rear
        cout << value << " enqueued successfully" << endl;
        return true;
    }

    // Dequeue operation: Remove and return front element
    int dequeue() {
        // Check if queue is empty
        if (front == -1) {
            cout << "Queue is Empty. Cannot dequeue" << endl;
            return -1;
        }

        int ans = arr[front]; // Store front element
        arr[front] = -1;      // Optional: clear the position

        // Case 1: Only one element in queue
        if (front == rear) {
            front = rear = -1;
        }
        // Case 2: Front reached end (wrap around)
        else if (front == size - 1) {
            front = 0;
        }
        // Case 3: Normal case
        else {
            front++;
        }

        return ans;           // Return dequeued element
    }

    // Display elements of the circular queue
    void display() {
        // Check if queue is empty
        if (front == -1) {
            cout << "Queue is Empty" << endl;
            return;
        }

        cout << "Queue elements: ";

        // Case 1: No wrap-around
        if (front <= rear) {
            for (int i = front; i <= rear; i++) {
                cout << arr[i] << " ";
            }
        }
        // Case 2: Wrap-around case
        else {
            for (int i = front; i < size; i++) {
                cout << arr[i] << " ";
            }
            for (int i = 0; i <= rear; i++) {
                cout << arr[i] << " ";
            }
        }
        cout << endl;
    }
};

// Main function to test Circular Queue
int main() {
    CircularQueue cq(5);   // Create circular queue of size 5

    cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(30);
    cq.enqueue(40);
    cq.enqueue(50);        // Queue becomes full here

    cq.display();          // Display queue elements

    cout << "Dequeued element: " << cq.dequeue() << endl;
    cout << "Dequeued element: " << cq.dequeue() << endl;

    cq.display();          // Display after dequeue

    cq.enqueue(60);        // Wrap-around insertion
    cq.enqueue(70);

    cq.display();          // Final queue state

    return 0;
}

/*
Expected Output (approx):

10 enqueued successfully
20 enqueued successfully
30 enqueued successfully
40 enqueued successfully
50 enqueued successfully
Queue elements: 10 20 30 40 50
Dequeued element: 10
Dequeued element: 20
Queue elements: 30 40 50
60 enqueued successfully
70 enqueued successfully
Queue elements: 30 40 50 60 70
*/
