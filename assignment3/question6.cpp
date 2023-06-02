Given a non-empty array of integers nums, every element appears twice except
for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only
constant extra space.

Example 1:
Input: nums = [2,2,1]
Output: 1
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int singleNumber(vector<int>& nums) {
    unordered_map<int, int> hash;
    int ans = 0;

    for (int num : nums) {
        hash[num]++;
    }

    for (auto pair : hash) {
        if (pair.second == 1) {
            ans = pair.first;
            break;
        }
    }

    return ans;
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

    int result = singleNumber(nums);

    cout << "The single number in the array is: " << result << endl;

    return 0;
}
