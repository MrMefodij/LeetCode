#include <iostream>
#include <vector>
#include "../test_runner/test_runner.h"
class Solution {
public:
    void moveZeroes(std::vector<int>& nums) {
        auto it = nums.begin();
        auto it_zero = std::remove(it, nums.end(), 0);
        for (;it_zero< nums.end();it_zero++){
            *it_zero = 0;
        }
    }
};
void SimpleTest() {
    {
        Solution sl;
        std::vector<int> v = {0,1,0,3,12};
        sl.moveZeroes(v);
        std::vector<int> result = {1,3,12,0,0};
        ASSERT_EQUAL(v, result);
    }
    {
        Solution sl;
        std::vector<int> v = {0};
        sl.moveZeroes(v);
        std::vector<int> result = {0};
        ASSERT_EQUAL(v, result);
    }
}
int main() {
    TestRunner tr;
    RUN_TEST(tr, SimpleTest);
    return 0;
}
