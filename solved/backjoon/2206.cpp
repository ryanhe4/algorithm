//
// Created by yangheechan on 2021-02-20.
//

#include <bits/stdc++.h>

using std::vector;
using std::string;
using std::cin;
using std::cout;

vector<string> arr_td;
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

    cin >> n >> m;
    for (int i = 0; i<n; ++i) {
        cin >> s;
        arr_td.push_back(s);
    }
    if(n == m && n == 1) {
        std::cout << 1;
        return 0;
    }

    vector<vector<int>> visit[2] = {
            vector<vector<int>>(n, vector<int>(m, -1)),
            vector<vector<int>>(n, vector<int>(m, -1)),
    };
    std::queue<std::pair<int, std::pair<int, int>>> q;
    q.push({0, {0, 0}});
    visit[0][0][0] = 1;

    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        for (int i = 0; i<4; i++) {
            int nx = cur.second.first+dx[i];
            int ny = cur.second.second+dy[i];

            int isdrill = cur.first;
            if (nx<0 || ny<0 || nx>=n || ny>=m) continue;
            if (nx==n-1 && ny==m-1) {
                std::cout << visit[isdrill][cur.second.first][cur.second.second]+1;
                return 0;
            }
            if (isdrill==1 && arr_td[nx][ny]!='0' || visit[isdrill][nx][ny]!=-1) continue;
            else if (isdrill==0 && arr_td[nx][ny]=='1') {
                q.push({1, {nx, ny}});
                visit[1][nx][ny] = visit[0][cur.second.first][cur.second.second]+1;
                continue;
            }
            q.push({isdrill, {nx, ny}});
            visit[isdrill][nx][ny] = visit[isdrill][cur.second.first][cur.second.second]+1;
        }
    }

    std::cout << -1;
    return 0;
}