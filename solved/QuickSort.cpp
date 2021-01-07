//
// Created by yangheechan on 2020-12-19.
// O(N*logN) => Best Case
// O(N^2) => Worst Case

#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    static void quickSort(vector<int>& data, int start, int end)
    {
        if (start>=end) { // 원소가 1개인 경우
            return;
        }
        int key = start; // 키는 첫번째 원소
        int i = start+1;
        int j = end;

        while (i<=j) {
            while (data[i]<=data[key]) { // 키 값보다 큰 값을 만날때 까지
                i++;
            }
            while (data[j]>=data[key] && j>start) { // 키 값보다 작은 값을 만날 때 까지
                j--;
            }

            if (i>j) {
                std::swap(data[j], data[key]);
            } else {
                std::swap(data[j], data[i]);
            }
        }
        quickSort(data, start, j-1);
        quickSort(data, j+1, end);

    }
};

int main()
{
    vector<int> array{1, 10, 5, 8, 7, 6, 4, 3, 2, 9};

    Solution::quickSort(array, 0 , array.size()-1);

    for (auto& elem: array) {
        std::cout << elem << " ";
    }

    return 0;
}
