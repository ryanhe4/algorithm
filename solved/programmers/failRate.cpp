//
// Created by yangheechan on 2021-03-22.
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
std::queue<std::pair<int, int>> que;
vector<std::pair<int, int>> A;

class failRate {
public:
    std::pair<int, int> _p;
    int _index;

    failRate(std::pair<int, int> p_, int index_)
            :_p(p_), _index(index_) { }

    bool operator<(failRate& fr) const
    {
        double base = 0, arg = 0;
        base = _p.second==0 ? 0 : _p.first/(double) _p.second;
        arg = fr._p.second==0 ? 0 : fr._p.first/(double) fr._p.second;
        if (base!=arg) return base>arg;
        else return _index<fr._index;
    }
};

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N = 5;
    vector<int> stages{2, 1, 2, 6, 2, 3, 3, 3};

    vector<std::pair<int, int>> value(N, {0, 0});

    for (auto& e : stages) {
        for (int i = 0; i<e; i++) {
            if (i>=N) continue;
            value[i].second++;
            if (i==e-1) {
                value[i].first++;
            }
        }
    }
    int index = 0;
    vector<failRate> v_fr;
    for (auto& e: value) {
        v_fr.push_back(failRate(e, index+1));
        index++;
    }

    std::sort(v_fr.begin(), v_fr.end());

    for (auto& e: v_fr) {
        cout << e._p.first/(double) e._p.second << " ";
        cout << e._index << "\n";
    }
}

