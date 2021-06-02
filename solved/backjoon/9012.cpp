//
// Created by yangheechan on 2021-06-02.
//

#include <bits/stdc++.h>
using std::vector;
using std::string;
using std::cin;
using std::cout;

int n;
int m;
string str;

vector<int> v;
vector<string> sv;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
vector<vector<bool>> visited;
vector<int> tracking;

//= vector<vector<bool>>(n, vector<bool>(m, false));
void check_VPS()
{
    std::stack<char> stack;
    for (int j = 0; j<str.size(); j++) {
        if (str[j]==')' && stack.empty()) {
            cout << "NO";
            return;
        }
        if (str[j]=='(') {
            stack.push(str[j]);
        }
        else {
            if (!stack.empty()) stack.pop();
            else {
                cout << "NO";
                return;
            }
        }
    }
    if (stack.empty()) {
        cout << "YES";
    }
    else {
        cout << "NO";
        return;
    }
}

int test9012()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i<n; i++) {
        cin >> str;
        check_VPS();
        cout <<"\n";
    }
}