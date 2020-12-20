class Solution {
public:
    int reverse(int x) {
        int rev_x = 0;

        while (x != 0) {
            int mod = x % 10;
            x = x / 10;

            if (rev_x > INT_MAX/10 || (rev_x == INT_MAX / 10 && mod > 7)) return 0;
            if (rev_x < INT_MIN/10 || (rev_x == INT_MIN / 10 && mod < -8)) return 0;
            rev_x = (rev_x * 10) + mod;
        }

        return rev_x;
    }
};
