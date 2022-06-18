#include <iostream>
#include "test_runner.h"

class Solution {
public:
    int maxSubArray(std::vector<int>& nums) {
        auto it_other = nums.begin();
        int other_sum = 0;

        auto first_positive = std::find_if(nums.begin(), nums.end(), [](int a){
            return a>0;
        });

        if (first_positive != nums.end()){
            sum = *first_positive;
            other_sum = *first_positive;
            for (auto it = std::next(first_positive); it < nums.end(); it++){
                if (other_sum + *it > 0){
                    other_sum += *it;
                    if (other_sum > sum ){
                        sum =other_sum;
                    }
                } else {
                    other_sum = 0;
                }

            }
        } else {
            return *std::max_element(nums.begin(), nums.end());
        }
        return sum;
    }
private:
    int sum = 0;
};

void SimpleTest(){
    {
        Solution sl;
        std::vector<int> v = {-2,-8,1,-3,4,-1,2,1,-5,4};
        ASSERT_EQUAL(sl.maxSubArray(v), 6);
    }
    {
        Solution sl;
        std::vector<int> v = {1};
        ASSERT_EQUAL(sl.maxSubArray(v), 1);
    }
    {
        Solution sl;
        std::vector<int> v = {5,4,-1,7,8};
        ASSERT_EQUAL(sl.maxSubArray(v), 23);
    }
    {
        Solution sl;
        std::vector<int> v = {-5,-4,-1,-7,-8};
        ASSERT_EQUAL(sl.maxSubArray(v), -1);
    }
}
int main() {
    TestRunner tr;
    RUN_TEST(tr,SimpleTest);
    return 0;
}
