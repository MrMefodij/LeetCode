#include <iostream>
#include "../test_runner/test_runner.h"

class Solution {
public:
    void backtracking(std::vector<std::vector<int>>&res,std::vector<int>temp,int max,int i){
        if(i<0 or temp[i]>=max)
            return;
        else{
            while(temp[i]<(max-1)){
                temp[i]+=1;
                res.push_back(temp);
                backtracking(res,temp,temp[i],i-1);
            }
        }
    }
    std::vector<std::vector<int>> combine(int n, int k) {
        std::vector<std::vector<int>>res;
        std::vector<int>temp;
        for(int i=1;i<=k;i++)
            temp.push_back(i);
        res.push_back(temp);
        backtracking(res,temp,n+1,k-1);
        return res;

    }
};

void SimpleTest() {
    {
        Solution sl;
        std::vector<std::vector<int>> result = {{1, 2}, {1, 3}, {2, 3}, {1, 4}, {2, 4}, {3, 4}};
        ASSERT_EQUAL(sl.combine(4,2), result);
    }
    {
        Solution sl;
        std::vector<std::vector<int>> result = {{1}};
        ASSERT_EQUAL(sl.combine(1,1), result);
    }
    {
        Solution sl;
        std::vector<std::vector<int>> result = {{1, 2, 3}, {1, 2, 4}, {1, 3, 4}, {2, 3, 4}, {1, 2, 5}, {1, 3, 5}, {2, 3, 5}, {1, 4, 5}, {2, 4, 5}, {3, 4, 5}};
        ASSERT_EQUAL(sl.combine(5,3), result);
    }
}
int main() {
    TestRunner tr;
    RUN_TEST(tr, SimpleTest);
    return 0;
}
