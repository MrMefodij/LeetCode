#include <iostream>
#include <vector>
#include "iterator"
#include "test_runner.h"

class Solution {
public:
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
        std::vector<int> column_set;
        column_set.reserve(matrix.size());
        for (int i = 0; i < matrix.size(); i++){
            column_set.push_back(*matrix.at(i).begin());
        }
        auto it_column = std::lower_bound(column_set.begin(), column_set.end(), target);
        if ( *it_column == target){
            return true;
        }
        if (it_column != column_set.end()) {
            auto it_row = std::lower_bound(matrix.at(it_column - column_set.begin() - 1).begin(),
                                           matrix.at(it_column - column_set.begin() - 1).end(), target);
            if (*it_row == target){
                return true;
            }
        } else {
            auto it_row = std::lower_bound(matrix.at(it_column - column_set.begin() -1 ).begin(),
                                           matrix.at(it_column - column_set.begin() -1 ).end(), target);

            if (it_row !=matrix.at(it_column - column_set.begin()).end() && *it_row == target){
                return true;
            }
        }
        return false;
    }
};

void SimpleTest(){
    {
        Solution sl;
        std::vector<std::vector<int>> v1 =
                {{1,3,5,7},
                 {10,11,16,20},
                 {23,30,34,60}};

        ASSERT_EQUAL(sl.searchMatrix(v1,3), true);
    }

    {
        Solution sl;
        std::vector<std::vector<int>> v1 =
                {{1,3,5,7},
                 {10,11,16,20},
                 {23,30,34,60}};

        ASSERT_EQUAL(sl.searchMatrix(v1,13), false);
    }
    {
        Solution sl;
        std::vector<std::vector<int>> v1 =
                {{1}};

        ASSERT_EQUAL(sl.searchMatrix(v1,0), false);
    }
    {
        Solution sl;
        std::vector<std::vector<int>> v1 =
                {{1}};

        ASSERT_EQUAL(sl.searchMatrix(v1,2), false);
    }
    {
        Solution sl;
        std::vector<std::vector<int>> v1 =
                {{1,3,5,7},
                 {10,11,16,20},
                 {23,30,34,60}};

        ASSERT_EQUAL(sl.searchMatrix(v1,69), false);
    }
}
int main() {
    TestRunner tr;
    RUN_TEST(tr,SimpleTest);
    return 0;
}