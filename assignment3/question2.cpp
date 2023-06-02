Given an array nums of n integers, return an array of all the unique quadruplets
[nums[a], nums[b], nums[c], nums[d]] such that:
           ● 0 <= a, b, c, d < n
           ● a, b, c, and d are distinct.
           ● nums[a] + nums[b] + nums[c] + nums[d] == target

You may return the answer in any order.

Example 1:
Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
/*------ my code start form here-------*/


#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> result;
    map<vector<int>, int> uniqueQuadruplets;

    for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            int start = j + 1;
            int end = nums.size() - 1;

            while (start < end) {
                long long currentSum = nums[start] + nums[end] + nums[i] * 1ll + nums[j];

                if (currentSum == target) {
                    vector<int> quadruplet = {nums[i], nums[j], nums[start], nums[end]};
                    if (uniqueQuadruplets[quadruplet] == 0) {
                        uniqueQuadruplets[quadruplet] = 1;
                        result.push_back(quadruplet);
                    }
                    start++;
                } else if (currentSum < target) {
                    start++;
                } else {
                    end--;
                }
            }
        }
    }

    return result;
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

    int target;
    cout << "Enter the target number: ";
    cin >> target;

    vector<vector<int>> result = fourSum(nums, target);

    cout << "Quadruplets that sum up to the target:" << endl;
    for (const vector<int>& quadruplet : result) {
        for (int num : quadruplet) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
