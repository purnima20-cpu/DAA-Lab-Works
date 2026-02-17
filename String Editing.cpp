#include <bits/stdc++.h>
using namespace std;

// Function to find minimum of three numbers
int minimum(int x, int y, int z)
{
    return min(min(x, y), z);
}

// Function to calculate Edit Distance
int editDistDP(string str1, string str2, int m, int n)
{
    int dp[m + 1][n + 1];

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            // If first string is empty
            if (i == 0)
                dp[i][j] = j;

            // If second string is empty
            else if (j == 0)
                dp[i][j] = i;

            // If last characters are same
            else if (str1[i - 1] == str2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];

            // If characters are different
            else
                dp[i][j] = 1 + minimum(
                                    dp[i][j - 1],    // Insert
                                    dp[i - 1][j],    // Remove
                                    dp[i - 1][j - 1] // Replace
                                );
        }
    }

    return dp[m][n];
}

int main()
{
    string str1, str2;

    cout << "Enter first string: ";
    cin >> str1;

    cout << "Enter second string: ";
    cin >> str2;

    int result = editDistDP(str1, str2, str1.length(), str2.length());

    cout << "\nMinimum number of operations required: " << result << endl;

    return 0;
}