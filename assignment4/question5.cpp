You have n coins and you want to build a staircase with these coins. The staircase consists of k rows where the ith row has exactly i coins. The last row of the staircase **may be** incomplete.
Given the integer n, return *the number of **complete rows** of the staircase you will build*.

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
