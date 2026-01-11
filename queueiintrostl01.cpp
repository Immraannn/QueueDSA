#include<iostream>     // For input-output operations
#include<queue>        // For using STL queue
using namespace std;

int main() {

    // Create a queue of integers
    queue<int> q;

    // Push 11 into the queue
    q.push(11);

    // Print the front element of the queue
    cout << "front of q is: " << q.front() << endl;  
    // Output: front of q is: 11

    // Push 15 into the queue
    q.push(15);

    // Front remains 11 because queue follows FIFO
    cout << "front of q is: " << q.front() << endl;  
    // Output: front of q is: 11

    // Push 13 into the queue
    q.push(13);

    // Front is still 11
    cout << "front of q is: " << q.front() << endl;  
    // Output: front of q is: 11

    // Print the current size of the queue
    cout << "size of queue is : " << q.size() << endl;  
    // Output: size of queue is : 3

    // Remove elements from the queue (FIFO order)
    q.pop();   // Removes 11
    q.pop();   // Removes 15
    q.pop();   // Removes 13

    // Queue is now empty
    cout << "size of queue is : " << q.size() << endl;  
    // Output: size of queue is : 0

    // Check whether the queue is empty
    if(q.empty()) {
        cout << "Queue is empty " << endl;
    }
    else {
        cout << "queue is not empty " << endl;
    }

    return 0;
}





#include<iostream>     // For input-output
#include<queue>        // For STL queue
using namespace std;

// Function to read (print) all elements of the queue
// Queue is passed by value, so original queue is not changed
void readQueue(queue<char> q) {

    // Loop until queue becomes empty
    while(!q.empty()) {
        cout << q.front() << " ";  // Print front element
        q.pop();                   // Remove front element
    }
    cout << endl;
}

int main() {

    // Create a queue of characters
    queue<char> q;

    // Insert elements into queue
    q.push('A');
    q.push('B');
    q.push('C');

    cout << "Front of queue is: " << q.front() << endl;
    // Output: Front of queue is: A

    cout << "Size of queue is: " << q.size() << endl;
    // Output: Size of queue is: 3

    cout << "Queue elements are: ";
    readQueue(q);
    // Output: Queue elements are: A B C

    // Queue remains unchanged after function call
    cout << "Front after function call: " << q.front() << endl;
    // Output: Front after function call: A

    cout << "Size after function call: " << q.size() << endl;
    // Output: Size after function call: 3

    return 0;
}

