You are given an m x n matrix M initialized with all 0's and an array of operations ops,
where ops[i] = [ai, bi] means M[x][y] should be incremented by one for all 0 <= x < ai and 0 <= y < bi.

Count and return *the number of maximum integers in the matrix after performing all the operations*

**Example 1:**

![q4.jpg](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/4d0890d0-7bc7-4f59-be8e-352d9f3c1c52/q4.jpg)

**Input:** m = 3, n = 3, ops = [[2,2],[3,3]]

**Output:** 4

**Explanation:** The maximum integer in M is 2, and there are four of it in M. So return 4.

/*----------- my code start from here---------*/
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int maxCount(int m, int n, vector<vector<int>>& ops) {
    if (ops.empty()) return m * n;
    int min1 = INT_MAX;
    int min2 = INT_MAX;
    for (vector<int> v : ops) {
        if (v[0] < min1) min1 = v[0];
        if (v[1] < min2) min2 = v[1];
    }
    return min1 * min2;
}

int main() {
    // Input
    int m = 3;
    int n = 4;
    vector<vector<int>> ops = {{2, 2}, {3, 3}};

    // Call the maxCount function
    int result = maxCount(m, n, ops);

    // Output
    cout << result << endl;

    return 0;
}
