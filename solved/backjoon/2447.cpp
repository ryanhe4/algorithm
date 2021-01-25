//
// Created by yangheechan on 2021-01-25.
//

#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

class Solution {
public:
    auto star(vector<string>& stars, int n, int i, int j, bool& flag) -> void
    {
        // 기저사례
        if (flag && n!= 1) {
            for (int k = 0; k<n; k++) {
                for (int l = 0; l<n; l++) {
                    stars[i+k][j+l] = ' ';
                }
            }
            return;
        }
        else if (n==1 && i%3==1 && j%3==1) {
//            std::cout << "i: " << i << "j: " << j << "\n";
            stars[i][j] = ' ';
            return;
        }
        else if (n==1) {
            return;
        }

        for (int k = 0; k<3; k++) {
            for (int l = 0; l<3; l++) {
                if (k==1 && l==1) {
                    flag = true;
                    star(stars, n/3, i+(k*(n/3)), j+(l*(n/3)), flag);
                    flag = false;
                }
                else {
                    star(stars, n/3, i+(k*(n/3)), j+(l*(n/3)), flag);
                }
            }
        }

    }
    auto solve() -> void
    {
        int n;
        std::cin >> n;

        vector<string> stars;
        for (int i = 0; i<n; i++) {
            stars.push_back(string(n, '*'));
        }
        bool flag = false;
        star(stars, n, 0, 0, flag);

        for (auto& elem: stars) {
            std::cout << elem << "\n";
        }
    }
};

int main()
{
    // input variables


    // process
    Solution s;
    s.solve();

    return 0;
}