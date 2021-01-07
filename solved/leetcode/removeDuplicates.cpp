//
// Created by heechan on 21. 1. 7..
//

#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    static int removeDuplicates(vector<int> &nums) {

        for (auto it = begin(nums); it != end(nums);) {
            if(it == begin)

                if (*it == prevNum) {
                    ret++;
                    prevNum = *it;
                    it = nums.erase(it);
                } else {
                    prevNum = *it;
                    ++it;
                }
        }
        return ret;
    }
};

int main() {
    vector<int> arg1{0,0,1,1,1,2,2,3,3,4};
    std::cout << Solution::removeDuplicates(arg1);
    for (auto &v: arg1) {
        std::cout << v << " ";
    }
    return 0;
}