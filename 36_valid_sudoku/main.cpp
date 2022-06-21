#include <iostream>
#include <vector>
#include "test_runner.h"

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int profit = 0;
        int minVal = prices[0];
        for(int i = 1; i < prices.size(); i++){
            if(prices[i]>minVal)
                profit=std::max(profit, prices[i]-minVal);
            minVal=std::min(minVal, prices[i]);
        }
        return profit;
    }
};

void SimpleTest(){
    {
        Solution sl;
        std::vector<int> v1 = {7,0,2,5,3,6,4};

        ASSERT_EQUAL(sl.maxProfit(v1), 6);
    }

    {
        Solution sl;
        std::vector<int> v1 = {7,6,4,3,1};

        ASSERT_EQUAL(sl.maxProfit(v1), 0);
    }
}
int main() {
    TestRunner tr;
    RUN_TEST(tr,SimpleTest);
    return 0;
}