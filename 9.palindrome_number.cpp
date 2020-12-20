#include <cstdint>
#include <iostream>

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        int rev_x = 0;
        int old_x = x;
        while (x != 0) {
            int mod = x % 10;
            x = x / 10;
            if (rev_x >= INT_MAX / 10) {
                return false;
            }
            rev_x = rev_x * 10 + mod;
        }

        std::cout << rev_x << std::endl;

        return rev_x == old_x;
    }
};
