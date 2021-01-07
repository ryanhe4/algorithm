//
// Created by yangheechan on 2020-12-07.
//
#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    static void selectionSort(vector<int>& array)
    {
        int min, index, temp;
        for (int i = 0; i<10; i++) {
            min = 9999;
            for (int j = i; j<10; j++) {
                if (min>array[j]) {
                    min = array[j];
                    index = j;
                }
            }
            temp = array[i];
            array[i] = array[index];
            array[index] = temp;
        }
    }
};

int main()
{
    vector<int> array{1, 10, 5, 8, 7, 6, 4, 3, 2, 9};
    Solution::selectionSort(array);

    for (auto& elem: array) {
        std::cout << elem << " ";
    }
    return 0;
}