//
// Created by yangheechan on 2021-03-09.
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
vector<vector<bool>> visited;
vector<std::pair<int, int>> tracking;
//= vector<vector<bool>>(n, vector<bool>(m, false));
std::queue<std::pair<int, int>> que;
int ans;

bool checkrow(int x)
{
    bool check[10] = {false,};
    for (int i = 0; i<9; i++) {
        if (arr_td[x][i]!=0) {
            if (check[arr_td[x][i]]) { //already true
                return false;
            }
            check[arr_td[x][i]] = true;
        }
    }
    return true;
}
bool checkcol(int y)
{
    bool check[10] = {false,};
    for (int i = 0; i<9; i++) {
        if (arr_td[i][y]!=0) {
            if (check[arr_td[i][y]]) return false;
            check[arr_td[i][y]] = true;
        }
    }
    return true;
}
bool checkblock(int x, int y)
{
    int x_block = x/3;
    int y_block = y/3;

    bool check[10] = {false,};

    for (int i = x_block*3; i<x_block*3+3; i++) {
        for (int j = y_block*3; j<y_block*3+3; j++) {
            if (arr_td[i][j]!=0) {
                if (check[arr_td[i][j]]) return false;
                check[arr_td[i][j]] = true;
            }
        }
    }
    return true;
}

void backtrack(int row, int col)
{
    for (int i = 0; i<9; i++) {
        for (int j = 0; j<9; j++) {
            if (arr_td[i][j]==0) {
                for (int k = 1; k<=9; k++) {
                    arr_td[i][j] = k;
                    if (checkrow(i) && checkcol(j) && checkblock(i, j)) {
                        backtrack(i, j);
                    }
                    arr_td[i][j] = 0;
                }
                return;
            }
            if (i==8 && j==8) {
                for (int i = 0; i<9; i++) {
                    for (int j = 0; j<9; j++) {
                        if (arr_td[i][j]==0) {
                            return;
                        }
                    }
                }
                for (int i = 0; i<9; i++) {
                    for (int j = 0; j<9; j++) {
                        cout << arr_td[i][j] << " ";
                    }
                    cout << "\n";
                }
                exit(0);
            }
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    for (int i = 0; i<9; i++) {
        vector<int> v0;
        for (int j = 0; j<9; j++) {
            int vtemp;
            cin >> vtemp;
            v0.push_back(vtemp);
            if (vtemp==0) que.push({i, j});
        }
        arr_td.push_back(v0);
    }

    backtrack(0, 0);

}