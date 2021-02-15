//
// Created by heechan on 21. 1. 25..
// hanoi

#include <cmath>
#include <iostream>
#include <string>

using std::string;
using std::vector;

class Solution {
public:
  auto solve() -> void {
    // input
    int n;
    std::cin >> n;

    std::cout << int(pow(2, n) - 1) << "\n";
    hanoi(n, 1, 3, 2);
  }
  // cout은 속도 제한 문제로 printf를 사용해야 한다.
  auto move(int start, int to) -> void { printf("%d %d\n", start, to); }
  auto hanoi(int n, int start, int to, int via) -> void {
    if (n == 1)
      move(start, to);
    else {
      hanoi(n - 1, start, via, to);
      move(start, to);
      hanoi(n - 1, via, to, start);
    }
  }
};

int main() {
  Solution solution;

  // process
  solution.solve();

  return 0;
}