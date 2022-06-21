#include <iostream>
#include <vector>

#include "test_runner.h"

class Solution {
public:
    std::vector<std::vector<int>> matrixReshape(std::vector<std::vector<int>>& mat, int r, int c) {
        if (mat.size() * mat.at(0).size() != r * c){
            return mat;
        }x
        std::vector<int> temp_vector;
        temp_vector.reserve(r * c);
        for (auto i = 0; i<mat.size(); i++){
            temp_vector.insert(temp_vector.end(),std::move_iterator(mat.at(i).begin()),std::move_iterator(mat.at(i).end()));
        }
        std::vector<std::vector<int>> result;
        result.reserve(r);
        for(int i = 0; i < r; i++){

            std::vector<int> vector_to_insert;
            //std::cout << *temp_vector.begin() << ' ' <<*std::next(temp_vector.begin() + c-1) <<std::endl;
            vector_to_insert.insert(vector_to_insert.begin(), temp_vector.begin(),
                                    temp_vector.begin() + c);
            temp_vector.erase(temp_vector.begin(),
                              temp_vector.begin() + c);
            result.push_back(std::move(vector_to_insert));
        }
        return result;
    }
};

void SimpleTest(){
    {
        Solution sl;
        std::vector<std::vector<int>> v1 = {{1,2},{3,4}};
        std::vector<std::vector<int>> result = {{1, 2, 3, 4}};

        ASSERT_EQUAL(sl.matrixReshape(v1, 1, 4), result);
    }
    {
        Solution sl;
        std::vector<std::vector<int>> v1 = {{1,2},{3,4}};
        std::vector<std::vector<int>> result = {{1,2},{3,4}};

        ASSERT_EQUAL(sl.matrixReshape(v1, 2, 4), result);
    }
    {
        Solution sl;
        std::vector<std::vector<int>> v1 = {{1,2},{3,4},{5,6}};
        std::vector<std::vector<int>> result = {{1, 2, 3},{4,5,6}};

        ASSERT_EQUAL(sl.matrixReshape(v1, 2, 3), result);
    }
    {
        Solution sl;
        std::vector<std::vector<int>> v1 = {{1,2},{3,4}};
        std::vector<std::vector<int>> result = {{1},{2},{3},{4}};

        ASSERT_EQUAL(sl.matrixReshape(v1, 4, 1), result);
    }
}
int main() {
    TestRunner tr;
    RUN_TEST(tr,SimpleTest);
    return 0;
}
