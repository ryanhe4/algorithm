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

void subAccum(string s, int r)
{
    int index = 0;
    int point;
    while(isdigit(s[index])){
        if(index == 1) {
            point = 10;
            index++;
            break;
        }
        point = atoi(&s[index]);
        index++;
    }

    cout << point <<" ";

    if (s[index]=='S') {
    }
    else if (s[index]=='D') {
        point = point*point;
    }
    else if (s[index]=='T') {
        point = point*point*point;
    }

    if (s.size()>=index+1) {
        if (s[index+1]=='*') {
            point *= 2;
            if (r!=0) {
                v[r-1] *= 2;
            }
        }
        else if (s[index+1]=='#') {
            point *= -1;
        }
    }
    cout << point << "\n";
    v[r] = point;
}

void processing(string dartResult)
{
    int row = 0;
    string subStr;

    for (int i = 0; i<dartResult.size(); i++) {
        if (i!=0 && isdigit(dartResult[i])) {
            subAccum(subStr, row++);
            subStr.clear();
        }
        subStr.push_back(dartResult[i]);
        // i+1(다음번)이 숫자면
        if (isdigit(dartResult[i]) && isdigit(dartResult[i+1])) {
            subStr.push_back(dartResult[i+1]);
            i++;
        }
    }
    subAccum(subStr, row);
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    v = vector<int>(3, 0);

    processing(string("1S2D*3T"));

    int sum = 0;
    for (int i = 0; i<v.size(); i++) {
        sum += v[i];
    }
    cout << sum;
}

