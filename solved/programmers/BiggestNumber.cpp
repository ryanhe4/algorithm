//
// Created by yangheechan on 2021-03-23.
//

#include <bits/stdc++.h>

using std::vector;
using std::string;
using std::cin;
using std::cout;

vector<vector<int>> board;
vector<int> moves;
int n;
int m;
string str;

vector<int> v;

struct st {
  int x, y, cnt;
  st(int x, int y, int cnt)
          :x(x), y(y), cnt(cnt) { }
};

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
vector<bool> visited;
vector<int> tracking;
//= vector<vector<bool>>(n, vector<bool>(m, false));
std::queue<std::pair<int, int>> que;
vector<std::pair<int, int>> A;

string makebin(int size, int val)
{
    string binary("");
    int mask = 1;
    for (int i = 0; i<size; i++) {
        if ((mask & val)>=1)
            binary = "1"+binary;
        else
            binary = "0"+binary;
        mask <<= 1;
    }
    return binary;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    vector<int> nums{0,0,0,0};
    //vector<string> num_s;
//    for (int i = 0; i<nums.size(); i++) {
//        num_s.push_back(std::to_string(nums[i]));
//    }

    std::sort(nums.begin(), nums.end(), [](const int& a, const int& b) {
      int a_leng = 0;
      int a_tmp = a;
      while (a_tmp>0) {
          a_tmp /= 10;
          a_leng++;
      }

      int b_leng = 0;
      int b_tmp = b;
      while (b_tmp>0) {
          b_tmp /= 10;
          b_leng++;
      }

      if (a_leng==b_leng) {
          return a>b;
      }
      else {
          //자리수가 다른경우
          string tmp1 = std::to_string(a);
          string tmp2 = std::to_string(b);

          string tmp3 = tmp1 + tmp2;
          string tmp4 = tmp2 + tmp1;

          if(std::stoi(tmp3) < std::stoi(tmp4)) {
              return false;
          } else if(std::stoi(tmp3) > std::stoi(tmp4)){
              return true;
          } else {
              return false;
          }
      }
    });
    for (auto& c: nums) {
        cout << c;
    }
}

