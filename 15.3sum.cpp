#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace::std;

class Solution {
    public:
        vector<vector<int>> threeSum(vector<int>& nums) {
            vector<vector<int>> res;
            sort(nums.begin(), nums.end());

            int r = 0, l = 0;

            for (int i = 0; i < nums.size(); ++i) {
                if (i > 0 && nums[i] == nums[i - 1]) {
                    continue;
                }
                l = i + 1;
                r = nums.size() - 1;
                int val = -nums[i];

                while (l < r) {
                    if (nums[r] + nums[l] > val) {
                        r--;
                    } else if (nums[r] + nums[l] < val) {
                        l++;
                    } else {
                        res.push_back({nums[i], nums[l], nums[r]});
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
            return res;
        }
};
