//
// Created by yangheechan on 2021-02-15.
//
// 0으로 초기화해서 사용하는 visited 배열이 핵심
// 실제 방문을 위한 배열은 따로 저장하지 않아도 됨

#include <bits/stdc++.h>

using std::vector;
using std::string;

vector<int> arr;
vector<vector<int>> arr_td;
vector<vector<int>> cache{};
vector<vector<int>> visited;
int n;
int m;
string s;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    //BFS
    std::cin >> n >> m;


    std::swap(n, m);
    std::queue<std::pair<int, int>> bfs;
    visited = vector<vector<int>>(n, vector<int>(m, 0));

    for (int i = 0; i<n; i++) {
        vector<int> temp;
        for (int j = 0; j<m ;j++) {
            int a;
            std::cin >> a;
            temp.push_back(a);
            if (a==1) {
                bfs.push({i, j});
            }
            if(a == 0 ) visited[i][j] = -1;
        }
        arr_td.push_back(temp);
    }

    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    int days = 0;
    while (!bfs.empty()) {
        auto cur = bfs.front();
        bfs.pop();

        for (int i = 0; i<4; ++i) {
            int nx = cur.first+dx[i];
            int ny = cur.second+dy[i];

            if (nx<0 || ny<0 || nx>=n || ny>=m) continue;
            if (visited[nx][ny] >= 0) continue;
            visited[nx][ny] = visited[cur.first][cur.second] +1;
            days = std::max(days, visited[nx][ny]);
            bfs.push({nx, ny});
        }
    }

    for (int i = 0; i<n; ++i) {
        for (int j = 0; j<m; ++j) {
            if(visited[i][j] == -1) {
                std::cout << -1;
                return 0;
            }
        }
    }

    std::cout << days;
    return 0;
}