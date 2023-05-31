<aside>
💡  Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

**Example 1:**
Input: nums = [1,2,3,1]

Output: true

</aside>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool containsDuplicate(vector<int>& nums) {
    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size() - 1; i++) {
        if (nums[i] == nums[i + 1]) {
            return true;
        }
    }

    return false;
}

int main() {
    // Example usage
    vector<int> nums = {1, 2, 3, 4, 5};
    bool hasDuplicate = containsDuplicate(nums);

    if (hasDuplicate) {
        cout << "The vector contains duplicates." << endl;
    } else {
        cout << "The vector does not contain duplicates." << endl;
    }

    return 0;
}
