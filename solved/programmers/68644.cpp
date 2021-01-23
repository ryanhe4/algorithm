//
// Created by heechan on 21. 1. 18..
//
// https://programmers.co.kr/learn/courses/30/lessons/68644
// 두 개 뽑아서 더하기

#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
  auto solve(vector<int> numbers) -> void {
    vector<int> answer;
    for (int i = 0; i < numbers.size(); i++) {
      for (int j = i+1; j < numbers.size(); j++) {
        answer.push_back(numbers[j] + numbers[i]);
      }
    }
    std::sort(answer.begin(), answer.end());

    int beforeItem = -1;
    answer.erase(std::remove_if(answer.begin(), answer.end(), [&](const int &i) {
      bool ret = beforeItem == i;
      beforeItem = i;
      return ret;
    }), answer.end());

    for(auto& elem : answer) {
      std::cout << elem << " ";
    }
  }
  auto input() -> void { std::cin >> N >> M; }

private:
  int N, M;
};

int main() {
  Solution solution;

  // process
  solution.solve(vector<int>{2,1,3,4,1});

  return 0;
}