//
// Created by heechan on 21. 2. 3..
//

#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// n은 동전 종류의 수, k는 동전의 목표
int N, K;
vector<vector<int>> cache;
vector<int> cacheOne;
vector<int> arr;
using ll = long long;

int fix(int length) {
  int countTape = 0;
  vector<bool> isMarking(arr.size(), false);
  for (int i = 0; i < arr.size(); i++) {
    if (!isMarking[i]) {
      int mark = arr[i] + length;
      countTape++;
      isMarking[i] = true;
      for (int j = i + 1; j < arr.size(); j++) {
        if (arr[j] < mark) {
          isMarking[j] = true;
        }
      }
    }
  }
  return countTape;
}

int main() {
  int n, l;
  std::cin >> n >> l;
  for (int i = 0; i < n; i++) {
    int temp;
    cin >> temp;
    arr.push_back(temp);
  }
  std::sort(arr.begin(), arr.end());
  std::cout << fix(l);
  return 0;
}