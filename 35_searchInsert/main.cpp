#include <iostream>
#include "../test_runner/test_runner.h"
class Solution {
public:
    int searchInsert(std::vector<int>& nums, int target) {
        return std::lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    }
};
void SimpleTest() {
    {

    }
}
int main() {
    TestRunner tr;
    RUN_TEST(tr, SimpleTest);
    return 0;
}
