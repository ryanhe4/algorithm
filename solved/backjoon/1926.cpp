//
// Created by yangheechan on 2021-02-15.
//

#include <bits/stdc++.h>

using std::vector;
using std::string;

vector<int> arr;
vector<std::pair<string, string>> arr_pair;
vector<vector<int>> arr_td;
vector<vector<int>> cache{};
vector<vector<bool>> visited;
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
    for (int i = 0; i<n; i++) {
        vector<int> temp;
        for (int j = 0; j<m; j++) {
            int a;
            std::cin >> a;
            temp.push_back(a);
        }
        arr_td.push_back(temp);
    }
    visited = vector<vector<bool>>(n, vector<bool>(m, false));

    int dx[4] = {-1, 0, 0, 1};
    int dy[4] = {0, -1, 1, 0};

    int size = 0;
    int maxSize = 0;
    for (int i = 0; i<n; ++i) {
        for (int j = 0; j<m; ++j) {
            if (!visited[i][j] && arr_td[i][j]==1) {
                std::queue<std::pair<int, int>> bfs;
                //bfs 작업
                bfs.push({i, j});
                visited[i][j] = true;
                int area = 0;
                while (!bfs.empty()) {
                    area++;
                    auto cur = bfs.front();
                    bfs.pop();
                    for(int dir = 0 ; dir < 4 ; dir ++) {
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];
                        if( nx < 0 || nx >= n || ny < 0 || ny >= m ) continue;
                        if(visited[nx][ny] || arr_td[nx][ny] != 1) continue;
                        visited[nx][ny] = true;
                        bfs.push({nx, ny});
                    }
                }
                maxSize = std::max(maxSize, area);
                size++;
            }
        }
    }
    std::cout << size << "\n" << maxSize;

    return 0;
}