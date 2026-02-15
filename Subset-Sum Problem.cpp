#include <iostream>
#include <vector>
using namespace std;

int total_nodes = 0;

// Function to print subset
void printSubset(vector<int> &subset) {
    for (int i = 0; i < subset.size(); i++) {
        cout << subset[i] << " ";
    }
    cout << endl;
}

// Backtracking function
void subsetSum(vector<int> &arr, vector<int> &subset, 
               int index, int current_sum, int target) {
    
    total_nodes++;

    // If target achieved
    if (current_sum == target) {
        printSubset(subset);
        return;
    }

    // If sum exceeds target or index out of range
    if (current_sum > target || index >= arr.size()) {
        return;
    }

    // Include current element
    subset.push_back(arr[index]);
    subsetSum(arr, subset, index + 1, current_sum + arr[index], target);

    // Backtrack (exclude current element)
    subset.pop_back();
    subsetSum(arr, subset, index + 1, current_sum, target);
}

int main() {
    int n, target;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter target sum: ";
    cin >> target;

    vector<int> subset;

    cout << "\nSubsets with sum " << target << " are:\n";
    subsetSum(arr, subset, 0, 0, target);

    cout << "\nTotal nodes generated: " << total_nodes << endl;

    return 0;
}