//
// Created by projector-user on 4/29/21.
//

#include <bits/stdc++.h>

using std::vector;
using std::string;

vector<vector<int>> arr;
vector<vector<bool>> visited;
int n;
int m;

//(0, 0)을 기준으로 왼쪽, 오른쪽 아래
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int num;
    std::cin >> num;
    vector<int> v;

    for (int i = 0; i<num; i++) {
        int item;
        std::cin >> item;

        v.push_back(item);
    }
    std::sort(v.begin(), v.end());
    int cover;
    std::cin >> cover;
    int interval = 0; // A <= x <= B
    for (int i = 1; i<num; i++) {
        if (cover<v[i]) {
            interval = i;
            break;
        }
        if(cover == v[i]) {
            std::cout << 0;
            return 0;
        }
    }

    int ans = 0;
    for (int i = v[interval-1]+1; i<v[interval]; i++) {
        for (int j = i+1; j<v[interval]; j++) {
            if (i>cover) break;
            if( cover > j) continue; // equal :: i <= cover <= j
            ans++;
        }
    }
    std::cout << ans;
    return 0;
}