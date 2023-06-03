<aside>
💡 Given three integer arrays arr1, arr2 and arr3 **sorted** in **strictly increasing** order, return a sorted array of **only** the integers that appeared in **all** three arrays.

**Example 1:**

Input: arr1 = [1,2,3,4,5], arr2 = [1,2,5,7,9], arr3 = [1,3,4,5,8]

Output: [1,5]

**Explanation:** Only 1 and 5 appeared in the three arrays.

</aside>
// my code is start from here
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool ispresent(vector<int> nums, int target) {
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == target) {
            return true;
        }
    }
    return false;
}

int main() {
    vector<int> nums1 = {1,2,3,4,5};
    vector<int> nums2 = {1,2,5,7,9};
    vector<int> nums3 = {1,3,4,5,8};
    vector<int> ans;

    for (int i = 0; i <= nums1.size()-1; i++) {
        if (ispresent(nums2, nums1[i]) && ispresent(nums3, nums1[i])) {
            ans.push_back(nums1[i]);
        }
    }

    sort(ans.begin(), ans.end());

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

    return 0;
}
