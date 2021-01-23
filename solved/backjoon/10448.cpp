//
// Created by heechan on 21. 1. 23..
//
#include <iostream>

using std::string;
using std::vector;

class Solution {
public:
  auto solve() -> void {
    // input
    int C;
    std::cin >> C;
    for (int i = 0; i < C; i++) {
      int K;

      std::cin >> K;
      std::cout << Eureka(K, 0) << "\n";
    }
  }
  auto Eureka(int K, int n, int sum = 0) -> bool {
    // 기저사례
    if (K == sum && n == 3) {
      return true;
    } else if (K == sum && n != 3) {
      return false;
    } else if (K != sum && n == 3) {
      return false;
    }

    // for
    bool ret = false;
    for (int i = 1; i <= K; i++) {
      if (i > K)
        return false;
      ret = Eureka(K, n + 1, sum + calcNum(i));
      if (ret)
        return ret;
    }
    return ret;
  }
  auto calcNum(int n) -> int { return n * (n + 1) / 2; }
};

int main() {
  Solution solution;

  // process
  solution.solve();

  return 0;
}