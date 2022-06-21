#include <iostream>
#include <vector>
#include "../test_runner/test_runner.h"

class Solution {
public:
    bool canConstruct(std::string ransomNote, std::string magazine) {
        for (auto a : magazine) {
            chars[a]++;
        }
        for (auto a : ransomNote) {
            chars[a]--;
            if (chars[a]<0){
                return false;
            }
        }
        return true;
    }
private:
    int chars[256] = {0};
};

void SimpleTest(){
    {
        Solution sl;
        std::string ransomNote = "a";
        std::string magazine = "b";
        ASSERT_EQUAL(sl.canConstruct(ransomNote, magazine), false);
    }
    {
        Solution sl;
        std::string ransomNote = "aa";
        std::string magazine = "ab";
        ASSERT_EQUAL(sl.canConstruct(ransomNote, magazine), false);
    }
    {
        Solution sl;
        std::string ransomNote = "aa";
        std::string magazine = "aab";
        ASSERT_EQUAL(sl.canConstruct(ransomNote, magazine), true);
    }
}
int main() {
    TestRunner tr;
    RUN_TEST(tr,SimpleTest);
    return 0;
}