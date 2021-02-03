//
// Created by heechan on 21. 2. 3..
//

#include <cmath>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

// n은 동전 종류의 수, k는 동전의 목표
int N, K;
vector<vector<int>> cache;
vector<int> cacheOne;
vector<pair<int, int>> arr;
using ll = long long;

int meetingRoom() {
  sort(arr.begin(), arr.end());
  priority_queue<int, vector<int>, greater<>> room;

  room.push(arr[0].second);
  for (int i = 1; i < arr.size(); i++) {
    int meetingBegin = arr[i].first, meetingEnd = arr[i].second;

    std::cout << room.top();
    if (room.top() > meetingBegin) {
      room.push(meetingEnd);
    } else {
      room.pop();
      room.push(meetingEnd);
    }
  }

  return room.size();
}

int main() {
  //  int testcase;
  //  cin >> testcase;
  int n;
  std::cin >> n;
  for (int i = 0; i < n; i++) {
    int start, end;
    cin >> start >> end;
    arr.emplace_back(start, end);
  }
  std::cout << meetingRoom();
  //  cache = vector<vector<int>>(N + 1, vector<int>(K + 1, -1));
  //  cacheOne = vector<int>(N + 1, -1);
  return 0;
}