Convert 1D Array Into 2D Array

You are given a **0-indexed** 1-dimensional (1D) integer array original, and two integers, m and n. You are tasked with creating a 2-dimensional (2D) array with  m rows and n columns using **all** the elements from original.

The elements from indices 0 to n - 1 (**inclusive**) of original should form the first row of the constructed 2D array, the elements from indices n to 2 * n - 1 (**inclusive**) should form the second row of the constructed 2D array, and so on.

Return *an* m x n *2D array constructed according to the above procedure, or an empty 2D array if it is impossible*
**input:** original = [1,2,3,4], m = 2, n = 2

**Output:** [[1,2],[3,4]]

**Explanation:** The constructed 2D array should contain 2 rows and 2 columns.

The first group of n=2 elements in original, [1,2], becomes the first row in the constructed 2D array.

The second group of n=2 elements in original, [3,4], becomes the second row in the constructed 2D array

/*------- my code start from here-----*/
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
    if (original.size() != m * n) {
        return {}; // Return an empty 2D array
    }

    vector<vector<int>> result;
    int x = 0;

    for (int i = 0; i < m; i++) {
        vector<int> row;

        for (int j = 0; j < n; j++) {
            row.push_back(original[x]);
            x++;
        }

        result.push_back(row);
    }

    return result;
}

int main() {
    // Read input from the user
    int m, n;
    cout << "Enter the number of rows (m): ";
    cin >> m;
    cout << "Enter the number of columns (n): ";
    cin >> n;

    vector<int> original(m * n);
    cout << "Enter the elements of the array:\n";
    for (int i = 0; i < m * n; i++) {
        cin >> original[i];
    }

    // Construct the 2D array by calling my fucntion
    vector<vector<int>> result = construct2DArray(original, m, n);

    // Display the result
    cout << "Result:\n";
    for (const vector<int>& row : result) {
        for (int element : row) {
            cout << element << " ";
        }
        cout << endl;
    }

    return 0;
}
