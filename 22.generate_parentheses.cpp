#include <string>
#include <iostream>
#include <vector>

using namespace::std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;

        backtrack(res, "", 0, 0, n);

        return res;
    }

    void backtrack(vector<string> &ans, string curr, int open, int close, int max) {
        std::cout << curr << std::endl;
        if (curr.length() == max * 2) {
            ans.push_back(curr);
            return;
        }

        if (open < max)
            backtrack(ans, curr + "(", open + 1, close, max);
        if (close < open)
            backtrack(ans, curr + ")", open, close + 1, max);
    }
};
