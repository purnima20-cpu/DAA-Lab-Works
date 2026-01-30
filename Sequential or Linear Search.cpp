#include <iostream>
using namespace std;

// C++ code to linearly search x in arr[]. If x
// is present then return its location, otherwise
// return -1
int linearSearch(int arr[], int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
            return i;   // return index
    }
    return -1;  // not found
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 30;

    int result = linearSearch(arr, n, x);

    if (result != -1)
        cout << "Element found at index " << result;
    else
        cout << "Element not found";

    return 0;
}
