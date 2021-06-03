//
// Created by yangheechan on 2021-02-23.
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
int count;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

//auto visited = vector<vector<int>>(n, vector<int>(m, 0));

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    cin >> n >> m;
    // max값 구하기
    int mx = -1;
    for (int i = 0; i<n; i++) {
        auto arr_temp = vector<int>();
        for (int j = 0; j<m; j++) {
            int temp;
            std::cin >> temp;
            arr_temp.push_back(temp);
            mx = std::max(mx, temp);
        }
        arr_td.push_back(arr_temp);
    }

    int Year = 0;
    while (1) {
        //몇개의 부분으로 구성되는지 bfs를 돌면서 확인
        auto visited = vector<vector<int>>(n, vector<int>(m, 0));
        auto q = std::queue<std::pair<int, int>>();
        int blockCount = 0;
        for (int j = 0; j<n; j++) {
            for (int k = 0; k<m; k++) {
                if (visited[j][k]==0 && arr_td[j][k]!=0) {
                    q.push({j, k});
                    visited[j][k] = 1;
                    blockCount++;
                    if (blockCount>=2) {
                        cout << Year;
                        return 0;
                    }
                    while (!q.empty()) {
                        auto cur = q.front();
                        q.pop();

                        for (int dir = 0; dir<4; dir++) {
                            int nx = cur.first+dx[dir];
                            int ny = cur.second+dy[dir];

                            if (nx<0 || ny<0 || nx>=n || ny>=m) continue;
                            if (visited[nx][ny]!=0 || arr_td[nx][ny]==0)continue;

                            q.push({nx, ny});
                            visited[nx][ny] = 1;
                        }
                    }
                }
            }
        }
        if (blockCount==0) {
            cout << 0;
            break;
        }
        // 2중포문 돌면서 주변(동서남북) 0 하나당 -1 하기
        auto nmap = vector<vector<int>>(n, vector<int>(m, 0));
        for (int j = 0; j<n; j++) {
            for (int k = 0; k<m; k++) {
                if (arr_td[j][k]==0) continue;
                int nearZero = 0;
                for (int dir = 0; dir<4; dir++) {
                    int nx = j+dx[dir];
                    int ny = k+dy[dir];

                    if (nx<0 || ny<0 || nx>=n || ny>=m) continue;
                    if (arr_td[nx][ny]==0) nearZero++;
                }
                nmap[j][k] = arr_td[j][k]-nearZero<0 ? 0 : arr_td[j][k]-nearZero;
            }
        }

        arr_td = nmap;
        Year++;
    }
    return 0;
}