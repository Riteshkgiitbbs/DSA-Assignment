Given an integer array nums, find three numbers whose product is maximum and return the maximum product.
Example 1:
Input: nums = [1,2,3]
Output: 6
 
 /*---------my code is start from here-------------*/
#include <iostream>
class Solution {
public:
    int arrangeCoins(int n) {
        int i = 1;
        int count = 0;
        while (n >= 0) {
            n -= i;
            count++;
            i++;
        }
        return count - 1;
    }
};

int main() {
    Solution solution;
    int n;
    std::cout << "Enter the number of coins: ";
    std::cin >> n;
    int result = solution.arrangeCoins(n);
    std::cout << "Number of complete rows: " << result << std::endl;
    return 0;
}
