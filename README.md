# partitions
Created a partitions calculator for number n (by user input).

### Limitations:
Without the use of the *boost/* library, which I didn't use, the number provided you can provide to the programs is largely limited to ~200. 

## Euler_partitions.cpp
This file includes code inspired from the use of Euler's pentagonal numbers to determine partition numbers. What's seen within the calculating function relates to the following equation:
```math
p(n) = \sum_{k \neq 0} (-1)^{k-1} \, p(n - g_k), \quad 
g_k = \frac{k(3k-1)}{2}, \quad k = \pm 1, \pm 2, \pm 3, \dots
```
Euler's method defines a recurrence relation between partition numbers and generalized pentagongal numbers, more information can be found [here](https://en.wikipedia.org/wiki/Pentagonal_number_theorem).

## dp_partitions.cpp
This version of the program utilises dynamic programming (DP) to compute the number of partitions.  
Let $dp[i]$ represent the number of partitions of the integer $i$. Then:

$dp[i] = \sum_{k=1}^{i} dp[i-k]$

## Usage
Feel free to download the files to your respective directories and run the following:
### 1. Compilation:
``g++ -std=c++17 -O2 METHOD_partitions.cpp -o partitions``
### 2. Run:
``./partitions``
