We define a harmonious array as an array where the difference between its maximum value
and its minimum value is exactly 1.

Given an integer array nums, return the length of its longest harmonious subsequence
among all its possible subsequences.

A subsequence of an array is a sequence that can be derived from the array by deleting some or no elements without changing the order of the remaining elements.

Example 1:
Input: nums = [1,3,2,2,5,2,3,7]
Output: 5

Explanation: The longest harmonious subsequence is [3,2,2,2,3].
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int findLHS(vector<int>& nums) {
    unordered_map<int, int> tmp;
    int maxSub = 0;
    
    for (auto num : nums) {
        ++tmp[num];
    }
    
    for (auto &[num, value] : tmp) {
        if (tmp.find(num - 1) != tmp.end()) {
            if (maxSub < tmp[num - 1] + value) {
                maxSub = tmp[num - 1] + value;
            }
        }
    }
    
    return maxSub;
}

int main() {
    // Input handling
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    // Call the findLHS function
    int result = findLHS(nums);

    // Output
    cout << "Length of the longest harmonious subsequence: " << result << endl;

    return 0;
}

