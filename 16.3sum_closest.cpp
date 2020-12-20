#include <iostream>
#include <vector>
#include <string>

using namespace::std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int res = INT_MAX / 2;

        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); ++j) {
                for (int k = j + 1; k < nums.size(); ++k) {
                    if (nums[i] + nums[j] + nums[k] == target) {
                        return target;
                    }
                    if (abs(nums[i] + nums[j] + nums[k] - target) < abs(res - target)) {
                        res = nums[i] + nums[j] + nums[k];
                    }
                } 
            }
        }

        return res;
    }
};
