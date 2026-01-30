#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

// Swap two elements
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to find median of arr[] (size <= 5)
int findMedian(int arr[], int n)
{
    sort(arr, arr + n);
    return arr[n / 2];
}

// Partition array around element x
int partition(int arr[], int l, int r, int x)
{
    int i;
    for (i = l; i < r; i++)
        if (arr[i] == x)
            break;

    swap(&arr[i], &arr[r]);

    i = l;
    for (int j = l; j <= r - 1; j++)
    {
        if (arr[j] <= x)
        {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[r]);
    return i;
}

// Returns k'th smallest element in arr[l..r] in worst-case linear time
int kthSmallest(int arr[], int l, int r, int k)
{
    if (k > 0 && k <= r - l + 1)
    {
        int n = r - l + 1; // Number of elements
        int i, median[(n + 4) / 5]; // Medians of groups

        // Divide arr[] in groups of 5 and find medians
        for (i = 0; i < n / 5; i++)
            median[i] = findMedian(arr + l + i * 5, 5);

        if (i * 5 < n) // For last group with < 5 elements
        {
            median[i] = findMedian(arr + l + i * 5, n % 5);
            i++;
        }

        // Find median of medians
        int medOfMed = (i == 1) ? median[0] : kthSmallest(median, 0, i - 1, i / 2);

        // Partition around median of medians
        int pos = partition(arr, l, r, medOfMed);

        // If position is same as k
        if (pos - l == k - 1)
            return arr[pos];

        if (pos - l > k - 1)
            return kthSmallest(arr, l, pos - 1, k);

        return kthSmallest(arr, pos + 1, r, k - pos + l - 1);
    }

    return INT_MAX; // k is out of bounds
}

int main()
{
    int n, k;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter k (to find k-th smallest element): ";
    cin >> k;

    int result = kthSmallest(arr, 0, n - 1, k);

    if (result == INT_MAX)
        cout << "Invalid k! It should be between 1 and " << n << endl;
    else
        cout << "K-th smallest element is " << result << endl;

    return 0;
}
