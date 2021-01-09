//
// Created by heechan on 21. 1. 9..
//
#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

class Solution {
public:
    static int searchInsert(vector<int>& nums, int target)
    {
        // 1. normal brute force
//        for(int i = 0 ; i < nums.size(); i++) {
//            if(nums[i] >= target) {
//                return i;
//            }
//        }
//        return nums.size();

        // 2. binary search
        int l = 0, r = nums.size()-1;
        while (l<=r) {
            int mid = (l+r)/2;
            if (target==nums[mid]) return mid;
            if (target>nums[mid]) l = mid+1;
            else r = mid-1;
        }
        return l;
    }

};

int main()
{
    vector<int> nums{1, 3, 5, 6};
    std::cout << Solution::searchInsert(nums, 4);

    return 0;
}
