<aside>
💡 Given an integer array nums sorted in **non-decreasing** order, return *an array of **the squares of each number** sorted in non-decreasing order*.

**Example 1:**

Input: nums = [-4,-1,0,3,10]

Output: [0,1,9,16,100]

**Explanation:** After squaring, the array becomes [16,1,0,9,100].
After sorting, it becomes [0,1,9,16,100]

</aside>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> result;
        int ans;
        for (int i = 0; i < nums.size(); i++) {
            ans = nums[i] * nums[i];
            result.push_back(ans);
        }
        sort(result.begin(), result.end());
        return result;
    }
};

int main() {
    // Input
    vector<int> nums = {-4, -1, 0, 3, 10};

    // Create an instance of the Solution class
    Solution obj;

    // Call the sortedSquares function
    vector<int> result = obj.sortedSquares(nums);

    // Output
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
