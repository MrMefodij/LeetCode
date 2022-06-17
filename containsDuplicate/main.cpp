#include <iostream>
#include <vector>
#include "test_runner.h"

class Solution {
public:
    bool containsDuplicate(std::vector<int>& nums) {
        std::set<int> s_nums(nums.begin(), nums.end());
        return nums.size() != s_nums.size();
    }
private:

};

void SimpleTest(){
    {
        Solution sl;
        std::vector<int> v = {1,2,3,1};
        ASSERT_EQUAL(sl.containsDuplicate(v), true);
    }
    {
        Solution sl;
        std::vector<int> v = {1,2,3,4};
        ASSERT_EQUAL(sl.containsDuplicate(v), false);
    }
    {
        Solution sl;
        std::vector<int> v = {1,1,1,3,3,4,3,2,4,2};
        ASSERT_EQUAL(sl.containsDuplicate(v), true);
    }
}
int main() {
    TestRunner tr;
    RUN_TEST(tr,SimpleTest);
    return 0;
}
