//
// Created by yangheechan on 2021-02-18.
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

vector<bool> visited;
vector<bool> finished;
vector<int> v;
int count;
void dfs(int cur)
{
    int nxt = v[cur];
    visited[cur] = true;

    if (!visited[nxt]) dfs(nxt);
    else {
        if (!finished[nxt]) {
            for (int i = nxt; i!=cur; i = v[i]) {
                count++;
            }
            count++;
        }
    }
    finished[cur] = true;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--) {
        std::cin >> n;
        v = vector<int>(n+1, 0);
        for (int i = 1; i<=n; ++i) {
            std::cin >> m;
            v[i] = m;
        }
        visited = vector<bool>(n+1, false);
        finished = vector<bool>(n+1, false);
        count = 0;
        for (int j = 1; j<=n; j++) {
            if (!visited[j]) {
                dfs(j);
            }
        }
        std::cout << n-count << "\n";
    }

    std::queue<std::pair<int, int>> q;
    vector<int> ret;

    return 0;
}