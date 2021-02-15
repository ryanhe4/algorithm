//
// Created by heechan on 21. 2. 13..
//
#include <deque>
#include <iostream>
#include <string>
#include <vector>

using std::deque;
using std::vector;

vector<int> arr;
deque<int> deq;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0;
  int m;

  std::cin >> n >> m;

  // n개의 수를 deque에 입력
  for (int i = 0; i < n; ++i) {
    deq.push_back(i + 1);
  }
  // 3번 반복
  int sum = 0;
  for (int i = 0; i < m; ++i) {
    int temp;
    std::cin >> temp;

    // back에서의 거리, front에서의 거리 가까운방향으로 이
    int index;
    for (int j = 0; j < deq.size(); ++j) {
      if (deq[j] == temp) {
        index = j;
        break;
      }
    }
    if (index < deq.size() - index) {
      while (deq.front() != temp) {
        deq.push_back(deq.front());
        deq.pop_front();
        sum++;
      }
    } else {
      while (deq.front() != temp) {
        deq.push_front(deq.back());
        deq.pop_back();
        sum++;
      }
    }
    deq.pop_front();
  }
  std::cout << sum;
  return 0;
}