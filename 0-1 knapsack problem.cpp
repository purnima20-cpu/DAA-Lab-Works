#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item {
    int id;
    double weight;
    double profit;
    double ratio;
};

double maxProfit = 0;
vector<int> bestSet;

// Compare items by profit/weight ratio (descending)
bool compare(Item a, Item b) {
    return a.ratio > b.ratio;
}

// Bounding function
double bound(vector<Item>& items, int n, double capacity,
             double currentWeight, double currentProfit, int level) {
    
    double remaining = capacity - currentWeight;
    double profitBound = currentProfit;

    while (level < n && items[level].weight <= remaining) {
        remaining -= items[level].weight;
        profitBound += items[level].profit;
        level++;
    }

    // Take fraction of next item (for bound only)
    if (level < n) {
        profitBound += items[level].ratio * remaining;
    }

    return profitBound;
}

// Backtracking function
void knapsack(vector<Item>& items, int n, double capacity,
              vector<int>& currentSet, double currentWeight,
              double currentProfit, int level) {

    if (level == n) {
        if (currentProfit > maxProfit) {
            maxProfit = currentProfit;
            bestSet = currentSet;
        }
        return;
    }

    // Try including item
    if (currentWeight + items[level].weight <= capacity) {
        currentSet[items[level].id] = 1;
        knapsack(items, n, capacity, currentSet,
                 currentWeight + items[level].weight,
                 currentProfit + items[level].profit,
                 level + 1);
        currentSet[items[level].id] = 0; // backtrack
    }

    // Check bound before excluding
    if (bound(items, n, capacity, currentWeight, currentProfit, level + 1) > maxProfit) {
        knapsack(items, n, capacity, currentSet,
                 currentWeight, currentProfit,
                 level + 1);
    }
}

int main() {
    int n;
    double capacity;

    cout << "Enter number of items: ";
    cin >> n;

    vector<double> weights(n), profits(n);

    cout << "Enter weights:\n";
    for (int i = 0; i < n; i++)
        cin >> weights[i];

    cout << "Enter profits:\n";
    for (int i = 0; i < n; i++)
        cin >> profits[i];

    cout << "Enter knapsack capacity: ";
    cin >> capacity;

    vector<Item> items(n);
    for (int i = 0; i < n; i++) {
        items[i].id = i;
        items[i].weight = weights[i];
        items[i].profit = profits[i];
        items[i].ratio = profits[i] / weights[i];
    }

    sort(items.begin(), items.end(), compare);

    vector<int> currentSet(n, 0);
    bestSet.resize(n);

    knapsack(items, n, capacity, currentSet, 0, 0, 0);

    cout << "\nMaximum Profit: " << maxProfit << endl;
    cout << "Selected items:\n";
    for (int i = 0; i < n; i++) {
        if (bestSet[i] == 1) {
            cout << "Item " << i 
                 << " (Weight = " << weights[i] 
                 << ", Profit = " << profits[i] << ")\n";
        }
    }

    return 0;
}