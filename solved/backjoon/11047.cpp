//
// Created by heechan on 21. 2. 3..
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
int N, K;
vector<vector<int>> cache;
vector<int> cacheOne;
vector<int> arr;
using ll = long long;

int coin(int money) {
  int ret = 0;

  for(int i = arr.size()-1 ; i >= 0; i--) {
    while(arr[i] <= money) {
      ret++;
      money -= arr[i];
      if(money == 0) break;
    }
    if(money == 0) break;
  }

  return ret;
}

int main() {
  //  int testcase;
  //  cin >> testcase;
  int n, k;
  std::cin >> n >> k;
  for (int i = 0; i < n; i++) {
    int temp;
    cin >> temp;
    arr.push_back(temp);
  }
  std::cout << coin(k);
  //  cache = vector<vector<int>>(N + 1, vector<int>(K + 1, -1));
  //  cacheOne = vector<int>(N + 1, -1);
  return 0;
}