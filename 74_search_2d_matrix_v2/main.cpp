#include <iostream>
#include <vector>
#include <set>
#include "iterator"
#include "test_runner.h"

class Solution {
public:
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
        std::set<int> temp_set;
        std::for_each(matrix.begin(),matrix.end(),[&temp_set](auto a){temp_set.insert(a.begin(), a.end());});
        auto it = std::find(temp_set.begin(), temp_set.end(), target);
        if (it == temp_set.end()) {
            return false;
        } else {
            return true;
        }
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