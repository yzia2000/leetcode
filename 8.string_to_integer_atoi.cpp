#include <iostream>
#include <string>

using namespace::std;

class Solution {
public:
    int myAtoi(string str) {
        bool numberBegins = false;
        int num = 0;
        bool isNeg = false;

        for (auto ch : str) {
            if (numberBegins) {
                if (ch <= '9' && ch >= '0') {
                    if (num == INT_MAX/10 && ch <= '7' && ch >= '0') {
                        num = num * 10 + (ch - '0');
                        return isNeg ? -num : num;
                    } else if (num >= INT_MAX/10) {
                        return isNeg ? INT_MIN : INT_MAX;
                    }
                    num = num * 10 + (ch - '0');
                } else {
                    return isNeg ? -num : num;
                }
            } else {
                if (ch == '+') {
                    numberBegins = true;
                } else if (ch == '-') {
                    isNeg = true;
                    numberBegins = true;
                } else if (ch >= '0' && ch <= '9') {
                    numberBegins = true;
                    num = ch - '0';
                } else if (ch != ' ') {
                    return num;
                }
            }
        }
        return isNeg ? -num : num;
    }
};
