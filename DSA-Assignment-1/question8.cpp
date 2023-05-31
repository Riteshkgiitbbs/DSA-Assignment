<aside>
💡 You have a set of integers s, which originally contains all the numbers from 1 to n. 
  Unfortunately, due to some error, one of the numbers in s got duplicated to another number in the set,
which results in repetition of one number and loss of another number.

You are given an integer array nums representing the data status of this set after the error.

Find the number that occurs twice and the number that is missing and return them in the form of an array.

**Example 1:**
Input: nums = [1,2,2,4]
Output: [2,3]

</aside>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> findErrorNums(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int wrongsum = 0;
    long long n = nums.size();
    int first;
    vector<int> ans;
    for (int i = 0; i < nums.size() - 1; i++) {
        if (nums[i] == nums[i + 1]) {
            first = nums[i];
            ans.push_back(first);
        }
    }
    for (int i = 0; i < n; i++) {
        wrongsum += nums[i];
    }
    long long rightsum = n * (n + 1) / 2;

    long long second = rightsum - (wrongsum - first);
    ans.push_back(second);
    return ans;
}

int main() {
    // Read input from the user
    int numElements;
    cout << "Enter the number of elements: ";
    cin >> numElements;
    //taking the element in the nums
    vector<int> nums(numElements);
    cout << "Enter the elements: ";
    for (int i = 0; i < numElements; i++) {
        cin >> nums[i];
    }

    // Call the findErrorNums function
    vector<int> result = findErrorNums(nums);

    // Print the result
    cout << "Result: ";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
