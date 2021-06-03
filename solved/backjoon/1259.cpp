//
// Created by yangheechan on 2021-06-03.
//
#include <bits/stdc++.h>
using std::vector;
using std::string;
using std::cin;
using std::cout;

int n;
string str;

int palindrome()
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