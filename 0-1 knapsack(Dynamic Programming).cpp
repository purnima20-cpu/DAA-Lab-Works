#include <bits/stdc++.h>
using namespace std;

// Function to return maximum of two numbers
int maxValue(int a, int b)
{
    return (a > b) ? a : b;
}

// 0-1 Knapsack function
int knapSack(int W, int wt[], int val[], int n)
{
    int K[n + 1][W + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
                K[i][w] = 0;

            else if (wt[i - 1] <= w)
                K[i][w] = maxValue(
                    val[i - 1] + K[i - 1][w - wt[i - 1]],
                    K[i - 1][w]
                );

            else
                K[i][w] = K[i - 1][w];
        }
    }

    return K[n][W];
}

int main()
{
    int n;

    cout << "Enter number of items: ";
    cin >> n;

    int val[n], wt[n];

    cout << "Enter values of items:\n";
    for (int i = 0; i < n; i++)
        cin >> val[i];

    cout << "Enter weights of items:\n";
    for (int i = 0; i < n; i++)
        cin >> wt[i];

    int W;
    cout << "Enter capacity of knapsack: ";
    cin >> W;

    int result = knapSack(W, wt, val, n);

    cout << "\nMaximum value that can be obtained: " 
         << result << endl;

    return 0;
}