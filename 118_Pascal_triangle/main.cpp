#include <iostream>
#include <vector>

#include "test_runner.h"

class Solution {
public:
    std::vector<std::vector<int>> generate(int numRows) {
        std::vector<std::vector<int>> result;
        result.reserve(numRows);
        for (int i = 0; i < numRows; ++i) {
            std::vector<int> vector_to_insert;
            vector_to_insert.resize(i+1);
            int j = 0;
            do{
                if (j == 0){
                    vector_to_insert[0] = 1;
                    vector_to_insert[i] = 1;
                } else {
                    vector_to_insert[j] = result[i-1][j-1] + result[i-1][j];
                    vector_to_insert[i-j] = result[i-1][j-1] + result[i-1][j];
                }
                j++;
            } while (j < (i+1)/ 2);
            if (i%2 ==0 && i!=0){
                vector_to_insert[j] = result[i-1][j-1] + result[i-1][j];
            }
            result.push_back(std::move(vector_to_insert));
        }
        return result;
    }
};

void SimpleTest(){
    {
        Solution sl;
        std::vector<std::vector<int>> result = {{1},{1,1},{1,2,1},{1,3,3,1},{1,4,6,4,1}};

        ASSERT_EQUAL(sl.generate(5), result);
    }
    {
        Solution sl;
        std::vector<std::vector<int>> result = {{1}};

        ASSERT_EQUAL(sl.generate(1), result);
    }
    {
        Solution sl;
        std::vector<std::vector<int>> result = {{1},{1,1},{1,2,1},{1,3,3,1},{1,4,6,4,1}, {1,5,10,10,5,1}, {1,6,15,20,15,6,1}};

        ASSERT_EQUAL(sl.generate(7), result);
    }
}
int main() {
    TestRunner tr;
    RUN_TEST(tr,SimpleTest);
    return 0;
}
