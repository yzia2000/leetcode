#include <string>
#include <iostream>
#include <tuple>
#include <vector>
#include <unordered_set>

using namespace::std;

typedef tuple <int, int> cord;

class Solution {
    public:
        string longestPalindrome(string s) {
            if (s == "") {
                return "";
            }

            vector<vector<int>> dpPal(s.length(), vector<int>(s.length(), 0));

            int n = s.length();
            string longPal;

            longPal.push_back(s[0]);

            if (s.length() == 1) {
                return s;
            }

            if (s.length() == 2 ) {
                if (s[0] == s[1]) {
                    return s;
                } else {
                    return longPal;
                }
            }

            char dupCheck = s[0];
            bool isDup = true;

            for (int k = 0; k < s.length(); k++) {
                for (int i = 0; i < s.length() - k ; i++) {
                    if (dupCheck != s[i]) {
                        isDup = false;
                    }
                    int j = i + k;
                    if (i == j) {
                        dpPal[i][j] = 1;
                    } else if (j - i == 1 && s[i] == s[j]) {
                        dpPal[i][j] = 1;
                        longPal = s.substr(i, j - i + 1);
                    } else if (dpPal[i + 1][j - 1] && s[i] == s[j]) {
                        dpPal[i][j] = 1;
                        longPal = s.substr(i, j - i + 1);
                    } 
                }
                if (isDup == true) {
                    return s;
                }
            }

            return longPal;
        }

        bool isPalindrome(string s) {
            for (int i = 0; i < s.length() / 2; i++) {
                if (s[i] != s[s.length() - 1 - i]) {
                    return false;
                }
            }
            return true;
        }
};
