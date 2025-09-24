/*
Author: Li J.R.
Date: 24 Sep. 2025
Description:
This version of the partitions calculator for number n
uses the a form of Euler's pentagonal number recurrence,
where p(n) = ∑​(−1)^k+1(p(n−g1​)+p(n−g2​))
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
    vector<unsigned long long> p(n + 1);

    p[0] = 1;

    for (int i = 1; i <= n; i++) {
        long long total = 0;
        for (int m = 1; ; m++) {

            // Calculate g(m), the generalized pentagonal numbers
            int g1 = m * (3 * m - 1) / 2;
            int g2 = m * (3 * m + 1) / 2;
            if (g1 > i) break;

            int sign = (m % 2 == 0 ? -1 : 1);   // Check the sign alternation by pairs

            total += sign * p[i - g1];          // assign signage to value added to total

            if (g2 <= i)
                total += sign * p[i - g2];
        }
        p[i] = total;
    }

    return p[n];
}