#include <iostream>
#include <vector>
#include "../test_runner/test_runner.h"

class Solution {
public:
    void rotate(std::vector<int>& nums, int k) {
        if (k > nums.size()){
            k = k % nums.size();
        }
        if (k == 0 || nums.size() < 2) return;
        std::vector<int> tmp(nums.size());
        for (int i = 0; i < nums.size(); ++i) {
            if (i + k < nums.size()){
                tmp[i + k] = nums.at(i);
            } else {
                tmp[i + k -nums.size()] = nums.at(i);
            }
        }
        std::move(tmp.begin(), tmp.end(), nums.begin());
    }
};

void SimpleTest() {
    {
        Solution sl;
        std::vector<int> v = {1,2,3,4,5,6,7};
        std::vector<int> result = {5,6,7,1,2,3,4};
        sl.rotate(v,3);
        ASSERT_EQUAL(v, result);
    }
    {
        Solution sl;
        std::vector<int> v = {-1,-100,3,99};
        std::vector<int> result = {3,99,-1,-100};
        sl.rotate(v,2);
        ASSERT_EQUAL(v, result);
    }
}
int main() {
    TestRunner tr;
    RUN_TEST(tr, SimpleTest);
    return 0;
}
