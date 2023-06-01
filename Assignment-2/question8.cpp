You are given an integer array nums and an integer k.

In one operation, you can choose any index i where 0 <= i < nums.length and change nums[i] to nums[i] + x where x is an integer from the range [-k, k]. You can apply this operation at most once for each index i.

The score of nums is the difference between the maximum and minimum elements in nums.

Return the minimum score of nums after applying the mentioned operation at most once for each index in it.

Example 1:
Input: nums = [1], k = 0
Output: 0

Explanation: The score is max(nums) - min(nums) = 1 - 1 = 0.
  // my code is starting from here
  #include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minimumScore(vector<int>& nums, int k) {
    int n = nums.size();
    
    // Sort the array in ascending order
    sort(nums.begin(), nums.end());
    
    // Initialize the minimum score with the difference between the maximum and minimum elements
    int minScore = nums[n - 1] - nums[0];
    
    // Check the potential candidates for the minimum score
    for (int i = 0; i < n - 1; i++) {
        int minVal = min(nums[0] + k, nums[i + 1] - k);
        int maxVal = max(nums[n - 1] - k, nums[i] + k);
        minScore = min(minScore, maxVal - minVal);
    }
    
    return minScore;
}

int main() {
    // Input handling
    int n, k;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    cout << "Enter the value of k: ";
    cin >> k;

    // Call the minimumScore function
    int result = minimumScore(nums, k);

    // Output
    cout << "Minimum score of nums: " << result << endl;

    return 0;
}
