#include <iostream>
#include <vector>
#include <set>

#include "test_runner.h"

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        //std::map<int,int> nums_set;
        for (auto it = nums.begin(); it != nums.end(); it++) {
            auto result = std::find(next(it), nums.end(), (target-*it));
            if (result!= nums.end()){
                return {int(it - nums.begin()),int(result - nums.begin())};
            }
        }
        return {};
    }
};

void Examples(){
    Solution sl;
    std::vector<int> nums = {2,7,11,15};
    ASSERT_EQUAL(sl.twoSum(nums,9),std::vector<int> ({0,1}));
    sl.twoSum(nums,9);
    nums = {3,2,4};
    sl.twoSum(nums,6);
    ASSERT_EQUAL(sl.twoSum(nums,6),std::vector<int> ({1,2}));
    nums = {3,3};
    sl.twoSum(nums,6);
    ASSERT_EQUAL(sl.twoSum(nums,6),std::vector<int> ({0,1}));
}

int main() {
    TestRunner tr;
    RUN_TEST(tr,Examples);
    return 0;
}
