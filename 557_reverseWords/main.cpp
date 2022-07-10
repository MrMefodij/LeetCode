#include <iostream>
#include <vector>
#include "../test_runner/test_runner.h"
class Solution {
public:
    std::string reverseWords(std::string& str) {
        auto str_begin = str.begin();
        const auto str_end = str.end();
        while (true){
            auto it= std::find(str_begin, str_end, ' ');

            auto word_begin = str_begin;
            auto word_end = it - 1;

            while (word_begin - str_begin < (it - str_begin)/2){
                if (*word_begin != *word_end){
                    char tmp = *word_begin;
                    *word_begin = *word_end;
                    *word_end = tmp;
                }
                word_begin++;
                word_end--;
            }

            if (it == str_end){
                break;
            } else {
                str_begin = it + 1;
            }
        }
        return str;
    }
};
void SimpleTest() {
    {
        Solution sl;
        std::string str = "Let's take LeetCode contest";
        std::string result = "s'teL ekat edoCteeL tsetnoc";
        ASSERT_EQUAL(sl.reverseWords(str), result);
    }
    {
        Solution sl;
        std::string str = "God Ding";
        std::string result = "doG gniD";
        ASSERT_EQUAL(sl.reverseWords(str), result);
    }
}
int main() {
    TestRunner tr;
    RUN_TEST(tr, SimpleTest);
    return 0;
}
