#include <iostream>
#include <vector>
#include "iterator"
#include "test_runner.h"

class Solution {
public:
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
        std::vector<int> column_set_back;
        std::vector<int> column_set_front;
        if (matrix.size() >1) {
            column_set_back.reserve(matrix.size());
            column_set_front.reserve(matrix.size());

            for (int i = 0; i < matrix.size(); i++) {
                column_set_back.push_back(matrix.at(i).back());
                column_set_front.push_back(matrix.at(i).front());
            }
            auto it_column_front = std::lower_bound(column_set_front.begin(), column_set_front.end(), target);
            auto it_column_back = std::lower_bound(column_set_back.begin(), column_set_back.end(), target);

            if ((it_column_front == column_set_front.begin() && *it_column_front != target)
                || it_column_back == column_set_back.end() ||
                (*it_column_back == *it_column_front && *it_column_front != target)) {
                return false;
            } else if (*it_column_front == target || *it_column_back == target) {
                return true;
            }
            auto it_row = std::lower_bound(matrix.at(it_column_back - column_set_back.begin()).begin(),
                                           matrix.at(it_column_back - column_set_back.begin()).end(),
                                           target);
            if (it_row == matrix.at(it_column_back - column_set_back.begin()).end()) {
                return false;
            } else if (*it_row == target) {
                return true;
            }
        } else {
            auto it_row = std::lower_bound(matrix.at(0).begin(), matrix.at(0).end(), target);
            if (it_row == matrix.at(0).end()) {
                return false;
            } else if (*it_row == target) {
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
    {
        Solution sl;
        std::vector<std::vector<int>> v1 =
                {{1},
                 {3}};

        ASSERT_EQUAL(sl.searchMatrix(v1,69), false);
    }
    {
        Solution sl;
        std::vector<std::vector<int>> v1 =
                {{1},
                 {3}};

        ASSERT_EQUAL(sl.searchMatrix(v1,0), false);
    }
    {
        Solution sl;
        std::vector<std::vector<int>> v1 =
                {{1},
                 {3}};

        ASSERT_EQUAL(sl.searchMatrix(v1,2), false);
    }
    {
        Solution sl;
        std::vector<std::vector<int>> v1 =
                {{1, 3}};

        ASSERT_EQUAL(sl.searchMatrix(v1,2), false);
    }
    {
        Solution sl;
        std::vector<std::vector<int>> v1 =
                {{1},
                 {3}};

        ASSERT_EQUAL(sl.searchMatrix(v1,4), false);
    }
    {
        Solution sl;
        std::vector<std::vector<int>> v1 =
                {{1,3,5,7},{10,11,16,20},{23,30,34,50}};

        ASSERT_EQUAL(sl.searchMatrix(v1,30), true);
    }
    {
        Solution sl;
        std::vector<std::vector<int>> v1 =
                {{1,3,5,7},{10,11,16,20},{23,30,34,50}};

        ASSERT_EQUAL(sl.searchMatrix(v1,24), false);
    }
    {
        Solution sl;
        std::vector<std::vector<int>> v1 =
                {{1}};

        ASSERT_EQUAL(sl.searchMatrix(v1,1), true);
    }
}

int main() {
    TestRunner tr;
    RUN_TEST(tr,SimpleTest);
    return 0;
}