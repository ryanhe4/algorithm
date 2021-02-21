//
// Created by yangheechan on 2021-02-16.
//
#include <bits/stdc++.h>

using std::vector;
using std::string;

vector<string> arr_td;
vector<vector<int>> cache{};
int n;
int m;
int h;
string s;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::cin >> n >> m >> h;
    std::swap(n, m);

    int visited[n][m][h];
    int arr[n][m][h];
    std::fill(&visited[0][0][0], &visited[n-1][m-1][h], -1);
    std::fill(&arr[0][0][0], &arr[n-1][m-1][h], 0);

    struct pos {
      int x;
      int y;
      int z;

      pos(std::initializer_list<int> l)
              :x(*l.begin()), y(*(l.begin()+1)), z(*(l.begin()+2))
      {
      }
    };

    std::queue<pos> q;

    for (int num = 0; num<h; num++) {
        for (int i = 0; i<n; i++) {
            for (int j = 0; j<m; j++) {
                int temp;
                std::cin >> temp;
                arr[i][j][num] = temp;
                if (temp==1) {
                    visited[i][j][num] = 0;
                    q.push({i, j, num});
                }
            }
        }
    }

    int dx[6] = {0, 0, 0, 0, 1, -1};
    int dy[6] = {0, 0, 1, -1, 0, 0};
    int dz[6] = {1, -1, 0, 0, 0, 0};

    int max = 0;
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        for (int i = 0; i<6; i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            int nz = cur.z + dz[i];
            //범위체크
            if (nx<0 || ny<0 || nz<0 ||
                    nx>=n || ny>=m || nz>=h)
                continue;
            //유효성 체크
            if(arr[nx][ny][nz] == -1 || visited[nx][ny][nz] != -1) continue;
            visited[nx][ny][nz] = visited[cur.x][cur.y][cur.z] +1;
            max = std::max(max, visited[nx][ny][nz]);
            q.push({nx, ny, nz});
        }
    }

    for (int num = 0; num<h; num++) {
        for (int i = 0; i<n; i++) {
            for (int j = 0; j<m; j++) {
                if(visited[i][j][num] == -1 && arr[i][j][num] == 0) {
                    std::cout << -1;
                    return 0;
                }
            }
        }
    }

    std::cout << max;
    return 0;
}