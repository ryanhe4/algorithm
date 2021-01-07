//
// Created by yangheechan on 2020-12-19.
// O(NlogN)
#include <iostream>
#include <vector>

using std::vector;

vector<int> a{7, 6, 5, 8, 3, 5, 9, 1};
vector<int> s(a.size());

class Solution {
private:
    static void merge(vector<int> &array, int m, int middle,int n, vector<int> &sorted)
    {
        int i = m;
        int j = middle+1;
        int k = m;

        while(i <= middle && j <= n) {
            if(array[i] <= array[j]) {
                sorted[k] = array[i];
                i++;
            } else {
                sorted[k] = array[j];
                j++;
            }
            k++;
        }
        // 남은 데이터 삽입
        if(i > middle) {
            for (int t = j ; t<= n; t++) {
                sorted[k] = array[t];
                k++;
            }
        } else {
            for(int t = i; t<= middle; t++) {
                sorted[k] = array[t];
                k++;
            }
        }

        for (int t = m; t<= n; t++) {
            array[t] = sorted[t];
        }
    }
public:
    static void mergeSort(vector<int>& array, int m, int n) {
        if (m<n) {
            int middle = (m+n)/2;
            mergeSort(array, m, middle);
            mergeSort(array, middle+1 ,n);
            merge(array,m,middle,n,s);
        }
    }
};

int main()
{
    Solution::mergeSort(a,0, a.size()-1);

    for (auto& elem: a) {
        std::cout << elem << " ";
    }

    return 0;
}