#include <iostream>
using namespace std;

// Returns starting petrol pump index
int circularTour(int petrol[], int distance[], int n)
{
    int start = 0;      // Candidate starting pump
    int balance = 0;    // Current petrol left
    int deficit = 0;    // Petrol shortage encountered so far

    for (int i = 0; i < n; i++)
    {
        // Petrol gained - Petrol spent
        balance += petrol[i] - distance[i];

        // Cannot reach next pump
        if (balance < 0)
        {
            // Store the shortage
            deficit += balance;

            // Next pump becomes new starting point
            start = i + 1;

            // Reset current balance
            balance = 0;
        }
    }

    // If total petrol is sufficient
    if (balance + deficit >= 0)
        return start;

    return -1;
}

int main()
{
    int petrol[] = {4, 6, 7, 4};
    int distance[] = {6, 5, 3, 5};

    int n = 4;

    cout << circularTour(petrol, distance, n);

    return 0;
}
//Output
1

Dry run

// i=0 : balance=-2 (<0)
//       deficit=-2, start=1, balance=0

// i=1 : balance=1

// i=2 : balance=5

// i=3 : balance=4

// balance + deficit = 4 + (-2) = 2 >= 0
// Answer = 1