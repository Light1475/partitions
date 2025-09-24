/*
Author: Li J.R.
Date: 24 Sep. 2025
Description:
This version of the partitions calculator for number n
uses dynamic programming, where recursive uses of prior
calculated results are summated to determine n partitions.
p(n) = ∑[where k=1]p(n−k)
*/

#include <iostream>
#include <vector>
#include <locale>

using namespace std;

// Function to calculate the number of partions of n
unsigned long long partitionsCounter(int n);

int main(void) {
    int n = 0;

    do {
        cout << "Enter an integer (larger than 0, up to ~10**4): ";
        cin >> n;
    } while (n < 0);

    locale currentLocale("");

    cout.imbue(currentLocale);

    cout << "Number of partitions of " << n << " is: " << partitionsCounter(n) << endl;

    return 0;
}

unsigned long long partitionsCounter(int n) {
    vector<unsigned long long> dp(n + 1);

    dp[0] = 1;

    for (int k = 1; k <= n; k++) {
        for (int i = k; i <= n; i++) {
            dp[i] += dp[i - k];
        }
    }

    return dp[n];
}