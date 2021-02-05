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
void dfs(int y, int x)
{
    visited[y][x] = true;

    for (int i = 0; i<4; i++) {
        int nextX = x+dx[i];
        int nextY = y+dy[i];

        if (nextY>=0 && nextY<n && nextX>=0&& nextX<m) {
            if (!visited[nextY][nextX] && arr[nextY][nextX]==1)
                dfs(nextY, nextX);
        }
    }
}

void problem()
{
    int components = 0;

    for (int i = 0; i<n; i++) {
        for (int j = 0; j<m; j++) {
            if (!visited[i][j] && arr[i][j]==1) {
                dfs(i, j);
                components++;
            }
        }
    }
    std::cout << components << "\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int testcase = 0;

    std::cin >> testcase;

    for (int t = 0; t<testcase; t++) {
        std::cin >> m >> n >> count;

        arr.clear();
        arr = vector<vector<int>>(50, vector<int>(50, 0));
        visited.clear();
        visited = vector<vector<bool>>(50, vector<bool>(50, false));

        //count 개의 간선을 입력
        for (int i = 0; i<count; i++) {
            int a, b;
            std::cin >> a >> b;
            arr[b][a] = 1;
        }

        problem();
    }

    return 0;
}