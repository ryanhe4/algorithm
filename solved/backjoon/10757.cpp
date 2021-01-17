//
// Created by heechan on 21. 1. 17..
//

#include <algorithm>
#include <iostream>
#include <ranges>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
  static auto solve(const vector<int> &A, const vector<int> &B) -> void {
    if (B.size() > A.size())
      return solve(B, A);

    if(A.size() == 1 && A[0] == 0) {
      for (const auto &elem : B | std::ranges::views::reverse) {
        std::cout << elem;
      }
      return;
    }

    if(B.size() == 1 && B[0] == 0) {
      for (const auto &elem : A | std::ranges::views::reverse) {
        std::cout << elem;
      }
      return;
    }

    vector<int> C(A.size() + 1);
    int index;
    for (index = 0; index < B.size(); index++) {
      C[index] = A[index] + B[index];
    }
    if (A.size() > B.size()) {
      for (; index < A.size(); index++) {
        C[index] = A[index];
      }
    }
    //정규화
    normalize(C);
    if (C.back() == 0) {
      C.pop_back();
    }
    // print
    for (const auto &elem : C | std::ranges::views::reverse) {
      std::cout << elem;
    }
  }

  static auto normalize(vector<int> &array) -> void {
    bool carry = false;
    for (auto &elem : array) {
      if (carry) {
        elem++;
        carry = false;
      }
      if (elem >= 10) {
        carry = true;
        elem -= 10;
      }
    }
  }
};

int main() {
  string input;
  vector<int> A, B;

  std::cin >> input;

  for (const auto &elem : input | std::ranges::views::reverse) {
    A.push_back(elem - '0');
  }

  std::cin >> input;
  for (const auto &elem : input | std::ranges::views::reverse) {
    B.push_back(elem - '0');
  }
  // process
  Solution::solve(A, B);

  return 0;
}