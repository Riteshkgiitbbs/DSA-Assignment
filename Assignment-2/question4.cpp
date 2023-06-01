You have a long flowerbed in which some of the plots are planted, and some are not.
However, flowers cannot be planted in adjacent plots.
Given an integer array flowerbed containing 0's and 1's, where 0 means empty and 1 means not empty, and an integer n, return true if n new flowers can be planted in the flowerbed without violating the no-adjacent-flowers rule and false otherwise.

Example 1:
Input: flowerbed = [1,0,0,0,1], n = 1
Output: true
#include <iostream>
#include <vector>

using namespace std;

bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    int count = 0;
    int size = flowerbed.size();
    
    for (int i = 0; i < size; i++) {
        if (flowerbed[i] == 0) {
            if ((i == 0 || flowerbed[i - 1] == 0) && (i == size - 1 || flowerbed[i + 1] == 0)) {
                count++;
                flowerbed[i] = 1;  // Mark the current position as planted
            }
        }
    }
    
    return count >= n;
}

int main() {
    vector<int> flowerbed = {1, 0, 0, 0, 1};
    int n = 1;
    
    bool canPlace = canPlaceFlowers(flowerbed, n);
    
    cout << "Can place flowers: " << (canPlace ? "Yes" : "No") << endl;
    
    return 0;
}
