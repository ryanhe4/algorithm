//
// Created by yangheechan on 2020-12-09.
//
#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    static void bubbleSort(vector<int>& array)
    {
        int temp;
        for (int i = 0; i<array.size(); ++i) {
            for (int j = 0; j<9-i; ++j) {
                if (array[j]>array[j+1]) {
                    temp = array[j];
                    array[j] = array[j+1];
                    array[j+1] = temp;
                }
            }
        }
    }
};

int main()
{
    vector<int> array{1, 10, 5, 8, 7, 6, 4, 3, 2, 9};

    Solution::bubbleSort(array);

    for (auto& elem: array) {
        std::cout << elem << " ";
    }

    return 0;
}