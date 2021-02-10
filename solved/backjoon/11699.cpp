//
// Created by yangheechan on 2021-02-10.
//
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

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

    std::cin >> n;
    std::stack<int> st;

    for (int i = 0; i<n; i++) {
        int val;
        std::cin >> val;
        arr.push_back(val);
    }

    int current = 0;
    int num = 1;

    string ret;

    for (int i = 0; i<2*n; ++i) {
        if (st.empty()) {
            if(num <= n) {
                st.push(num++);
                ret.push_back('+');
            }
        }
        else {
            if (st.top()==arr[current]) {
                st.pop();
                ret.push_back('-');
                current++;
            }
            else {
                if (num<=n) {
                    st.push(num++);
                    ret.push_back('+');
                }
            }
        }
    }

    if (ret.length()!=2*n) {
        std::cout << "NO";
    }
    else {
        for (auto& item: ret) {
            std::cout << item << "\n";
        }
    }
//    problem();

    return 0;
}