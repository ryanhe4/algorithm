//
// Created by yangheechan on 2021-02-15.
//

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <list>
#include <functional>
#include <cmath>
#include <algorithm>
#include <numeric>

using std::vector;
using std::string;

vector<int> arr;
vector<std::pair<string, string>> arr_pair;
vector<vector<int>> arr_td;
vector<vector<int>> cache{};
vector<vector<bool>> visited;
int n;
int m;
int count;
string s;

void problem(int v) { }

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int i = 1;
    while (true) {
        std::stack<int> st;
        int ret = 0;
        std::cin >> s;
        if (s.find('-')!=string::npos) {
            break;
        }

        for (auto& c:s) {
            if (c=='{') {
                st.push(c);
            }
            else {
                if (!st.empty()) {
                    st.pop();
                }
                else { ret++;
                    st.push('{');
                }
            }
        }
        ret += st.size()/2;
        std::cout << i++ << ". " << ret << "\n";
    }

//    problem();

    return 0;
}