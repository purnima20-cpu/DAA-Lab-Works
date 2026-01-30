#include <iostream>
#include <algorithm>
using namespace std;

// Structure to represent a Job
struct Job
{
    char id;     // Job Id
    int dead;    // Deadline
    int profit;  // Profit
};

// Sort jobs according to decreasing profit
bool comparison(Job a, Job b)
{
    return (a.profit > b.profit);
}

// Function to schedule jobs
void printJobScheduling(Job arr[], int n)
{
    // Sort jobs by profit
    sort(arr, arr + n, comparison);

    int result[n];     // To store result (job indices)
    bool slot[n];      // To keep track of free time slots

    // Initialize all slots as free
    for (int i = 0; i < n; i++)
        slot[i] = false;

    // Iterate through all jobs
    for (int i = 0; i < n; i++)
    {
        // Find a free slot from last possible slot
        for (int j = min(n, arr[i].dead) - 1; j >= 0; j--)
        {
            // Free slot found
            if (slot[j] == false)
            {
                result[j] = i;
                slot[j] = true;
                break;
            }
        }
    }

    // Print job sequence
    for (int i = 0; i < n; i++)
        if (slot[i])
            cout << arr[result[i]].id << " ";
}

// Main function
int main()
{
    int n;
    cout << "Enter number of jobs: ";
    cin >> n;

    Job* arr = new Job[n];

    cout << "Enter Job ID, Deadline and Profit:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].id >> arr[i].dead >> arr[i].profit;
    }

    cout << "\nFollowing is maximum profit sequence of jobs\n";
    printJobScheduling(arr, n);

    delete[] arr;
    return 0;
}
