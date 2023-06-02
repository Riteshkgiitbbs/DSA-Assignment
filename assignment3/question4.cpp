Question 4
Given a sorted array of distinct integers and a target value, return the index if the
target is found. If not, return the index where it would be if it were inserted in
order.

You must write an algorithm with O(log n) runtime complexity.

Example 1:
Input: nums = [1,3,5,6], target = 5
Output: 2
  /* -------my code start form here--------------------*/
  // Online C++ compiler to run C++ program online
#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;
int search(vector<int>&nums,int target){
    int s = 0;
    int e = nums.size() - 1;
    int ans = -1;
    
    while (s <= e) {
        int mid = s + (e - s) / 2;
        
        if (nums[mid] == target) {
            ans = mid;
            break;
        } else if (target > nums[mid]) {
            s = mid + 1;
        } else if (target < nums[mid]) {
            e = mid - 1;
        }
    }
    return ans;
}
int searchInsert(vector<int>& nums, int target) {
    
    int index = search(nums,target);
    if(index==-1){
        nums.push_back(target);
        sort(nums.begin(),nums.end());
        index = search(nums,target);
    }
    return index;
    }
    
int main() {
    vector<int> nums;
    int target;

    // User input
    cout << "Enter the size of the array: ";
    int size;
    cin >> size;
    cout << "Enter the array elements: ";
    for (int i = 0; i < size; i++) {
        int num;
        cin >> num;
        nums.push_back(num);
    }
    cout << "Enter the target number: ";
    cin >> target;
    int index=searchInsert(nums,target);
    cout<<endl<<" your result is  " <<index<<endl;

    return 0;
}
