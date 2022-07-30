#include <iostream>
#include <array>
#include "../test_runner/test_runner.h"

class Solution {
public:
    bool matches(const std::array<int,26>& s1map, const std::array<int,26>& s2map) {
        for (int i = 0; i < 26; i++) {
            if (s1map[i] != s2map[i] )
                return false;
        }
        return true;
    }

    bool checkInclusion(std::string& s1, const std::string& s2) {
        if (s1 == s2) { return true; }
        if (s1 == "") { return true; }
        if (s2 == "") { return false; }
        if(s1.size() > s2.size()) {return false;}

        for (auto a : s1) {
            word[a - 'a']++;
        }
        for (int i = 0; i < s2.size(); i++){
            std::array<int,26> dictionary = {0};
            for (int j = 0; j < s1.size() && i+j<s2.size(); j++) {
                dictionary[s2.at(i + j) - 'a']++;
            }
            if (matches(word, dictionary))
                return true;
        }
        return false;
    }
private:
    std::array<int,26> word = {0};
};

void SimpleTest(){
    {
        Solution sl;
        std::string a = "ab";
        std::string b = "eidbaooo";
        ASSERT_EQUAL(sl.checkInclusion(a,b),true);
    }
    {
        Solution sl;
        std::string a = "ab";
        std::string b = "eidboaoo";
        ASSERT_EQUAL(sl.checkInclusion(a,b),false);
    }
    {
        Solution sl;
        std::string a = "ab";
        std::string b = "eidaboaoo";
        ASSERT_EQUAL(sl.checkInclusion(a,b),true);
    }
    {
        Solution sl;
        std::string a = "abc";
        std::string b = "bbbca";
        ASSERT_EQUAL(sl.checkInclusion(a,b),true);
    }
    {
        Solution sl;
        std::string a = "rvwrk";
        std::string b = "lznomzggwrvrkxecjaq";
        ASSERT_EQUAL(sl.checkInclusion(a,b),true);
    }
};

int main() {
    TestRunner tr;
    RUN_TEST(tr, SimpleTest);
    return 0;
}
