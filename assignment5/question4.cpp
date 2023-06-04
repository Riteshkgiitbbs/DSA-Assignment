Given two **0-indexed** integer arrays nums1 and nums2, return *a list* answer *of size* 2 *where:*
- answer[0] *is a list of all **distinct** integers in* nums1 *which are **not** present in* nums2*.*
- answer[1] *is a list of all **distinct** integers in* nums2 *which are **not** present in* nums1.
Note** that the integers in the lists may be returned in **any** order.

Example 1:**
**Input:** nums1 = [1,2,3], nums2 = [2,4,6]
**Output:** [[1,3],[4,6]]
**Explanation:**
For nums1, nums1[1] = 2 is present at index 0 of nums2, whereas nums1[0] = 1 and nums1[2] = 3 are not present in nums2.
  Therefore, answer[0] = [1,3].
For nums2, nums2[0] = 2 is present at index 1 of nums1, whereas nums2[1] = 4 and nums2[2] = 6 are not present in nums2. 
  Therefore, answer[1] = [4,6].

  
  
  
  // my code---***********------ start from here
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isPresent(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) {
                return true;
            }
        }
        return false;
    }

    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans1;
        vector<int> ans2;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        for (int i = 0; i < nums1.size(); i++) {
            if (!isPresent(nums2, nums1[i])) {
                ans1.push_back(nums1[i]);
            }
        }
        
        for (int i = 0; i < nums2.size(); i++) {
            if (!isPresent(nums1, nums2[i])) {
                ans2.push_back(nums2[i]);
            }
        }
        ans1.erase(unique(ans1.begin(), ans1.end()), ans1.end());
        ans2.erase(unique(ans2.begin(), ans2.end()), ans2.end());
        return {ans1, ans2};
    }
};

int main() {
    Solution solution;
    
    // Input
    vector<int> nums1 = {1, 2, 3, 3};
    vector<int> nums2 = {1, 1, 2, 2};

    // Function call
    vector<vector<int>> result = solution.findDifference(nums1, nums2);

    // Output
    cout << "Distinct integers in nums1 not present in nums2: [";
    for (int num : result[0]) {
        cout << num << " ";
    }
    cout << "]" << endl;

    cout << "Distinct integers in nums2 not present in nums1: [";
    for (int num : result[1]) {
        cout << num << " ";
    }
    cout << "]" << endl;

    return 0;
}

