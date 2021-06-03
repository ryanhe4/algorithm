//
// Created by yangheechan on 2021-03-07.
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

int ans;

bool adjacent()
{
//    std::queue<std::pair<int, int>> q;
    bool flag[7] = {false,};
    //std::pair<int, int> tmp{tracking[0]};
//    flag[0] = true;
    int cnt = 1;
    for (int i = 0; i<7; i++) {
        auto cur = tracking[i];

        for (int j = 0; j<7; j++) {
            if (flag[j] || i==j) continue;
            for (int dir = 0; dir<4; dir++) {
                int nx = cur.first+dx[dir];
                int ny = cur.second+dy[dir];

                if (nx==tracking[j].first && ny==tracking[j].second) {
                    flag[i] = true;
                    flag[j] = true;
                    cnt++;
                }
            }
        }
    }
    if (cnt==7) return true;
    return false;

}
void backtrack(int cnt, int S, int start)
{
    if (cnt==7) {
        if (S<4) return;
        // 모두 이어진 경우인지 체크
        if (!adjacent()) return;
        ans++;
        return;
    }

    for (int i = 0; i<5; i++) {
        for (int j = 0; j<5; j++) {
            int idx = i*5+j;
            if (visited[i][j] || idx<start) continue;
            tracking[cnt] = {i, j};

            visited[i][j] = true;
            bool isSom = (v[i][j]=='S');
            backtrack(cnt+1, S+isSom, idx+1);
            visited[i][j] = false;
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    for (int i = 0; i<5; i++) {
        cin >> s;
        v.push_back(s);
    }

    tracking = vector<std::pair<int, int>>(7, {0, 0});
    visited = vector<vector<bool>>(5, vector<bool>(5, false));
    backtrack(0, 0, 0);
    cout << ans;
}