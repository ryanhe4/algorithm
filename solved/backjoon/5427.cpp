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

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

vector<vector<int>> f_visited;
vector<vector<int>> h_visited;
//= vector<vector<bool>>(n, vector<bool>(m, false));
bool finish = false;

void bfs(vector<std::pair<int, int>> coord)
{
    auto q = std::queue<std::pair<int, int>>();

    for (auto& elem: coord) {
        q.push(elem);
        f_visited[elem.first][elem.second] = 0;
    }

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        for (int i = 0; i<4; i++) {
            int nx = cur.first+dx[i];
            int ny = cur.second+dy[i];

            if (nx<0 || ny<0 || nx>=n || ny>=m) continue;
            if (f_visited[nx][ny]!=-1 || v[nx][ny]=='#') continue;

            q.push({nx, ny});
            f_visited[nx][ny] = f_visited[cur.first][cur.second]+1;
        }
    }
}

void bfs2(int x, int y)
{
    auto q = std::queue<std::pair<int, int>>();
    q.push({x, y});
    h_visited[x][y] = 0;

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        for (int i = 0; i<4; i++) {
            int nx = cur.first+dx[i];
            int ny = cur.second+dy[i];

            if (nx<0 || ny<0 || nx>=n || ny>=m) {
                cout << h_visited[cur.first][cur.second]+1 << "\n";
                finish = true;
                return;
            }
            //방문 했거나, 벽이거나,
            if (h_visited[nx][ny]!=-1 || v[nx][ny]=='#' || f_visited[nx][ny]!=-1 &&
                    h_visited[cur.first][cur.second]+1>=f_visited[nx][ny])
                continue;

            q.push({nx, ny});
            h_visited[nx][ny] = h_visited[cur.first][cur.second]+1;
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        finish = false;
        auto coordination = vector<std::pair<int, int>>();
        std::pair<int, int> h_coord;
        v.clear();
        cin >> n >> m;
        std::swap(n, m);
        for (int i = 0; i<n; i++) {
            cin >> s;
            v.push_back(s);
            for (int j = 0; j<s.size(); j++) {
                if (s[j]=='*') {
                    coordination.push_back({i, j});
                }
                if (s[j]=='@') h_coord = {i, j};
            }
        }
        //불에 대해 bfs
        //visited 초기화
        f_visited = vector<vector<int>>(n, vector<int>(m, -1));
        bfs(coordination);

//        for (auto& vv: f_visited) {
//            for (auto& item: vv) {
//                std::cout << item << " ";
//            }
//            std::cout << "\n";
//        }
        //사람에 대해 불의 bfs, 값 보다 작을 때 bfs 진행 가능
        h_visited = vector<vector<int>>(n, vector<int>(m, -1));
        bfs2(h_coord.first, h_coord.second);

        if (!finish) std::cout << "IMPOSSIBLE" << "\n";
    }

    return 0;
}