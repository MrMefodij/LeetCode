#include <iostream>
#include <stack>
#include "../test_runner/test_runner.h"

class Solution {
public:
    bool isValid(const std::string& s) {
        for (const auto a : s) {
            if ( a == '{' || a == '(' || a == '[' ){
                stack_chars_.push(a);
            } else if (stack_chars_.size() == 0) {
                return false;
            } else if (a == '}') {
                if (stack_chars_.top() == '{'){
                    stack_chars_.pop();
                } else {
                    return false;
                }
            } else if (a == ')') {
                if (stack_chars_.top() == '('){
                    stack_chars_.pop();
                } else {
                    return false;
                }
            } else if (a == ']') {
                if (stack_chars_.top() == '['){
                    stack_chars_.pop();
                } else {
                    return false;
                }
            }
        }
        return stack_chars_.size() == 0;
    }
private:
    std::stack<char> stack_chars_; // (
};

void SimpleTest(){
    {
        Solution sl;
        std::string s = "()";
        ASSERT_EQUAL(sl.isValid(s), true);
    }
    {
        Solution sl;
        std::string s = "()[]{}";
        ASSERT_EQUAL(sl.isValid(s), true);
    }
    {
        Solution sl;
        std::string s = "(]";
        ASSERT_EQUAL(sl.isValid(s), false);
    }
    {
        Solution sl;
        std::string s = "([)]";
        ASSERT_EQUAL(sl.isValid(s), false);
    }
    {
        Solution sl;
        std::string s = "";
        ASSERT_EQUAL(sl.isValid(s), true);
    }
    {
        Solution sl;
        std::string s = "]";
        ASSERT_EQUAL(sl.isValid(s), false);
    }
};

int main() {
    TestRunner tr;
    RUN_TEST(tr, SimpleTest);
    return 0;
}