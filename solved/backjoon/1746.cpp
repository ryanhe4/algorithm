//
// Created by yangheechan on 2021-02-05.
//

#include <iostream>
#include <vector>

using std::vector;
using std::string;

vector<vector<int>> arr;
vector<vector<int>> cache{};
vector<vector<bool>> visited;
int n;
int m;
int count;

//(0, 0)을 기준으로 왼쪽, 오른쪽 아래
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

//cur : 현재 정점의 번호
int dfs(int y, int x)
{
    visited[y][x] = true;

    int ret = 1;

    for (int i = 0; i<4; i++) {
        int nextX = x+dx[i];
        int nextY = y+dy[i];

        if (nextY>=1 && nextY<=n && nextX>=1 && nextX<=m) {
            if (!visited[nextY][nextX] && arr[nextY][nextX]==1) {
                ret += dfs(nextY, nextX);
            }
        }
    }
    return ret;
}

void problem()
{
    //여기서 dfs 결과의 max를 구하고 출력.
    int max = -1;
    for (int i = 1; i<=n; i++) {
        for (int j = 1; j<=m; j++) {
            if (!visited[i][j] && arr[i][j]==1) {
                max = std::max(max, dfs(i, j));
            }
        }
    }
    std::cout << max;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    //int testcase = 0;

    std::cin >> m >> n >> count;

    arr.clear();
    arr = vector<vector<int>>(n+1, vector<int>(m+1, 0));
    visited.clear();
    visited = vector<vector<bool>>(n+1, vector<bool>(m+1, false));

    //count 개의 간선을 입력
    for (int i = 0; i<count; i++) {
        int a, b;
        std::cin >> a >> b;
        arr[b][a] = 1;
    }

    problem();

    return 0;
}