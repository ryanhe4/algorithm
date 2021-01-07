//
// Created by heechan on 21. 1. 8..
//
#include <iostream>
#include <vector>

using std::vector;

vector<int> a{7, 6, 5, 8, 3, 5, 9, 1, 6};
vector<int> s(a.size());

class Solution {
public:
    static void mergeSort(vector<int> &array, int first, int end) {
        if (first < end) { //2개 이상일 때 분
            int middle = (first + end) / 2;
            mergeSort(array, first, middle);
            mergeSort(array, middle + 1, end);
            merge(array, first, middle, end);
        }
    }

    static bool binSearch(vector<int> &array, int value, int start, int end) {

        bool ret = false;

        if (start < end) {
            int middle = (start + end) / 2;

            if (value == array[middle]) {
                return true;
            }

            if (value < array[middle]) {
                ret = binSearch(array, value, start, middle);
            } else {
                ret = binSearch(array, value, middle + 1, end);
            }
        } else if (start == end) {
            return value == array[start];
        }
        return ret;
    }

private:
    static void merge(vector<int> &array, int first, int middle, int end) {
        int i = first;
        int key = first;
        int j = middle + 1;

        while (i <= middle && j <= end) {
            if (array[i] <= array[j]) {
                s[key] = array[i];
                i++;
            } else {
                s[key] = array[j];
                j++;
            }
            key++;
        }

        if (i > middle) {
            // 반복하며 나머지 j값을
            for (int k = j; k <= end; k++) {
                s[key] = array[k];
                key++;
            }
        } else {
            // 반복하며 나머지 i값을
            for (int k = i; k <= middle; k++) {
                s[key] = array[k];
                key++;
            }
        }
        for (int t = first; t <= end; t++) {
            array[t] = s[t];
        }
    }
};

int main() {
    //vector<int> heap{7, 6, 5, 8, 3, 5, 9, 1, 6};
    Solution::mergeSort(a, 0, a.size() - 1);
    std::cout << Solution::binSearch(a, -5, 0, a.size() - 1) << "\n";

    for (auto &elem: a) {
        std::cout << elem << " ";
    }

    return 0;
}