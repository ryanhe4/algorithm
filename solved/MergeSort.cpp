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
    static void merge(vector<int>& array, int m, int middle, int n, vector<int>& sorted)
    {
        int i = m;
        int j = middle+1;
        int k = m;

        while (i<=middle && j<=n) {
            if (array[i]<=array[j]) {
                sorted[k] = array[i];
                i++;
            }
            else {
                sorted[k] = array[j];
                j++;
            }
            k++;
        }
        // 남은 데이터 삽입
        if (i>middle) {
            for (int t = j; t<=n; t++) {
                sorted[k] = array[t];
                k++;
            }
        }
        else {
            for (int t = i; t<=middle; t++) {
                sorted[k] = array[t];
                k++;
            }
        }

        for (int t = m; t<=n; t++) {
            array[t] = sorted[t];
        }
    }
public:
    static void mergeSort(vector<int>& array, int m, int n)
    {
        if (m<n) {
            int middle = (m+n)/2;
            mergeSort(array, m, middle);
            mergeSort(array, middle+1, n);
            merge(array, m, middle, n, s);
        }
    }
};

int arr[101];
int tmp[101];

void merge(int st, int ed)
{
    int mid = (st+ed)/2;
    int lidx = st;
    int ridx = mid;

    for (int i = st; i<ed; i++) {
        if (ridx==en) tmp[i] = arr[lidx++];
        else if (lidx==mid) tmp[i] = arr[ridx++];
        else if (arr[lidx]<=arr[ridx]) tmp[i] = arr[lidx++];
        else tmp[i] = arr[ridx++];
    }
    for (int i = st; i<en; i++)
        arr[i] = tmp[i];
}

void mergeSort(int st, int ed)
{
    if (st+1==ed) return;
    int mid = (st+ed)/2;
    mergeSort(st, mid);
    mergeSort(mid+1, ed);
    merge(st, ed);
}

int main()
{
    Solution::mergeSort(a, 0, a.size()-1);

    for (auto& elem: a) {
        std::cout << elem << " ";
    }

    return 0;
}