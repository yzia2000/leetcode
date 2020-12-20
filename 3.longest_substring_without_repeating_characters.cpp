#include <iostream>
#include <unordered_set>

using namespace::std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> count;
        int res = 0;
        int i = 0, j = 0;

        int n = s.length();

        while (i < n && j < n) {
            if (count.find(s[j]) == count.end()) {
                count.insert(s[j++]);
                res = max(res, j - i);
            } else {
                count.erase(s[i++]);
            }
        } 
        return res;
    }
};
