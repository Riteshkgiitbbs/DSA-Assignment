Given two integer arrays arr1 and arr2, and the integer d, *return the distance value between the two arrays*.

The distance value is defined as the number of elements arr1[i] such that there is not any element arr2[j] where |arr1[i]-arr2[j]| <= d.

**Example 1:**

**Input:** arr1 = [4,5,8], arr2 = [10,9,1,8], d = 2

**Output:** 2
// my code -----

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
    int count = 0;

    for (int i = 0; i < arr1.size(); i++) {
        bool found = false;

        for (int j = 0; j < arr2.size(); j++) {
            if (abs(arr1[i] - arr2[j]) <= d) {
                found = true;
                break;
            }
        }

        if (!found) {
            count++;
        }
    }

    return count;
}

int main() {
    // Read input from the user
    int n1, n2, d;
    cout << "Enter the size of arr1: ";
    cin >> n1;
    cout << "Enter the size of arr2: ";
    cin >> n2;
    cout << "Enter the distance threshold (d): ";
    cin >> d;

    vector<int> arr1(n1);
    vector<int> arr2(n2);

    cout << "Enter the elements of arr1: ";
    for (int i = 0; i < n1; i++) {
        cin >> arr1[i];
    }

    cout << "Enter the elements of arr2: ";
    for (int i = 0; i < n2; i++) {
        cin >> arr2[i];
    }

    // Calculate the distance value
    int distanceValue = findTheDistanceValue(arr1, arr2, d);

    // Display the result
    cout << "Distance value: " << distanceValue << endl;

    return 0;
}
