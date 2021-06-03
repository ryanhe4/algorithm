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

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    while (cin >> str) {
        if (str=="0") return 0;
        bool isPalindrome = true;
        for (int i = 0; i<str.size()/2; i++) {
            if (str[i] != str[str.size()-1 -i]) {
              cout << "no" <<"\n";
              isPalindrome = false;
              break;
            }
        }
        if(isPalindrome) {
            cout << "yes"<< "\n";
        }
    }
}