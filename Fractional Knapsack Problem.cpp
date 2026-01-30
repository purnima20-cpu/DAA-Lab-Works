#include <iostream>
#include <algorithm>
using namespace std;

// Structure for an item
struct Item
{
    int value, weight;

    // Default constructor (IMPORTANT for new Item[n])
    Item()
    {
        value = 0;
        weight = 0;
    }

    // Parameterized constructor
    Item(int v, int w)
    {
        value = v;
        weight = w;
    }
};

// Comparison function to sort items by value/weight ratio
bool cmp(Item a, Item b)
{
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

// Function to solve Fractional Knapsack
double fractionalKnapsack(int W, Item arr[], int n)
{
    // Sort items based on ratio
    sort(arr, arr + n, cmp);

    int currentWeight = 0;
    double finalValue = 0.0;

    for (int i = 0; i < n; i++)
    {
        // Take full item if possible
        if (currentWeight + arr[i].weight <= W)
        {
            currentWeight += arr[i].weight;
            finalValue += arr[i].value;
        }
        // Take fractional part
        else
        {
            int remain = W - currentWeight;
            finalValue += arr[i].value *
                          ((double)remain / arr[i].weight);
            break;
        }
    }

    return finalValue;
}

// Main function
int main()
{
    int n, W;

    cout << "Enter number of items: ";
    cin >> n;

    Item* arr = new Item[n];

    cout << "Enter value and weight of each item:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].value >> arr[i].weight;
    }

    cout << "Enter capacity of knapsack: ";
    cin >> W;

    cout << "Maximum value we can obtain = "
         << fractionalKnapsack(W, arr, n) << endl;

    delete[] arr;
    return 0;
}
