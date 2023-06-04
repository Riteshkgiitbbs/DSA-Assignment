Suppose an array of length n sorted in ascending order is **rotated** between 1 and n times. For example, the array nums = [0,1,2,4,5,6,7] might become:

- [4,5,6,7,0,1,2] if it was rotated 4 times.
- [0,1,2,4,5,6,7] if it was rotated 7 times.

Notice that **rotating** an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

Given the sorted rotated array nums of **unique** elements, return *the minimum element of this array*.

You must write an algorithm that runs in O(log n) time.

// my code ------------  
  
#include <iostream>
#include <vector>

using namespace std;

int findMin(vector<int>& nums) {
    int s = 0;
    int n = nums.size() - 1;
    int e = n;

    if (n == 0) {
        return nums[0];
    }

    while (s <= e) {
        int mid = s + (e - s) / 2;

        if ((mid < n) && nums[mid + 1] < nums[mid]) {
            return nums[mid + 1];
        }

        if ((mid > 0) && nums[mid - 1] > nums[mid]) {
            return nums[mid];
        }

        if (nums[mid] < nums[e]) {
            e = mid - 1;
        } else if (nums[mid] > nums[e]) {
            s = mid + 1;
        } else {
            e--;
        }
    }

    return nums[0];
}

int main() {
    // Read input from the user
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    // Find the minimum element
    int minElement = findMin(nums);

    // Display the result
    cout << "Minimum element: " << minElement << endl;

    return 0;
}
