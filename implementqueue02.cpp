#include <iostream>
using namespace std;

class Queue {

    int* arr;        // Dynamic array to store queue elements
    int qfront;      // Index of front element
    int rear;        // Index of next insertion position
    int size;        // Maximum size of queue

public:
    // Constructor
    Queue() {
        size = 100001;          // Set queue size
        arr = new int[size];    // Allocate memory
        qfront = 0;             // Initialize front
        rear = 0;               // Initialize rear
    }

    // Check if queue is empty
    bool isEmpty() {
        return (qfront == rear);
    }

    // Insert element into queue
    void enqueue(int data) {
        if(rear == size) {      // Queue overflow condition
            cout << "Queue is Full" << endl;
        }
        else {
            arr[rear] = data;   // Insert element at rear
            rear++;             // Move rear forward
        }
    }

    // Remove element from queue
    int dequeue() {
        if(qfront == rear) {   // Queue underflow condition
            return -1;
        }
        else {
            int ans = arr[qfront]; // Store front element
            arr[qfront] = -1;      // Optional: clear value
            qfront++;              // Move front forward

            // Reset pointers when queue becomes empty
            if(qfront == rear) {
                qfront = 0;
                rear = 0;
            }
            return ans;             // Return removed element
        }
    }

    // Get front element
    int front() {
        if(qfront == rear)
            return -1;
        else
            return arr[qfront];
    }
};

int main() {

    Queue q;   // Create queue object

    q.enqueue(10);   // Insert 10
    q.enqueue(20);   // Insert 20
    q.enqueue(30);   // Insert 30

    cout << "Front element: " << q.front() << endl;   // Output: 10

    cout << "Deleted element: " << q.dequeue() << endl; // Output: 10
    cout << "Deleted element: " << q.dequeue() << endl; // Output: 20

    cout << "Front element after deletions: " << q.front() << endl; // Output: 30

    q.dequeue();  // Remove last element

    // Check if queue is empty
    if(q.isEmpty()) {
        cout << "Queue is empty" << endl;
    }

    return 0;
}
