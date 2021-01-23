//
// Created by heechan on 21. 1. 23..
//
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
  auto solve() -> void {
    // input
    int size;
    vector<string> board(0);

    std::cin >> size;
    for (int i = 0; i < size; i++) {
      string line;
      std::cin >> line;
      board.push_back(line);
    }
    std::cout << maxCandy(board, false);
  }
  auto maxCandy(vector<string> &board, bool isSwap) -> int {
    if (isSwap) {
      // check maxCandy
      return checkCandy(board);
    }

    int ret = -1;

    for (int i = 0; i < board.size(); i++) {
      //시작점 선택(i)
      for (int j = 0; j < board.size() - 1; j++) {
        //가로
        std::swap(board[i][j], board[i][j + 1]);
        ret = std::max(ret, maxCandy(board, true));
        //복구
        std::swap(board[i][j], board[i][j + 1]);
      }

      //세로에서는 5번째줄에 가면 안될듯

      for (int j = 0; j < board.size() - 1; j++) {
        //세로
        std::swap(board[j][i], board[j + 1][i]);
        ret = std::max(ret, maxCandy(board, true));
        //복구
        std::swap(board[j][i], board[j + 1][i]);
      }
    }

    return ret;
  }
  auto checkCandy(vector<string> board) -> int {
    int max = 1;
    string lastWord = "";

    //가로 최대값
    for (int i = 0; i < board.size(); i++) {
      int sum = 0;
      for (int j = 0; j < board.size(); j++) {
        if (lastWord[0] == board[i][j]) {
          sum += 1;
          lastWord = board[i][j];
          max = std::max(max, sum);
        } else {
          sum = 1;
          lastWord = board[i][j];
        }
      }
      lastWord = "";
      sum = 0;
      for (int j = 0; j < board.size(); j++) {
        if (lastWord[0] == board[j][i]) {
          sum += 1;
          lastWord = board[j][i];
          max = std::max(max, sum);
        } else {
          sum = 1;
          lastWord = board[j][i];
        }
      }
    }
    //세로 최대값
    return max;
  }
};

int main() {
  Solution solution;

  // process
  solution.solve();

  return 0;
}