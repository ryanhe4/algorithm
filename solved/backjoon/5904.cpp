//
// Created by yangheechan on 2021-02-25.
//

#include <bits/stdc++.h>

using std::vector;
using std::string;
using std::cin;
using std::cout;

vector<vector<int>> arr_td;
vector<int> input;
int n;
int m;
string s;

vector<string> v;

struct st {
  int x, y, cnt;
  st(int x, int y, int cnt)
          :x(x), y(y), cnt(cnt) { }
};

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int am;
vector<vector<int>> visited;
//= vector<vector<bool>>(n, vector<bool>(m, false));
bool finish = false;
int blue;
int white;
void click(int x, int y)
{
    for (int i = 0; i<m; i++) {
        if (arr_td[i][0]==x+1 && arr_td[i][1]==y+1) {
            if (visited[arr_td[i][2]-1][arr_td[i][3]-1]==-1) {
                visited[arr_td[i][2]-1][arr_td[i][3]-1] = 0;
                am++;
                std::cout << arr_td[i][0] << arr_td[i][1] << arr_td[i][2] << arr_td[i][3] << " " << x << y << "\n";
            }
        }
    }
}

void dfs(int x, int y)
{
    std::stack<std::pair<int, int>> stack;
    stack.push({x, y});
    visited[x][y] = 1;

    while (!stack.empty()) {
        auto cur = stack.top();
        stack.pop();

        click(cur.first, cur.second);

        for (int i = 0; i<4; i++) {
            int nx = cur.first+dx[i];
            int ny = cur.second+dy[i];

            if (nx<0 || ny<0 || nx>=n || ny>=n) continue;

            //불을 키지 않았으면 이동 불가
            if (visited[nx][ny]!=0) continue;

            stack.push({nx, ny});
            visited[nx][ny] = 1;
            click(nx, ny);
        }
    }
}
int idx;

void recursive(int num)
{
    if (num==1) {
        if (idx+1==n) {
            cout << "m";
            exit(0);
        }
        else if (idx+2==n || idx+3==n) {
            cout << "o";
            exit(0);
        }
        idx += 3;
        return;
    }
    recursive(num-1);
    if (idx+1==n) {
        cout << "m";
        exit(0);
    }
    idx++;
    for (int i = 0; i<=num; i++) {
        if (idx+1==n) {
            cout << "o";
            exit(0);
        }
        idx++;
    }

    recursive(num-1);
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    cin >> n;

/*    for(int i = 0 ; i < n; i++ ){
        auto tempAry = vector<int>();
        for(int j = 0 ; j < n ; j++) {
            int temp;
            cin >> temp;
            tempAry.push_back(temp);
        }
        arr_td.push_back(tempAry);
    }*/
    recursive(30);
    return 0;
}