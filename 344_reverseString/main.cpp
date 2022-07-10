#include <iostream>
#include <vector>
#include "../test_runner/test_runner.h"
class Solution {
public:
    void reverseString(std::vector<char>& s) {
        auto it = s.begin();
        auto it_r = s.rbegin();
        while (it - s.begin() < s.rend() - it_r){
            if (*it != *it_r){
                char tmp = *it;
                *it = *it_r;
                *it_r = tmp;
            }
            it++;
            it_r++;
        }
    }
};
void SimpleTest() {
    {
        Solution sl;
        std::vector<char> v = {'h','e','l','l','o'};
        sl.reverseString(v);
        std::vector<char> result = {'o','l','l','e','h'};
        ASSERT_EQUAL(v, result);
    }
    { //"H","a","n","n","a","h"
        Solution sl;
        std::vector<char> v = {'H','a','n','n','a','h'};
        sl.reverseString(v);
        std::vector<char> result = {'h','a','n','n','a','H'};
        ASSERT_EQUAL(v, result);
    }
}
int main() {
    TestRunner tr;
    RUN_TEST(tr, SimpleTest);
    return 0;
}
