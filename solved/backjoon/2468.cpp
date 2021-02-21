//
// Created by yangheechan on 2021-02-21.
// 빗물, 안전영역
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
int count;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    cin >> n;
    int mx = -1;
    for (int i = 0; i<n; ++i) {
        vector<int> t;
        for (int j = 0; j<n; ++j) {
            cin >> m;
            mx = std::max(mx, m);
            t.push_back(m);
        }
        arr_td.push_back(t);
    }
    if(n == 1) {
        cout << 1;
        return 0;
    }
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    int ret = -1;
    for (int height = 0; height<mx; height++) {
        vector<vector<int>> visited(n, vector<int>(n, -1));

        int checkVal = 0;
        for (int i = 0; i<n; i++) {
            for (int j = 0; j<n; j++) {
                std::queue<std::pair<int, int>> q;
                if (visited[i][j]!=-1 || arr_td[i][j]<=height) continue;
                q.push({i, j});
                visited[i][j] = 0;
                while (!q.empty()) {
                    auto cur = q.front();
                    q.pop();

                    for (int dir = 0; dir<4; dir++) {
                        int nx = cur.first+dx[dir];
                        int ny = cur.second+dy[dir];

                        if (nx<0 || ny<0 || nx>=n || ny>=n) continue;
                        if (visited[nx][ny]!=-1 || arr_td[nx][ny]<=height) continue;

                        q.push({nx, ny});
                        visited[nx][ny] = 0;
                    }
                }
                checkVal++;
            }
        }
        ret = std::max(checkVal, ret);
    }

    std::cout << ret;
    return 0;
}