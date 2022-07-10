#include <iostream>
#include "../test_runner/ListNode.h"
#include "../test_runner/test_runner.h"

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL || (head->next == NULL && n!=1) || n==0) {
            return head;
        }

        ListNode* fast = head;
        ListNode* slow = head;
        for (int i=1; i<=n; ++i) {
            if (fast->next != NULL) {
                fast = fast->next;
            } else if (i == n && fast->next == NULL){
                head = head->next;
                return head;
            } else {
                return head;
            }
        }
        while(fast->next != NULL){
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return head;
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

        ListNode* l5_r = new ListNode(5);
        ListNode* l3_r = new ListNode(3, l5_r);
        ListNode* l2_r = new ListNode(2, l3_r);
        ListNode* l1_r = new ListNode(1, l2_r);

        //ASSERT_EQUAL(sl.removeNthFromEnd(l1,2) == l1_r, true);
    }
    {
        Solution sl;

        ListNode* l1 = new ListNode(1);

        ASSERT_EQUAL(sl.removeNthFromEnd(l1,1), nullptr);
    }
    {
        Solution sl;

        ListNode* l2 = new ListNode(2);
        ListNode* l1 = new ListNode(1, l2);

        ListNode* l1_r = new ListNode(1);

        ASSERT_EQUAL(sl.removeNthFromEnd(l1,2), l1_r);
    }
};

int main() {
    TestRunner tr;
    RUN_TEST(tr, SimpleTest);
    return 0;
}
