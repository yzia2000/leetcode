#include <string>
#include <iostream>

using namespace::std;

class Solution {
public:
    int romanToInt(string s) {
        int res = 0;

        while (s.length() != 0) {
            if (s[0] == 'C' && s[1] == 'D') {
                res = res + 400;
                s.erase(0, 2);
            } else if (s[0] == 'C' && s[1] == 'M') {
                res = res + 900;
                s.erase(0, 2);
            } else if (s[0] == 'X' && s[1] == 'L') {
                res = res + 40;
                s.erase(0, 2);
            } else if (s[0] == 'X' && s[1] == 'C') {
                res = res + 90;
                s.erase(0, 2);
            } else if (s[0] == 'I' && s[1] == 'V') {
                res = res + 4;
                s.erase(0, 2);
            } else if (s[0] == 'I' && s[1] == 'X') {
                res = res + 9;
                s.erase(0, 2);
            } else if (s[0] == 'M') {
                res = res + 1000;
                s.erase(0, 1);
            } else if (s[0] == 'D') {
                res = res + 500;
                s.erase(0, 1);
            } else if (s[0] == 'C') {
                res = res + 100;
                s.erase(0, 1);
            } else if (s[0] == 'L') {
                res = res + 50;
                s.erase(0, 1);
            } else if (s[0] == 'X') {
                res = res + 10;
                s.erase(0, 1);
            } else if (s[0] == 'V') {
                res = res + 5;
                s.erase(0, 1);
            } else if (s[0] == 'I') {
                res = res + 1;
                s.erase(0, 1);
            }
        }
        return res;
    }
};
