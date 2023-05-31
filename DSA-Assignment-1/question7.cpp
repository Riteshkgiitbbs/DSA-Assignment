<aside>
💡 Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the nonzero elements.

Note that you must do this in-place without making a copy of the array.

**Example 1:**
Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]

</aside>
#include <iostream>
#include <vector>
using namespace std;
void moveZeroes(vector<int>& nums) {
    int n = nums.size();
    int temp[n];
    int last = n - 1;
    int j = 0;

    for (int i = 0; i < n; i++) {
        if (nums[i] != 0) {
            temp[j] = nums[i];
            j++;
        }
        if (nums[i] == 0) {
            temp[last] = nums[i];
            last = last - 1;
        }
    }

    for (int i = 0; i < n; i++) {
        nums[i] = temp[i];
    }
}

int main() {
    // Example usage
    vector<int> nums = {0, 1, 0, 3, 12};

    cout << "Before moving zeroes: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    moveZeroes(nums);

    cout << "After moving zeroes: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
