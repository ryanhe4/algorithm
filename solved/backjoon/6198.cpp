//
// Created by heechan on 21. 2. 12..
//
#include <iostream>
#include <stack>
#include <vector>
using std::stack;
using std::vector;

vector<int> arr;
stack<int> stack1;

int main() {
  int n = 0;
  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    int val;
    std::cin >> val;
    arr.push_back(val);
  }
  long long sum = 0;
  long long value;

  for (int i = 0; i < n; i++) {
    value = arr[i];
    while (!stack1.empty() && stack1.top() <= value ) {
      stack1.pop();
    }
    sum += (long long )stack1.size();
    stack1.push(arr[i]);
  }

  std::cout << sum;

  return 0;
}