<aside>
💡 **Question 3**
A permutation of an array of integers is an arrangement of its members into a
sequence or linear order.

For example, for arr = [1,2,3], the following are all the permutations of arr:
[1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].

The next permutation of an array of integers is the next lexicographically greater
permutation of its integer. More formally, if all the permutations of the array are
sorted in one container according to their lexicographical order, then the next
permutation of that array is the permutation that follows it in the sorted container.

If such an arrangement is not possible, the array must be rearranged as the
lowest possible order (i.e., sorted in ascending order).

● For example, the next permutation of arr = [1,2,3] is [1,3,2].
● Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
● While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not
have a lexicographical larger rearrangement.

Given an array of integers nums, find the next permutation of nums.
The replacement must be in place and use only constant extra memory.

**Example 1:**
Input: nums = [1,2,3]
Output: [1,3,2]

</aside>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void nextPermutation(vector<int>& nums) {
    int index = -1;
    int n = nums.size();
    for (int i = n - 1; i > 0; i--) {
        if (nums[i] > nums[i - 1]) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        sort(nums.begin(), nums.end());
    } else {
        for (int i = index + 1; i < n; i++) {
            if (nums[i] > nums[index - 1] && nums[i] < nums[index]) {
                swap(nums[i], nums[index - 1]);
            }
        }
        reverse(nums.begin() + index, nums.end());
    }
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

    nextPermutation(nums);

    cout << "The next permutation is: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

