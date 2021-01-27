//
// Created by yangheechan on 2021-01-27.
//

#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using std::vector;
using std::string;

class Solution {
public:
    auto solve() -> void
    {
        int n;
        vector<int> numbers;
        vector<int> modeArray(8001, 0);

        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);

        std::cin >> n;

        int max = -4001, min = 4001;
        double avg = 0;
        int maxMode = -1;
        for (int i = 0; i<n; ++i) {
            int temp;
            std::cin >> temp;
            numbers.push_back(temp);
            avg += temp;
            min = std::min(min, temp);
            max = std::max(max, temp);
            modeArray[temp+4000]++;
            maxMode = std::max(modeArray[temp+4000], maxMode);
        }

        int mode_index;
        bool flag = false;
        for (int i = min+4000; i<=max+4000; i++) {
            if (modeArray[i]==maxMode) {
                mode_index = i;
                if(flag) break;
                flag = true;
            }
        }

        std::sort(numbers.begin(), numbers.end());

        int median = n%2==1 ? numbers[n/2] : numbers[n/2+1];

        std::cout << floor(avg/n+0.5) << "\n"; //산술 평균
        std::cout << median << "\n";               // 중앙 값
        std::cout << mode_index-4000 << "\n";       // 최빈 값
        std::cout << max-min;                      // 최대- 최소 차이
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