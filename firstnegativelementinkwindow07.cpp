#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Function to find the first negative integer in every window of size k
vector<int> firstNegative(vector<int> &arr, int k)
{
    vector<int> ans;      // Stores the answer for each window
    queue<int> q;         // Stores indices of negative elements

    int n = arr.size();

    // -------------------- Process the first window --------------------

    for (int i = 0; i < k; i++)
    {
        // If current element is negative,
        // store its index in the queue
        if (arr[i] < 0)
        {
            q.push(i);
        }
    }

    // Store answer for the first window
    if (q.empty())
    {
        // No negative element found
        ans.push_back(0);
    }
    else
    {
        // First negative element is at the front index
        ans.push_back(arr[q.front()]);
    }

    // -------------------- Process remaining windows --------------------

    for (int i = k; i < n; i++)
    {
        // Current window is:
        // [ i-k+1 ........ i ]

        // Remove indices that have gone outside the current window
        while (!q.empty() && q.front() < (i - k + 1))
        {
            q.pop();
        }
    //   i → points to the new element entering the window.
    //   i - k + 1 → gives the start (left boundary) of the current window.
    //   We remove indices that are before i - k + 1.
    //  We add the new element at i if it satisfies the condition (negative in this problem).
    // The front of the queue always gives the answer for the current window.

        // If the newly entered element is negative,
        // store its index
        if (arr[i] < 0)
        {
            q.push(i);
        }

        // Store answer for the current window
        if (q.empty())
        {
            // No negative element in this window
            ans.push_back(0);
        }
        else
        {
            // Front of the queue is the first negative element
            ans.push_back(arr[q.front()]);
        }
    }

    return ans;
}

int main()
{
    vector<int> arr = {12, -1, -7, 8, -15, 30, 16, 28};
    int k = 3;

    vector<int> ans = firstNegative(arr, k);

    cout << "First negative integer in every window:\n";

    for (int x : ans)
    {
        cout << x << " ";
    }

    return 0;
}
//output
// -1 -1 -7 -15 -15 0



Queue Visualization
Window 0-2
12  -1  -7
     ↑    ↑
Queue
[1,2]
Answer = arr[1]
↓
Window 2-4
-7   8  -15
 ↑       ↑
Queue
[2,4]
Answer = arr[2]
↓
Window 5-7
30 16 28
Queue
[]
Answer = 0
C++ Code (Properly Commented)



  // bruteforce approach


  #include <iostream>
#include <vector>
using namespace std;

// Function to find first negative integer in every window (Brute Force)
vector<int> firstNegative(vector<int> &arr, int k)
{
    vector<int> ans;
    int n = arr.size();

    // Traverse every possible window
    for (int i = 0; i <= n - k; i++)
    {
        bool found = false;

        // Check every element inside the current window
        for (int j = i; j < i + k; j++)
        {
            // First negative element found
            if (arr[j] < 0)
            {
                ans.push_back(arr[j]);
                found = true;
                break;          // No need to check further
            }
        }

        // No negative element in this window
        if (!found)
        {
            ans.push_back(0);
        }
    }

    return ans;
}

int main()
{
    vector<int> arr = {12, -1, -7, 8, -15, 30, 16, 28};
    int k = 3;

    vector<int> ans = firstNegative(arr, k);

    cout << "Answer: ";

    for (int x : ans)
    {
        cout << x << " ";
    }

    return 0;
}


Approach                	Time            	Auxiliary Space
Brute Force	            O((n-k+1) × k)  	O(1)
Queue + Sliding Window	O(n)	            O(k)
  
