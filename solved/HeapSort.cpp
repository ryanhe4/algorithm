//
// Created by yangheechan on 2020-12-22.
//
#include <iostream>
#include <vector>

using std::vector;

class Solution {

public:
    static void heapSort(vector<int>& heap)
    {
        int number = heap.size();
        for (int i = 1; i<number; i++) {
            int c = i;
            do {
                int root = (c-1)/2;
                if (heap[root]<heap[c]) {
                    std::swap(heap[root], heap[c]);
                }
                c = root;
            }
            while (c!=0);
        }

        for (int i = number-1; i>=0; i--) {
            std::swap(heap[0], heap[i]);
            int root = 0;
            int c;
            do {
                c = 2*root+1;
                // 자식중에 더 큰 값 찾기
                if (heap[c]<heap[c+1] && c<i-1) {
                    c++;
                }
                if (heap[root]<heap[c] && c<i) {
                    std::swap(heap[root], heap[c]);
                }
                root = c;
            }
            while (c<i);
        }
    }
};

int main()
{
    vector<int> heap{7, 6, 5, 8, 3, 5, 9, 1, 6};
    Solution::heapSort(heap);

    for (auto& elem: heap) {
        std::cout << elem << " ";
    }

    return 0;
}