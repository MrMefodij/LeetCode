#include <iostream>
#include <vector>
#include "../test_runner/test_runner.h"

class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        for (auto a : s) {
            chars[a]++;
        }
        for (auto a : t) {
            chars[a]--;
            if (chars[a]<0){
                return false;
            }
        }
        for (int i = 0; i < 256; ++i) {
            if (chars[i]!=0){
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
        std::string ransomNote = "anagram";
        std::string magazine = "nagaram";
        ASSERT_EQUAL(sl.isAnagram(ransomNote, magazine), true);
    }
    {
        Solution sl;
        std::string ransomNote = "rat";
        std::string magazine = "car";
        ASSERT_EQUAL(sl.isAnagram(ransomNote, magazine), false);
    }
}
int main() {
    TestRunner tr;
    RUN_TEST(tr,SimpleTest);
    return 0;
}