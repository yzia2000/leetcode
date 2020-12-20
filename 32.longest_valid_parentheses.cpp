#include <string>
#include <iostream>
#include <stack>

using namespace::std;

class Solution {
public:
    int longestValidParentheses(string s) {

        int count = 0, curr_max = 0;
        
        int l = 0, r = 0;

        while (r < s.length()) {
            string sub = s.substr(l, r - l + 1);
            std::cout << sub << std::endl;
            std::cout << l << " " << r << std::endl;
            bool isValid = true;
            int open = 0;
            for (auto i : sub) {
                open = i == '(' ? open + 1 : open - 1;
            }

            if (open > 0) {
                r++;
            }

            if (curr_max > count) {
                count = curr_max;
            }
        }

        return count;
    }
};
