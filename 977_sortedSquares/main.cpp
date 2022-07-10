#include <iostream>
#include <vector>
#include "../test_runner/test_runner.h"
class Solution {
public:
    std::vector<int> sortedSquares(std::vector<int>& nums) {
        std::for_each(nums.begin(), nums.end(), [](int& a){
            return a = a*a;
        });
        std::sort(nums.begin(), nums.end());
        return nums;
    }
};
void SimpleTest() {
    {
        Solution sl;
        std::vector<int> v = {-4,-1,0,3,10};
        std::vector<int> result = {0,1,9,16,100};
        ASSERT_EQUAL(sl.sortedSquares(v), result);
    }
    {
        Solution sl;
        std::vector<int> v = {-7,-3,2,3,11};
        std::vector<int> result = {4,9,9,49,121};
        ASSERT_EQUAL(sl.sortedSquares(v), result);
    }
}
int main() {
    TestRunner tr;
    RUN_TEST(tr, SimpleTest);
    return 0;
}
