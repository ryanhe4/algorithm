//
// Created by yangheechan on 2021-02-01.
//

#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

class Solution {
public:
    auto solve() -> void
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);

        int t;
        std::cin >> t;
        for (int test = 0; test<t; test++) {
            arr.clear();
            std::cin >> n;
            for (int i = 0; i<2; i++) {
                vector<int> line;
                for (int j = 0; j<n; j++) {
                    int temp;
                    std::cin >> temp;
                    line.push_back(temp);
                }
                arr.push_back(line);
            }
            cache = vector<vector<int>>(n, vector<int>(3, -1));
            std::cout << sticker(0, 0) <<"\n";
        }
    }
    int sticker(int c, int status) // vector<int>& picked,
    {
        if (c>=n) return 0;

        int& ret = cache[c][status];
        if (ret!=-1) return ret;

        //2차원 bool 배열로 선택가능성 체크
        ret = sticker(c+1, 0);
        if (status!=1) ret = std::max(ret, sticker(c+1, 1)+arr[0][c]);
        if (status!=2) ret = std::max(ret, sticker(c+1, 2)+arr[1][c]);

        return ret;
    }

    string replaceAll(string orig, string pattern, string to)
    {
        auto start_pos = 0;
        while ((start_pos = orig.find(pattern, start_pos))!=string::npos) {
            orig.replace(start_pos, pattern.length(), to);
            start_pos += to.length();
        }
        return orig;
    }

private:
    vector<vector<int>> arr{};
    vector<vector<int>> cache{};
    int n{};

};

int main()
{
    // input variables
    // process
    Solution s;
    s.solve();

    return 0;
}