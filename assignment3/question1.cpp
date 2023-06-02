Given an integer array nums of length n and an integer target, find three integers
in nums such that the sum is closest to the target.
Return the sum of the three integers.

You may assume that each input would have exactly one solution.

Example 1:
Input: nums = [-1,2,1,-4], target = 1
Output: 2

Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
  /* ------- my  code start from here------*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int threeSumClosest(vector<int>& nums, int target) {
    int closest = INT_MAX;
    sort(nums.begin(), nums.end());
    if (nums.size() < 3) {
        return 0;
    }
    for (int i = 0; i < nums.size() - 2; i++) {
        int j = i + 1;
        int k = nums.size() - 1;
        while (j < k) {
            int sum = nums[i] + nums[j] + nums[k];
            if (sum == target) {
                return target;
            }
            if (abs(target - sum) < abs(target - closest)) {
                closest = sum;
            }
            if (sum < target) {
                j++;
            } else {
                k--;
            }
        }
    }

    return closest;
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

    int target;
    cout << "Enter the target number: ";
    cin >> target;

    int result = threeSumClosest(nums, target);

    cout << "The closest sum to the target is: " << result << endl;

    return 0;
}
