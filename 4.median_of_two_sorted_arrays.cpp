#include <sched.h>
#include <vector>
#include <iostream>

using namespace::std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> mergedArray;

        int i = 0, j = 0;

        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] < nums2[j]) {
                mergedArray.push_back(nums1[i]);
                i++;
            } else {
                mergedArray.push_back(nums2[j]);
                j++;
            }
        }

        while (i < nums1.size()) {
            mergedArray.push_back(nums1[i]);
            i++;
        }

        while (j < nums2.size()) {
            mergedArray.push_back(nums2[j]);
            j++;
        }

        if (mergedArray.size() % 2 == 0) {
            int mid = mergedArray.size() / 2;
            return (double) (mergedArray[mid] + mergedArray[mid - 1]) / 2.0;
        } else {
            return mergedArray[mergedArray.size() / 2];
        }

    }
};
