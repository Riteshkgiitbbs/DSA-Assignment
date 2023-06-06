Given two strings s and t, *determine if they are isomorphic*.
Two strings s and t are isomorphic if the characters in s can be replaced to get t.
All occurrences of a character must be replaced with another character while preserving the order of characters.
  No two characters may map to the same character, but a character may map to itself.

Example 1:**
Input:** s = "egg", t = "add"
Output:** true
 
 // my code --------
 
#include <iostream>
#include <string>
#include <map>

using namespace std;

bool isIsomorphic(string s, string t) {
    map<char, char> mp, mp1;
    
    if (s.size() != t.size())
        return false;
    
    for (int i = 0; i < s.size(); i++) {
        if (mp.find(s[i]) != mp.end()) {
            if (mp[s[i]] != t[i])
                return false;
        }
        else if (mp1.find(t[i]) != mp1.end()) {
            if (mp1[t[i]] != s[i])
                return false;
        }
        else {
            mp[s[i]] = t[i];
            mp1[t[i]] = s[i];
        }
    }
    
    return true;
}

int main() {
    string s, t;
    cout << "Enter string s: ";
    cin >> s;
    cout << "Enter string t: ";
    cin >> t;
    
    bool result = isIsomorphic(s, t);
    
    if (result)
        cout << "The strings are isomorphic." << endl;
    else
        cout << "The strings are not isomorphic." << endl;
    
    return 0;
}
