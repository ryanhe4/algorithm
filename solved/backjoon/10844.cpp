//
// Created by heechan on 21. 2. 2..
//
//
// Created by heechan on 21. 2. 1..
//
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// n은 동전 종류의 수, k는 동전의 목표
int N;
vector<vector<int>> cache;
vector<int> coins;

int stairNum(int n, int k) {
  if (k == -1 || k == 10)
    return 0;
  if (n == N) {
    return 1;
  }
  int &ret = cache[n][k];
  if (ret != -1)
    return ret;

  ret = (stairNum(n + 1, k + 1) + stairNum(n + 1, k - 1)) % 1000000000;
  return ret;
}

int main() {
  cin >> N;
  cache = vector<vector<int>>(N + 1, vector<int>(10 + 1, -1));
  long long sum = 0;
  for (int i = 1; i < 10; i++) {
    sum += stairNum(1, i);
  }
  std::cout << sum % 1000000000;

  return 0;
}