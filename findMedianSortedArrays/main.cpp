#include <iostream>
#include <vector>
#include "test_runner.h"

class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        int p1 = nums1.size();
        int p2 = nums2.size();
        int count_sum = p1 + p2;
        double result = 0;
        if (count_sum == 0){
            return {};
        }
        p1--; p2--;
        while ( 0 < count_sum){
            if (p2 < 0 || (p1 >= 0 && nums1[p1] > nums2[p2])){
                result = nums1[p1--];
            } else {
                result = nums2[p2--];
            }
            count_sum -= 2;
        }
        if (count_sum == 0) {
            if (p2 < 0 || (p1 >= 0 && nums1[p1] > nums2[p2]))
                result= result+nums1[p1];
            else
                result= result+nums2[p2];
            result /= 2.0;
        }
        return result;
    }
};

void SimpleTest(){
    {
        std::vector<int> v1 = {1,3};
        std::vector<int> v2 = {2};
        Solution sl;
        ASSERT_EQUAL(sl.findMedianSortedArrays(v1,v2),2);
    }
    {
        std::vector<int> v1 = {1,2};
        std::vector<int> v2 = {3,4};
        Solution sl;
        ASSERT_EQUAL(sl.findMedianSortedArrays(v1,v2),2.5);
    }
    {
        std::vector<int> v1 = {1, 3, 5, 7};
        std::vector<int> v2 = {2, 6, 10};
        Solution sl;
        ASSERT_EQUAL(sl.findMedianSortedArrays(v1,v2),5);
    }
}

int main() {
    TestRunner tr;
    RUN_TEST(tr, SimpleTest);
    return 0;
}
