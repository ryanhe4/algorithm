//
// Created by heechan on 21. 1. 18..
// https://programmers.co.kr/learn/courses/30/lessons/12940
// GCD && LCM

#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
  auto solve(int n, int m) -> void {
    vector<int> answer;
    answer.push_back(gcd(n, m));
    answer.push_back(lcm(n, m));

    std::cout << answer[0] << " " << answer[1];
  }
  auto gcd(int n, int m) -> int {
    while (m != 0) {
      int r = n % m;
      n = m;
      m = r;
    }
    return n;
  }
  auto lcm(int n, int m) -> int { return n * m / gcd(n, m); }

  auto input() -> void { std::cin >> N >> M; }

private:
  int N, M;
};

int main() {
  Solution solution;

  // process
  solution.solve(2 , 5);

  return 0;
}