//
// Created by yangheechan on 2021-02-19.
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

vector<bool> finished;
vector<int> v;
int count;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
    int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

    int tc;
    std::cin >> tc;
    while (tc--) {
        std::cin >> n;

        auto visited = vector<vector<int>>(n, vector<int>(n, -1));
        std::queue<std::pair<int, int>> q;
        int a, b;
        cin >> a >> b;

        q.push({a, b});
        visited[a][b] = 0; //시작위치

        cin >> a >> b; //목표위치
        bool isFind = false;
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();

            for (int i = 0; i<8; ++i) {
                int nx = cur.first+dx[i];
                int ny = cur.second+dy[i];

                if (nx<0 || ny<0 || nx>=n || ny>=n) continue;
                if (visited[nx][ny]!=-1) continue;
                if (nx==a && ny==b) {
                    isFind = true;
                    std::cout << visited[cur.first][cur.second]+1 << "\n";
                    break;
                }

                q.push({nx, ny});
                visited[nx][ny] = visited[cur.first][cur.second]+1;
            }
            if (isFind) break;
        }
        if (!isFind) std::cout << 0 << "\n";
    }
    return 0;
}