//
// Created by yangheechan on 2021-01-20.
// KMP algorithm

#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

class Solution {
public:
    auto getPartialMatch(const string& pattern) -> vector<int>
    {
        int m = pattern.size();
        vector<int> pi = vector<int>(m, 0);
        int begin = 1, matched = 0;
        while (begin+matched<m) {
            if (pattern[begin+matched]==pattern[matched]) {
                ++matched;
                pi[begin+matched-1] = matched;
            }
            else {
                if (matched==0) ++begin;
                else {
                    begin += matched-pi[matched-1];
                    matched = pi[matched-1];
                }
            }
        }
        return pi;
    }
    auto KMP(const string& H, const string& N) -> void
    {
        int m = H.size(), n = N.size();
        vector<int> pi = getPartialMatch(N);
        int matched = 0, begin = 0;

        while (begin<=m-n) {
            if (matched<n && H[begin+matched]==N[matched]) {
                ++matched;
                if (matched==n) std::cout << begin << " ";
            }
            else {
                if (matched==0) ++begin;
                else {
                    begin += matched-pi[matched-1];
                    matched = pi[matched-1];
                }
            }
        }
    }
    auto KMP2(const string& H, const string& N) -> void
    {
        int n = H.size(), m = N.size();
        vector<int> pi = getPartialMatch(N);
        int matched = 0;

        for (int i = 0; i<n; ++i) {
            while (matched > 0 && H[i] != N[matched]) matched = pi[matched-1];
            if(H[i] == N[matched]) {
                ++matched;
                if(matched == m) {
                    std::cout << i-m+1 << " ";
                    matched = pi[matched-1];
                }
            }
        }
    }
};

int main()
{
    // input variables


    // process
    Solution s;
    s.KMP("ababacabacaabacaaba", "abacaaba");

    return 0;
}