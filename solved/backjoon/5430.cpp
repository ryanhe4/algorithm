//
// Created by heechan on 21. 2. 13..
//
#include <deque>
#include <iostream>
#include <queue>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using std::deque;
using std::stack;
using std::vector;

vector<int> arr;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0;
  int m;

  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    std::string p;
    int numCount;
    std::string arrayNum;
    std::deque<int> deq;
    bool errorFlag = false;

    std::cin >> p >> numCount >> arrayNum;
    arrayNum = arrayNum.substr(1, arrayNum.size() - 2);
    std::istringstream ss(arrayNum);
    std::string stringBuffer;
    bool frontFlag = true;

    while (getline(ss, stringBuffer, ',')) {
      deq.push_back(std::stoi(stringBuffer));
    }
    for (const auto &item : p) {
      if (item == 'R') {
        frontFlag = !frontFlag;
      } else {
        if (deq.empty())
          errorFlag = true;
        else {
          if (frontFlag)
            deq.pop_front();
          else
            deq.pop_back();
        }
      }
    }
    if (errorFlag)
      std::cout << "error";
    else {
      std::cout << "[";
      //배열 형태로 출력
      if (frontFlag) {
        for (auto it = deq.begin(); it != deq.end(); it++) {
          std::cout << *it;
          if(--deq.end() != it) std::cout << ",";
        }
      } else {
        for (auto it = deq.rbegin(); it != deq.rend(); it++) {
          std::cout << *it;
          if(--deq.rend() != it) std::cout << ",";
        }
      }
      std::cout << "]";
    }
    std::cout << "\n";
  }

  return 0;
}