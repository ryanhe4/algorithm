//
// Created by heechan on 21. 1. 7..
//
#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    static int removeDuplicates(vector<int>& nums)
    {
        int prevNum = 10001;
        int ret = 0;

        for (auto it = begin(nums); it!=end(nums);) {
            if (*it==prevNum) {
                prevNum = *it;
                it = nums.erase(it);
            }
            else {
                ret++;
                prevNum = *it;
                ++it;
            }
        }
        return ret;
    }

    static int removeElement(vector<int>& nums, int val)
    {
        //this is using std:: remove
        auto it = remove(nums.begin(), nums.end(), val);
        nums.resize(it-nums.begin());

        return nums.size();
    }
};

int main()
{
    vector<int> arg1{0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    std::cout << Solution::removeDuplicates(arg1);
    for (auto& v: arg1) {
        std::cout << v << " ";
    }
    return 0;
}