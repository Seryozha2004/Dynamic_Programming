# Dynamic_Programming

# Fibonacci Dynamic Programming

This project compares 2 dynamic programming ways to compute the n-th Fibonacci number:
- **Recursive with Memorization** (Top-Down)
- **Iterative with Memorization** (Bottom-Up)

### 1. Recursive + Memorization
- Uses recursion + a memo array.
- Avoids redundant calls.

### 2. Iterative Tabulation
- Uses a loop to fill values from 0 to n.
- No recursion.

## Performance
First method works faster than second.

---


# Factorial Dynamic Programming

This project compares 2 methods for calculatiing the factorial of n using:

- **Recursive with Memorization**
- **Iterative loop based approach**


### 1. Recursive + Memorization
- Top-down approach with caching.
- Avoids redundant computations.

### 2. Iterative
- Simple for loop from 2 to n
- No recursion or extra memory


### Performance
Second method works faster than first.



# Climbing Stairs

This project solves "Climbing Stairs" problem in 2 ways:

- **Recursive With Memorization**
- **Iterative Tabulation**


### 1. Recursive + Memorization
- Top-down approach
- Uses recursion and a memo array

### 2. Iterative Tabulation
- Bottom-up approach
- Fills a dp array from step 1 to n


### Performance
First method works faster than second



# Grid Unique Paths

This project computes the number of distinct paths from the top-left corner to the bottom-right corner of an mxn grid.
At each step you can move only right or down.


### Solution
We use iterative dynamic programming with a 2D array dp[m][n] where
- dp[i][j] = number number of unique paths to ceil (i-1, j-1)
- dp[0][j] = 1 for all j (only right moves)
- dp[i][0] = 1 for all i (only down moves)
- dp[i][j] = dp[i-1][j] + dp[i][j-1];
