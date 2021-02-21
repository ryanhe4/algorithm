//
// Created by yangheechan on 2021-02-18.
// BFS

#include <bits/stdc++.h>

using std::vector;
using std::string;

vector<string> arr_td;
vector<vector<int>> cache{};
int n;
int m;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int count;

    std::cin >> m >> n >> count;

    vector<vector<int>> v(m, vector<int>(n, 0));
    for (int i = 0; i<count; ++i) {
        int a[4];
        for (int & i : a) {
            std::cin >> i;
        }
        for (int k = a[1]; k<a[3]; k++) {
            for (int j = a[0]; j<a[2]; j++) {
                v[k][j] = -1;
            }
        }
    }

    std::queue<std::pair<int, int>> q;
    vector<int> ret;
    int retcount= 0;
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {1, -1, 0, 0};

    for (int i = 0; i<m; ++i) {
        for (int j = 0; j<n; ++j) {
            if (v[i][j]==0) {
                q.push({i, j});
                v[i][j] = 1; // 방문처리
                retcount++;

                int amount = 1;
                while (!q.empty()) {
                    auto cur = q.front();
                    q.pop();

                    for (int dir = 0; dir<4; dir++) {
                        int nx = cur.first+dx[dir];
                        int ny = cur.second+dy[dir];

                        if (nx<0 || ny<0 || nx>=m || ny>=n) continue;
                        if (v[nx][ny]==-1 || v[nx][ny]==1) continue; // 벽이다 또는 방문했다.
                        q.push({nx, ny});
                        v[nx][ny] = 1;
                        amount++;
                    }
                }
                ret.push_back(amount);
            }
        }
    }
    std::sort(ret.begin(), ret.end());
    std::cout << retcount <<"\n";
    for(auto& item: ret) {
        std::cout << item<<" ";
    }

    return 0;
}