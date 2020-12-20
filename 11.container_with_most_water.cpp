#include <exception>
#include <iostream>
#include <vector>

using namespace::std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int area = 0, i = 0, j = height.size() - 1;

        while (i < j) {
            area = max(area, (j-i) * min(height[i], height[j]));

            if (height[i] < height[j]) {
                i++;
            } else {
                j--;
            }
        }

        return area;
    }
};
