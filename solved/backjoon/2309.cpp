//
// Created by heechan on 21. 1. 22..
// 일곱난장이, 완전탐색, 조합 생성

#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using std::vector;

class Solution {
public:
  auto solve() -> void {
    // input
    vector<int> height(9, 0);
    for (auto &elem : height) {
      std::cin >> elem;
    }
    vector<int> sum;
    seventToys(height, sum, 0);
  }
  auto seventToys(vector<int> &arr, vector<int> &inserted, int start) -> bool {
    if (inserted.size() == 7) {
      int sum = std::accumulate(inserted.begin(), inserted.end(), 0);
      if (sum == 100) {
        std::sort(inserted.begin(), inserted.end());
        for (auto &elem : inserted) {
          std::cout << elem << "\n";
        }
        return true;
      }
      return false;
    }
    bool ret = false;
    for (int i = start; i < 9; i++) {
      inserted.push_back(arr[i]);
      ret = seventToys(arr, inserted, i + 1);
      if (ret)
        return ret;
      inserted.pop_back();
    }
    return ret;
  }

  auto input() -> void { std::cin >> N >> M; }

private:
  int N, M;
};

int main() {
  Solution solution;

  // process
  solution.solve();

  return 0;
}