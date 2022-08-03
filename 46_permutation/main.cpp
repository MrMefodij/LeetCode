#include <iostream>
#include "../test_runner/test_runner.h"

class Solution {
public:
    static int factorial(int num){
        int result = 1;
        for (int i=1; i<=num; i++){
            result *= i;
        }
        return result;
    }

    void permute(std::vector<std::vector<int>>& result, std::vector<int> nums, int i) {
        if ( i == nums.size()){
            result.push_back(nums);
        } else {
            for (int j = i; j < nums.size(); j++){
                std::swap(nums[i], nums[j]);
                permute(result,nums,i+1);
            }
        }
    }

    std::vector<std::vector<int>> permute(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        result.reserve(factorial(nums.size()));
        permute(result, nums, 0);
        return result;
    }
};

void SimpleTest() {
    {
        Solution sl;
        std::vector<int> nums = {1,2,3};
        std::vector<std::vector<int>> result = {{1,2,3},
                                                {1,3,2},
                                                {2,1,3},
                                                {2,3,1},
                                                {3,1,2},
                                                {3,2,1}};
        ASSERT_EQUAL(sl.permute(nums), result);
    }
    {
        Solution sl;
        std::vector<int> nums = {0,1};
        std::vector<std::vector<int>> result = {{0,1},
                                                {1,0}};
        ASSERT_EQUAL(sl.permute(nums), result);
    }
    {
        Solution sl;
        std::vector<int> nums = {1};
        std::vector<std::vector<int>> result = {{1}};
        ASSERT_EQUAL(sl.permute(nums), result);
    }
}
int main() {
    TestRunner tr;
    RUN_TEST(tr, SimpleTest);
    return 0;
}
