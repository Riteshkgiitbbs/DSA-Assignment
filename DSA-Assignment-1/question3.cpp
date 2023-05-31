<aside>
💡 **Q3.** Given a sorted array of distinct integers and a target value, return the index if the target is found.
  If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.

**Example 1:**
Input: nums = [1,3,5,6], target = 5

Output: 2

</aside>
// my code start from here
#include <iostream>
#include <vector>
using namespace std;
int searchInsert(vector<int>& nums, int target) {
        int s=0;
        int e=nums.size()-1;
        int mid=s+(e-s)/2;
        int ans=-1;
        while(s<=e){
             if(nums[mid]==target){
            ans=mid;
             }
            else if(target>nums[mid]){
            s=mid+1;
            }
            else if(target<nums[mid]){
            e=mid-1;
            }
             mid=s+(e-s)/2;
        }  
        return ans;
    }
int main(){
    vector<int> nums = {3,2,5,3};
    int target = 5;
    int searchindex=searchInsert(nums,target);
    cout<<"this is the index where our target value is the present "<<searchindex;
    return 0;
}
