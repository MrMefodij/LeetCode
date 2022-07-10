#include <iostream>
#include "../test_runner/ListNode.h"
#include "../test_runner/test_runner.h"

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast !=NULL && fast->next !=NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
};

void SimpleTest(){
    {
        Solution sl;
        ListNode* l5 = new ListNode(5);
        ListNode* l4 = new ListNode(4, l5);
        ListNode* l3 = new ListNode(3, l4);
        ListNode* l2 = new ListNode(2, l3);
        ListNode* l1 = new ListNode(1, l2);

        ASSERT_EQUAL(sl.middleNode(l1), l3);
    }
    {
        Solution sl;
        ListNode* l6 = new ListNode(6);
        ListNode* l5 = new ListNode(5, l6);
        ListNode* l4 = new ListNode(4, l5);
        ListNode* l3 = new ListNode(3, l4);
        ListNode* l2 = new ListNode(2, l3);
        ListNode* l1 = new ListNode(1, l2);

        ASSERT_EQUAL(sl.middleNode(l1), l4);
    }
};

int main() {
    TestRunner tr;
    RUN_TEST(tr, SimpleTest);
    return 0;
}