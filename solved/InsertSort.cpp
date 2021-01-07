//
// Created by yangheechan on 2020-12-09.
//

#include <iostream>
#include <vector>

using std::vector;

int main()
{
    //variables
    int temp;
    vector<int> array{1, 10, 5, 8, 7, 6, 4, 3, 2, 9};

    //algorithm
    for(int i = 0 ; i < array.size()-1; ++i) {
        int j = i;
        while(array[j] > array[j+1]) {
            temp= array[j];
            array[j] = array[j+1];
            array[j+1] = temp;
            j--;
        }
    }
    //output
    for(auto& elem: array) {
        std::cout<<elem << " ";
    }
    return 0;
}