#include <iostream>
#include <iterator>
#include "set"
#include "test_runner.h"
class Solution {
public:
    int lengthOfLongestSubstring(const std::string& str) {
        std::string anotherSubstring = "";
        for (int i = 0; i<str.size(); i++){
            if (auto it = anotherSubstring.find(str.at(i)) == str.npos){
                anotherSubstring.push_back(str.at(i));
            } else {
                if (longestSubstring_.size() < anotherSubstring.size()) {
                    longestSubstring_ = std::move(anotherSubstring);
                    anotherSubstring.clear();
                    anotherSubstring = longestSubstring_.substr((longestSubstring_.find(str.at(i))) + 1);
                } else {
                    anotherSubstring = anotherSubstring.substr((anotherSubstring.find(str.at(i))) + 1);
                }
                i--;
            }
        }
        if (longestSubstring_.size() < anotherSubstring.size()) {
            longestSubstring_ = std::move(anotherSubstring);
        }
        return longestSubstring_.size();
    }
private:
    std::string longestSubstring_ = "";
};

void SimpleTest(){
    Solution sl;
    ASSERT_EQUAL(sl.lengthOfLongestSubstring("abcabcbb"),3);
    Solution sl2;
    ASSERT_EQUAL(sl2.lengthOfLongestSubstring("bbbbb"),1);
    Solution sl3;
    ASSERT_EQUAL(sl3.lengthOfLongestSubstring("pwwkew"),3);
    Solution sl4;
    ASSERT_EQUAL(sl4.lengthOfLongestSubstring("abcabcbbpwwkeaw"),4);
    Solution sl5;
    ASSERT_EQUAL(sl5.lengthOfLongestSubstring("aab"),2);
    Solution sl6;
    ASSERT_EQUAL(sl6.lengthOfLongestSubstring("dvdf"),3);
    Solution sl7;
    ASSERT_EQUAL(sl7.lengthOfLongestSubstring("advadf"),4);
}

int main() {
    TestRunner tr;
    RUN_TEST(tr, SimpleTest);
    return 0;
}
