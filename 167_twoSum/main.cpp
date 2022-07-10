#include <iostream>
#include <vector>
#include "../test_runner/test_runner.h"
class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& numbers, int target) {
        auto it = numbers.begin();
        auto it_back = numbers.end() - 1;
        while (it<it_back){
            if (*it+*it_back == target){
                int first = it - numbers.begin() + 1;
                int second = it_back - numbers.begin() + 1;
                return {first,second};
            }
            if (*it+*it_back > target){
                it_back = std::prev(it_back);
            } else {
                it = std::next(it);
            }
        }
        return{};
    }
};
void SimpleTest() {
    {
        Solution sl;
        std::vector<int> v = {2,7,11,15};
        std::vector<int> result = {1,2};
        ASSERT_EQUAL(sl.twoSum(v,9), result);
    }
    {
        Solution sl;
        std::vector<int> v = {2,3,4};
        std::vector<int> result = {1,3};
        ASSERT_EQUAL(sl.twoSum(v,6), result);
    }
    {
        Solution sl;
        std::vector<int> v = {-1,0};
        std::vector<int> result = {1,2};
        ASSERT_EQUAL(sl.twoSum(v,-1), result);
    }
}
int main() {
    TestRunner tr;
    RUN_TEST(tr, SimpleTest);
    return 0;
}
