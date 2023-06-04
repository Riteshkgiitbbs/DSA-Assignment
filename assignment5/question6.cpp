Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears **once** or **twice**, return *an array of all the integers that appears **twice***.

You must write an algorithm that runs in O(n) time and uses only constant extra space.
  // my code is start from here
#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<int> findDuplicates(vector<int>& nums) {
    map<int, int> mp;
    vector<int> ans;

    for (auto x : nums) {
        mp[x]++;
    }

    for (auto i : nums) {
        if (mp[i] == 2) {
            mp[i]--;
            ans.push_back(i);
        }
    }

    return ans;
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

    // Find the duplicate elements
    vector<int> duplicates = findDuplicates(nums);

    // Display the result
    cout << "Duplicate elements: ";
    for (int i = 0; i < duplicates.size(); i++) {
        cout << duplicates[i] << " ";
    }
    cout << endl;

    return 0;
}
