#include <iostream>
#include <climits>
#include <cstdlib>
using namespace std;

// Swap two elements
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Standard partition process of QuickSort
int partition(int arr[], int l, int r)
{
    int x = arr[r], i = l;
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

// Picks a random pivot element and partitions the array
int randomPartition(int arr[], int l, int r)
{
    int n = r - l + 1;
    int pivot = rand() % n;
    swap(&arr[l + pivot], &arr[r]);
    return partition(arr, l, r);
}

// Returns k'th smallest element in arr[l..r]
int kthSmallest(int arr[], int l, int r, int k)
{
    if (k > 0 && k <= r - l + 1)
    {
        int pos = randomPartition(arr, l, r);

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
