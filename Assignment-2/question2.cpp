Question 2
Alice has n candies, where the ith candy is of type candyType[i]. Alice noticed that she started to gain weight, so she visited a doctor. 

The doctor advised Alice to only eat n / 2 of the candies she has (n is always even). Alice likes her candies very much, and she wants to eat the maximum number of different types of candies while still following the doctor's advice. 

Given the integer array candyType of length n, return the maximum number of different types of candies she can eat if she only eats n / 2 of them.

Example 1:
Input: candyType = [1,1,2,2,3,3]
Output: 3

Explanation: Alice can only eat 6 / 2 = 3 candies. Since there are only 3 types, she can eat one of each type.

  
/*-------my code starts from here---------------*/  
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int distributeCandies(vector<int>& candyType) {
    sort(candyType.begin(), candyType.end());
    int count = 1;
    int ans;
    int n = candyType.size() / 2;
    
    for (int i = 0; i < candyType.size() - 1; i++) {
        if (candyType[i] != candyType[i + 1]) {
            count++;
        }
    }  
    
    if (count > n) {
        ans = n;
    } else {
        ans = count;
    }
    
    return ans;
}

int main() {
    // Input handling
    int n;
    cout << "Enter the number of candies: ";
    cin >> n;

    vector<int> candyType(n);
    cout << "Enter the types of candies: ";
    for (int i = 0; i < n; i++) {
        cin >> candyType[i];
    }

    // Call the distributeCandies function
    int result = distributeCandies(candyType);

    // Output
    cout << "Maximum number of different types of candies Alice can eat: " << result << endl;

    return 0;
}
