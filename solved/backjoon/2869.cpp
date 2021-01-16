//
// Created by yangheechan on 2021-01-16.
//

#include <iostream>

using std::vector;

class Solution {
public:
    static auto solve(int A, int B, int V) -> void
    {
        int diff = A-B;

        // 총 올라가야하는 높이 : V-B, 하루에 오를 수 있는 높이 A-B
        // 일부러 mod값이 0일 수 없도록 만들어 두고(-1) 후에 +1을 해서 맞춰준다.
        int day = (V-B-1)/diff+1;

        std::cout << day;
    }
};

int main()
{
    // input variables
    int A, B, V;

    std::cin >> A >> B >> V;

    // process
    Solution::solve(A, B, V);

    return 0;
}