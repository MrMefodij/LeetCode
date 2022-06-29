#include <iostream>
#include "../test_runner/ListNode.h"
#include "../test_runner/test_runner.h"

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode *first;
        bool first_bool = false;
        ListNode *second;
        while (head !=NULL && head->next !=NULL){
            if (!first_bool) {
                first = new ListNode(head->val, NULL);
                first_bool = true;
            } else {
                first = second;
            }
            head = head->next;
            second = new ListNode(head->val, first);
        }
        return second;
    }
};

void SimpleTest(){
    {
        Solution sl;
        ListNode l1_1 = 7;
        ListNode l1_2 = {6, &l1_1};
        ListNode l1_3 = {5, &l1_2};
        ListNode l1_4 = {4, &l1_3};
        ListNode l1_5 = {3, &l1_4};
        ListNode l1_6 = {2, &l1_5};
        ListNode l1_7 = {1, &l1_6};

        ListNode l2_1 = 1;
        ListNode l2_2 = {2, &l2_1};
        ListNode l2_3 = {3, &l2_2};
        ListNode l2_4 = {4, &l2_3};
        ListNode l2_5 = {5, &l2_4};
        ListNode l2_6 = {6, &l2_5};
        ListNode l2_7 = {7, &l2_6};

        ListNode first = *sl.reverseList(&l1_7);

        ASSERT_EQUAL( first == l2_7, true);
    }
};




int main() {
    TestRunner tr;
    RUN_TEST(tr, SimpleTest);
    return 0;
}