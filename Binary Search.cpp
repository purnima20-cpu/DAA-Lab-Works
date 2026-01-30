#include <iostream>
using namespace std;

// Recursive Binary Search function
int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l)
    {
        int mid = l + (r - l) / 2;

        // If element is at mid
        if (arr[mid] == x)
            return mid;

        // If element is smaller than mid, search left
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);

        // Else search right
        return binarySearch(arr, mid + 1, r, x);
    }

    // Element not present
    return -1;
}

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements in sorted order:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int x;
    cout << "Enter element to search: ";
    cin >> x;

    int result = binarySearch(arr, 0, n - 1, x);

    if (result == -1)
        cout << "Element is not present in array" << endl;
    else
        cout << "Element is present at index " << result << endl;

    return 0;
}
