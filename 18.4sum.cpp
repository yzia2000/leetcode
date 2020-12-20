#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace::std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if (nums.size() < 4) {
            return {};
        }

        if (nums.size() == 4) {
            if (accumulate(nums.begin(), nums.end(), 0) == target) {
                return {nums};
            } else {
                return {};
            }
        }
        sort(nums.begin(), nums.end());
        int l = 0, r = nums.size() - 1;
        vector<vector<int>> res;

        for (int i = 0; i < nums.size(); ++i) {
            if (i > 0 && nums[i] == nums[i-1]) {
                continue;
            }
            for (int j = i + 1; j < nums.size(); ++j) {
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }

                //std::cout << nums[i] << std::endl;
                l = j + 1;
                r = nums.size() - 1;

                while (l < r) {
                    int currSum = nums[i] + nums[j] + nums[l] + nums[r];

                    //std::cout << nums[i] << " " << nums[j] << " " << nums[l] << " " << nums[r] << std::endl;

                    if (currSum < target) {
                        l++;
                    } else if (currSum > target) {
                        r--;
                    } else {
                        res.push_back({nums[i], nums[j], nums[l], nums[r]});
                        r--;
                        l++;

                        while (l < r && nums[r] == nums[r + 1]) {
                            r--;
                        }

                        while (l < r && nums[l] == nums[l - 1]) {
                            l++;
                        }
                    }
                }
            }
        }
        return res;
    }
};
