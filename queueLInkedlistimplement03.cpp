#include <iostream>
using namespace std;

// Node structure for linked list
class Node {
public:
    int data;       // Stores value
    Node* next;     // Pointer to next node

    // Constructor
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

// Queue class using linked list
class Queue {

    Node* front;    // Points to front node
    Node* rear;     // Points to rear node

public:
    // Constructor
    Queue() {
        front = NULL;   // Queue initially empty
        rear = NULL;
    }

    // Check if queue is empty
    bool isEmpty() {
        return (front == NULL);
    }

    // Enqueue operation (insert at rear)
    void enqueue(int data) {

        Node* newNode = new Node(data);  // Create new node

        // If queue is empty
        if(rear == NULL) {
            front = newNode;  // Front points to new node
            rear = newNode;   // Rear points to new node
        }
        else {
            rear->next = newNode;  // Link old rear node to new node
            rear = newNode;        // Move rear pointer to new last node
        }
    }

    // Dequeue operation (remove from front)
    int dequeue() {

        // If queue is empty
        if(isEmpty()) {
            cout << "Queue is Empty" << endl;
            return -1;
        }

        Node* temp = front;        // Store front node
        int ans = temp->data;      // Store value to return

        front = front->next;       // Move front pointer

        // If queue becomes empty after deletion
        if(front == NULL) {
            rear = NULL;
        }

        delete temp;               // Free memory
        return ans;                // Return removed element
    }

    // Get front element without removing
    int getFront() {
        if(isEmpty()) {
            return -1;
        }
        return front->data;
    }
};

int main() {

    Queue q;   // Create queue object

    q.enqueue(10);   // Queue: 10
    q.enqueue(20);   // Queue: 10 20
    q.enqueue(30);   // Queue: 10 20 30

    cout << "Front element: " << q.getFront() << endl;
    // Output: Front element: 10

    cout << "Deleted: " << q.dequeue() << endl;
    // Output: Deleted: 10

    cout << "Deleted: " << q.dequeue() << endl;
    // Output: Deleted: 20

    cout << "Front element now: " << q.getFront() << endl;
    // Output: Front element now: 30

    q.dequeue();  // Deletes 30, queue becomes empty

    if(q.isEmpty()) {
        cout << "Queue is empty now" << endl;
        // Output: Queue is empty now
    }

    return 0;
}

/*
FINAL OUTPUT:

Front element: 10
Deleted: 10
Deleted: 20
Front element now: 30
Queue is empty now
*/
