#include <iostream>
#include <vector>
#include <set>
#include "test_runner.h"

class Solution {
public:
    int firstUniqChar(const std::string& s) {
        std::set<char> chars;
        for (auto it_begin = s.begin(); it_begin < s.end(); ++it_begin) {
            auto it = std::find(it_begin + 1, s.end(), *it_begin);
            if (it == s.end() && chars.count(*it_begin) == 0){
                return it_begin - s.begin();
            } else {
                chars.insert(*it);
            }
        }
        return -1;
    }
};

void SimpleTest(){
    {
        Solution sl;
        ASSERT_EQUAL(sl.firstUniqChar("leetcode"), 0);
    }
    {
        Solution sl;
        ASSERT_EQUAL(sl.firstUniqChar("loveleetcode"), 2);
    }
    {
        Solution sl;
        ASSERT_EQUAL(sl.firstUniqChar("aabb"), -1);
    }
}
int main() {
    TestRunner tr;
    RUN_TEST(tr,SimpleTest);
    return 0;
}