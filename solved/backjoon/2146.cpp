//
// Created by yangheechan on 2021-02-24.
//

#include <bits/stdc++.h>

using std::vector;
using std::string;
using std::cin;
using std::cout;

vector<vector<int>> arr_td;
vector<vector<int>> cache{};
int n;
int m;
int h;
string s;

vector<string> v;

struct st {
  int x, y, cnt;
  st(int x, int y, int cnt)
          :x(x), y(y), cnt(cnt) { }
};

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int am;
vector<vector<int>> visited;
//= vector<vector<bool>>(n, vector<bool>(m, false));
bool finish = false;
std::queue<st> findQ;

void bfs(int x, int y)
{
    auto q = std::queue<std::pair<int, int>>();

    q.push({x, y});
    findQ.push(st(x, y, am));
    visited[x][y] = 0;

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        for (int i = 0; i<4; i++) {
            int nx = cur.first+dx[i];
            int ny = cur.second+dy[i];

            if (nx<0 || ny<0 || nx>=n || ny>=n) continue;
            if (visited[nx][ny]!=-1 || arr_td[nx][ny]==0) continue;

            q.push({nx, ny});
            visited[nx][ny] = 0;
            findQ.push(st(nx, ny, am));
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i<n; i++) {
        auto tempV = vector<int>();
        for (int j = 0; j<n; j++) {
            int temp;
            cin >> temp;
            tempV.push_back(temp);
        }
        arr_td.push_back(tempV);
    }

    visited = vector<vector<int>>(n, vector<int>(n, -1));
    for (int i = 0; i<n; i++) {
        for (int j = 0; j<n; j++) {
            if (visited[i][j]==-1 && arr_td[i][j]!=0) {
                bfs(i, j);
                am++;
            }
        }
    }
    int ans = 1000;
    while (!findQ.empty()) {
        auto cur = findQ.front();
        findQ.pop();

        std::queue<st> q2 = findQ;
        while (!q2.empty()) {
            auto diff = q2.front();
            q2.pop();
            if (cur.cnt==diff.cnt) continue;
            int length = abs(diff.y-cur.y)+abs(diff.x-cur.x)-1;
            ans = std::min(ans, length);
        }
    }

    cout << ans;
    return 0;
}