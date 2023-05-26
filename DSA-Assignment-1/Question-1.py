"""
💡 **Q1.** Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

**Example:**
Input: nums = [2,7,11,15], target = 9
Output0 [0,1]

**Explanation:** Because nums[0] + nums[1] == 9, we return [0, 1] 
"""

def twosum(nums, target):
    result = []                             # defining the a new array which store the value of i and j
    for i in range(len(nums) - 1):
        for j in range(i + 1, len(nums)):
            if nums[i] + nums[j] == target:
                result.append(i)
                result.append(j)
                break
    return result

nums = [2, 7, 11, 15]
target = 9
result = twosum(nums, target)

if len(result) == 2:
    print(f"[{result[0]}, {result[1]}]")
else:
    print("There is no valid result in the code.")
