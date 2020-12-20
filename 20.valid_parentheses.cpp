#include <string>
#include <iostream>
#include <stack>

using namespace::std;

class Solution {
public:
    bool isValid(string s) {
        if (s.length() == 0) {
            return true;
        }
        if (s.length() < 2) {
            return false;
        }
        stack<char> mem;

        for (auto i : s) {
            if (i == '[' || i == '(' || i == '{') {
                mem.push(i);
            } else {
                if (mem.size() == 0) {
                    return false;
                }
                char openingBrack = mem.top();
                mem.pop();
                bool valid = openingBrack == '(' && i == ')';
                valid = valid || (openingBrack == '{' && i == '}');
                valid = valid || (openingBrack == '[' && i == ']');
                if (!valid) {
                  return false;
                }
            }
        }

        if (mem.size() != 0) {
            return false;
        }

        return true;
    }
};
