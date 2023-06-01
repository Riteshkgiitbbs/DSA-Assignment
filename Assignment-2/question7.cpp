An array is monotonic if it is either monotone increasing or monotone decreasing.

An array nums is monotone increasing if for all i <= j, nums[i] <= nums[j]. An array nums is
monotone decreasing if for all i <= j, nums[i] >= nums[j].

Given an integer array nums, return true if the given array is monotonic, or false otherwise.

Example 1:
Input: nums = [1,2,2,3]
Output: true
  // my code start from here
  #include <iostream>
#include <vector>

using namespace std;

bool isMonotonic(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) {
        return true;
    }

    int i;
    for (i = 0; i < n - 1; i++) {
        if (nums[i] >= nums[i + 1])
            continue;
        else
            break;
    }

    if (i == n - 1)
        return true;

    for (i = 0; i < n - 1; i++) {
        if (nums[i] <= nums[i + 1])
            continue;
        else
            break;
    }

    if (i == n - 1)
        return true;

    return false;
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

    // Call the isMonotonic function
    bool result = isMonotonic(nums);

    // Output
    cout << "The array is monotonic: " << (result ? "true" : "false") << endl;

    return 0;
}
