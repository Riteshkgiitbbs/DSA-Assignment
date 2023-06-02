Question 7
You are given an inclusive range [lower, upper] and a sorted unique integer array
nums, where all elements are within the inclusive range.

A number x is considered missing if x is in the range [lower, upper] and x is not in
nums.

Return the shortest sorted list of ranges that exactly covers all the missing
numbers. That is, no element of nums is included in any of the ranges, and each
missing number is covered by one of the ranges.

Example 1:
Input: nums = [0,1,3,50,75], lower = 0, upper = 99
Output: [[2,2],[4,49],[51,74],[76,99]]

Explanation: The ranges are:
[2,2]
[4,49]
[51,74]
[76,99]
/*-------my code start from here-----*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> summaryRanges(vector<int>& nums) {
    vector<string> ranges;

    for (int i = 0; i < nums.size(); i++) {
        int start = nums[i];
        // Keep iterating until the next element is one more than the current element.
        while (i + 1 < nums.size() && nums[i] + 1 == nums[i + 1]) {
            i++;
        }

        if (start != nums[i]) {
            ranges.push_back(to_string(start) + "->" + to_string(nums[i]));
        } else {
            ranges.push_back(to_string(start));
        }
    }

    return ranges;
}

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    vector<int> nums(size);
    cout << "Enter the array elements: ";
    for (int i = 0; i < size; i++) {
        cin >> nums[i];
    }

    vector<string> result = summaryRanges(nums);

    cout << "Summary ranges:" << endl;
    for (const string& range : result) {
        cout << range << endl;
    }

    return 0;
}
