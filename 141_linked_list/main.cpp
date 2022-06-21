#include <iostream>
#include <vector>
#include "../test_runner/test_runner.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode* next_) : val(x), next(next_) {}
};


class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
            if (slow == fast){
                return true;
            }
        }
        return false;
    }
private:

};

void SimpleTest(){
    {
        Solution sl;

        ListNode ln2 (2);
        ListNode ln3 (3, &ln2);
        ListNode ln_4 (-4, &ln2);
        ListNode ln0 (0, &ln_4);
        ln2.next = &ln0;

        ASSERT_EQUAL(sl.hasCycle(&ln3), true);
    }
    {
        Solution sl;

        ListNode ln1 (1);
        ListNode ln2 (2, &ln1);
        ln1.next = &ln2;

        ASSERT_EQUAL(sl.hasCycle(&ln1), true);
    }
    {
        Solution sl;

        ListNode ln1 (1);

        ASSERT_EQUAL(sl.hasCycle(&ln1), false);
    }

    {
        Solution sl;

        ListNode ln1 ();

        ASSERT_EQUAL(sl.hasCycle(NULL), false);
    }

}
int main() {
    TestRunner tr;
    RUN_TEST(tr,SimpleTest);
    return 0;
}