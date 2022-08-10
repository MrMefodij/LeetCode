#include <iostream>
#include_next "../test_runner/test_runner.h"

class Solution {
public:
    size_t calculateSize(size_t i){
        size_t result = 0;
        result = (1<<i);
//        std::cout<< result << std::endl;
        return result;
    }
    void casePermute( std::vector<std::string>& result, const std::vector<int>& position, std::string word, int i, int j){
        if (i > (int)position.size() - 1 || j<=0){
            return;
        } else {
            while (j>=0) {
                i++;
                j--;
                if (i>=0 && j>=0) {
                    std::string tmp = word;
                    tmp[position.at(j)] = char(tmp[position.at(j)] - 32);
                    result.push_back(tmp);
                    casePermute(result, position, tmp, i, j);
                }
            }
        }
    }
    std::vector<std::string> letterCasePermutation(const std::string & s) {
        std::vector<std::string> result = {s};
        std::vector<int> position;
        for (int i = 0 ; i < s.size(); i++){
            int tmp = static_cast<int>(s.at(i));
            if((tmp > 64 && tmp < 91) ){
                position.push_back(i);
                result.at(0)[i] = char(result.at(0)[i] + 32) ;
            } else if ((tmp > 96 && tmp < 123)){
                position.push_back(i);
            }
        }
        size_t size = calculateSize(position.size());
        result.reserve(size);
        if ( size > 1) {
            casePermute(result, position, result.at(0), -1, position.size());
        }
        return result;
    }
};

void SimpleTest() {
    {
        Solution sl;
        std::vector<std::string> result = {"a1b2", "a1B2", "A1B2", "A1b2"};
        ASSERT_EQUAL(sl.letterCasePermutation("a1b2"), result);
    }
    {
        Solution sl;
        std::vector<std::string> result = {"3z4","3Z4"};
        ASSERT_EQUAL(sl.letterCasePermutation("3z4"), result);
    }
    {
        Solution sl;
        std::vector<std::string> result = {"a1b2c", "a1b2C", "a1B2C", "A1B2C", "A1b2C", "a1B2c", "A1B2c", "A1b2c"};
        ASSERT_EQUAL(sl.letterCasePermutation("a1b2C"), result);
    }
    {
        Solution sl;
        std::vector<std::string> result = {"dntj","dntJ","dnTj","dnTJ","dNtj","dNtJ","dNTj","dNTJ",
                                           "Dntj","DntJ","DnTj","DnTJ","DNtj","DNtJ","DNTj","DNTJ"};
        ASSERT_EQUAL(sl.letterCasePermutation("dnTJ"), result);
    }
}
int main() {
    TestRunner tr;
    RUN_TEST(tr, SimpleTest);
    return 0;
}
