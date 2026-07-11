// Intution
// Remove every element from the queue and push it into a stack.
// Pop every element from the stack and push it back into the queue.
// The order becomes reversed.




#include <iostream>
#include <queue>
#include <stack>
using namespace std;

// Function to reverse the queue
void reverseQueue(queue<int> &q)
{
    stack<int> st;

    // Step 1: Move all queue elements into stack
    while (!q.empty())
    {
        st.push(q.front());   // Store front element
        q.pop();              // Remove it from queue
    }

    // Step 2: Move stack elements back to queue
    // Since stack is LIFO, queue gets reversed
    while (!st.empty())
    {
        q.push(st.top());     // Insert top element
        st.pop();             // Remove from stack
    }
}

int main()
{
    queue<int> q;

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);

    reverseQueue(q);

    cout << "Reversed Queue: ";

    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}

// rucursive way

#include <iostream>
#include <queue>
using namespace std;

// Function to reverse queue using recursion
void reverseQueue(queue<int> &q)
{
    // Base case: empty queue
    if (q.empty())
        return;

    // Store front element
    int element = q.front();
    q.pop();

    // Reverse remaining queue
    reverseQueue(q);

    // Insert stored element at rear
    q.push(element);
}

int main()
{
    queue<int> q;

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);

    reverseQueue(q);

    cout << "Reversed Queue: ";

    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}
//

call stack
The recursive calls remove all elements:

Call 1 removes 10
Call 2 removes 20
Call 3 removes 30
Queue becomes empty

While returning:

Push 30
Queue: 30

Push 20
Queue: 30 20

Push 10
Queue: 30 20 10
