#include <iostream>
#include "../test_runner/test_runner.h"

class Solution {
public:
    void SetBad(int n){
        firstBad_ = n;
    }
    bool isBadVersion(int n){
        return firstBad_ <= n;
    }
    int firstBadVersion(int n) {
        knownBad_ = n;
        while (!isBadVersion(n) || isBadVersion(n - 1)){
            if (isBadVersion(n)){
                if (knownBad_ > n){
                    knownBad_ = n;
                }
                n = n / 2;
            } else {
                if (knownGood_< n ){
                    knownGood_ = n;
                }
                n = knownGood_ + (knownBad_ - knownGood_)/2;
            }
        }
        return n;
    }
private:
    int knownBad_ = 0;
    int knownGood_ = 0;
    int firstBad_ = 0;
};

void SimpleTest(){
    {
        Solution sl;
        sl.SetBad(4);
        ASSERT_EQUAL(sl.firstBadVersion(5), 4);
    }
    {
        Solution sl;
        sl.SetBad(2);
        ASSERT_EQUAL(sl.firstBadVersion(3), 2);
    }
    {
        Solution sl;
        sl.SetBad(3);
        ASSERT_EQUAL(sl.firstBadVersion(4), 3);
    }
    {
        Solution sl;
        sl.SetBad(1702766719);
        ASSERT_EQUAL(sl.firstBadVersion(2126753390), 1702766719);
    }
}
int main() {
    TestRunner tr;
    RUN_TEST(tr, SimpleTest);
    return 0;
}
