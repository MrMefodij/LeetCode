#include <iostream>
#include <vector>
#include "test_runner.h"

class Solution {
public:
    std::vector<int> intersect(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::vector<int> search_e;
        std::vector<int> pool;
        std::vector<int> result;
        if (nums1.size() > nums2.size()){
            search_e = std::move(nums2);
            pool = std::move(nums1);
        } else {
            search_e = std::move(nums1);
            pool = std::move(nums2);
        }
        result.reserve(search_e.size());
        int real_size = 0;
        for (auto it_search = search_e.begin(); it_search < search_e.end(); it_search++) {
            auto it_pool = std::find(pool.begin(), pool.end(), *it_search);
            if (it_pool != pool.end()){
                result.push_back(*it_pool);
                pool.erase(it_pool);
                real_size++;
            }
        }
        result.resize(real_size);
        return result;
    }
};
void SimpleTest(){
    {
        Solution sl;
        std::vector<int> v1 = {1,2,2,1};
        std::vector<int> v2 = {2,2};

        std::vector<int> result = {2,2};

        ASSERT_EQUAL(sl.intersect(v1,  v2), result);
    }
    {
        Solution sl;
        std::vector<int> v1 = {4,9,5};
        std::vector<int> v2 = {9,4,9,8,4};

        std::vector<int> result = {4,9};

        ASSERT_EQUAL(sl.intersect(v1,  v2), result);
    }
    {
        Solution sl;
        std::vector<int> v1 = {4,7,9,7,6,7};
        std::vector<int> v2 = {5,0,0,6,1,6,2,2,4};

        std::vector<int> result = {4,6};

        ASSERT_EQUAL(sl.intersect(v1,  v2), result);
    }
}
int main() {
    TestRunner tr;
    RUN_TEST(tr,SimpleTest);
    return 0;
}

