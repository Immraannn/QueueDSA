#include <iostream>
#include <deque>
using namespace std;

int main() {

    deque<int> dq;

    // Insert at rear
    dq.push_back(10);
    dq.push_back(20);

    // Insert at front
    dq.push_front(5);

    // Print deque
    cout << "Deque: ";
    for (int x : dq)
        cout << x << " ";

    cout << endl;

    // Delete front
    dq.pop_front();

    // Delete rear
    dq.pop_back();

    cout << "After deletion: ";
    for (int x : dq)
        cout << x << " ";

    return 0;
}
//output
// Deque: 5 10 20
// After deletion: 10

// | Feature      | Queue | Deque |
// | ------------ | ----- | ----- |
// | Insert Front | ❌     | ✔     |
// | Insert Rear  | ✔     | ✔     |
// | Delete Front | ✔     | ✔     |
// | Delete Rear  | ❌     | ✔     |
