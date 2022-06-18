#include <iostream>
#include <vector>

#include "test_runner.h"

class Solution {
public:
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
        if (n == 0){
            return;
        } else if ( m == 0){
            nums1 = std::move(nums2);
            return;
        }
        nums1.resize(m);
        auto it_insert_before = nums1.begin();
        for ( auto insert = nums2.begin(); insert < nums2.end();){
            it_insert_before = std::find_if(it_insert_before, nums1.end(), [insert](auto a){
                return *insert<a;
            });
            auto last_insert = std::find_if(insert, nums2.end(), [it_insert_before](auto a){
                return *it_insert_before<a;
            });
            //std::cout << *insert <<" to " << *last_insert<<" insert before "<< *it_insert_before <<std::endl;
            if (it_insert_before != nums1.end()) {
                nums1.insert(it_insert_before, insert, last_insert);
            }else{
                nums1.insert(nums1.end(),insert, nums2.end());
                return;
            }
            insert = last_insert;
        }

    }
};

void SimpleTest(){
    {
        Solution sl;
        std::vector<int> v1 = {1,2,3,0,0,0};
        int m = 3;

        std::vector<int> v2 = {2,5,6};
        int n = 3;

        std::vector<int> result = {1,2,2,3,5,6};
        sl.merge(v1, m, v2, n);

        ASSERT_EQUAL(v1 , result);
    }
    {
        Solution sl;
        std::vector<int> v1 = {1};
        int m = 1;

        std::vector<int> v2 = {};
        int n = 0;

        std::vector<int> result = {1};
        sl.merge(v1, m, v2, n);

        ASSERT_EQUAL(v1 , result);
    }
    {
        Solution sl;
        std::vector<int> v1 = {0};
        int m = 0;

        std::vector<int> v2 = {1};
        int n = 1;

        std::vector<int> result = {1};
        sl.merge(v1, m, v2, n);

        ASSERT_EQUAL(v1 , result);
    }
}
int main() {
    TestRunner tr;
    RUN_TEST(tr,SimpleTest);
    return 0;
}
