#include <iostream>
using namespace std;

// To heapify a subtree rooted with node i
void heapify(int arr[], int n, int i)
{
    int largest = i;        // Initialize largest as root
    int l = 2 * i + 1;      // left child
    int r = 2 * i + 2;      // right child

    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // If largest is not root
    if (largest != i)
    {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected subtree
        heapify(arr, n, largest);
    }
}

// Function to perform Heap Sort
void heapSort(int arr[], int n)
{
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Extract elements from heap one by one
    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);   // Move current root to end
        heapify(arr, i, 0);     // Heapify reduced heap
    }
}

// Function to print array
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Main function
int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    heapSort(arr, n);

    cout << "\nSorted array is:\n";
    printArray(arr, n);

    return 0;
}
