<aside>
💡 You are given a large integer represented as an integer array digits, where each
digits[i] is the ith digit of the integer. The digits are ordered from most significant
to least significant in left-to-right order. The large integer does not contain any
leading 0's.

Increment the large integer by one and return the resulting array of digits.

**Example 1:**
Input: digits = [1,2,3]
Output: [1,2,4]

**Explanation:** The array represents the integer 123.
Incrementing by one gives 123 + 1 = 124.
Thus, the result should be [1,2,4].

</aside>
// my code is start from here 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// making a function which return a vector
 vector<int> plusOne(vector<int>& digits) {
        int sum=1;
        int n=digits.size()-1;
        vector<int>v;
        int i=n;
        while(i>=0){
            if(sum+digits[i]>9){
                v.push_back((sum+digits[i])%10);// i can push back directly zero also
                sum=1;
            }else{
                v.push_back(sum+digits[i]);
                sum=0;
            }
            i--;
        }
        if(sum==1){
            v.push_back(1);
        }
        
        reverse(v.begin(),v.end());
        
        return v;
 }
int main(){
    
    // Read input from the user
    int numDigits;
    cout << "Enter the number of digits: ";
    cin >> numDigits;

    vector<int> digits(numDigits);
    cout << "Enter the digits (from left to right): ";
    for (int i = 0; i < numDigits; i++) {
        cin >> digits[i];
    }

    // Call the plusOne function
    vector<int> result = plusOne(digits);

    // Print the result
    cout << "Result: ";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
