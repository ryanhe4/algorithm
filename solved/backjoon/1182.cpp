//
// Created by yangheechan on 2021-03-03.
//

#include <bits/stdc++.h>

using std::vector;
using std::string;
using std::cin;
using std::cout;

vector<vector<int>> arr_td;
vector<int> input;
int n;
int m;
string s;

vector<string> v;

struct st {
  int x, y, cnt;
  st(int x, int y, int cnt)
          :x(x), y(y), cnt(cnt) { }
};

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
vector<bool> visited;
vector<int> tracking;
vector<int> arr;
//= vector<vector<bool>>(n, vector<bool>(m, false));

int count;
void backtrack(int cnt, int sum)
{
    if (cnt==n) {
        return;
    }
    //더하지 않는 분기
    backtrack(cnt+1, sum);
    // 현재 값을 더하는 분기
    sum += input[cnt];
    if (sum==m) count++;
    backtrack(cnt+1, sum);
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    cin >> n >> m;

    for (int i = 0; i<n; i++) {
        int temp;
        cin >> temp;
        input.push_back(temp);
    }
    visited = vector<bool>(n, false);
    backtrack(0, 0);
    cout << count;
    return 0;
}