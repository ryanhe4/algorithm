//
// Created by yangheechan on 2021-03-26.
//
#include <bits/stdc++.h>
using std::vector;
using std::string;
using std::cin;
using std::cout;

vector<vector<int>> board;
vector<int> moves;
int n;
int m;
string str;

vector<int> v;

struct st {
  int x, y, cnt;
  st(int x, int y, int cnt)
          :x(x), y(y), cnt(cnt) { }
};

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
vector<bool> visited;
vector<int> tracking;
//= vector<vector<bool>>(n, vector<bool>(m, false));

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int bridge_length = 2;
    int weight = 10;
    vector<int> truck_weights{7, 4, 5, 6};

    std::queue<std::pair<int, int>> q;
    int time = 1;
    int cur_weight = 0;
    int cur_index = 0;

    while (cur_index<truck_weights.size() || !q.empty()) {
        if (!q.empty() && q.front().second==time) {
            cur_weight -= q.front().first;
            q.pop();
        }

        if (cur_weight<weight && weight-cur_weight>=truck_weights[cur_index] && cur_index<truck_weights.size()) {
            q.push({truck_weights[cur_index], time+bridge_length}); // q에 넣을때 각각 트럭의 종료시간을 입력해줌
            cur_weight += truck_weights[cur_index++];
            time++;
        } else if(!q.empty()) {
            time = q.front().second;
        }
    }

    cout << time;
}

