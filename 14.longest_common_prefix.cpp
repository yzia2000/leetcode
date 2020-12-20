#include <string>
#include <iostream>
#include <vector>

using namespace::std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) {
            return "";
        }
        string common = "";
        return divideAndConquer(strs, 0, strs.size() - 1);
    }

    string divideAndConquer(vector<string>& strs, int i, int j) {
        if (i == j) {
            return strs[i];
        } else {
            int mid = (i + j) / 2;
            string prefLeft = divideAndConquer(strs, i, mid);
            string prefRight = divideAndConquer(strs, mid + 1, j);
            return commonPrefix(prefLeft, prefRight);
        }
    }

    string commonPrefix(string s1, string s2) {
        int index = min(s1.length(), s2.length());
        string res = "";
        for (int i = 0; i < index; ++i) {
            if (s1[i] != s2[i]) {
                return res;
            }
            res.push_back(s1[i]);
        }
        return res;
    }
};
