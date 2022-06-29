#include <iostream>
#include "../test_runner/ListNode.h"
#include "../test_runner/test_runner.h"

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode *result;
        ListNode *first;
        bool first_bool = false;
        ListNode *second;
        while (head !=NULL && head->next !=NULL){
            if (!first_bool) {
                first = new ListNode(head->val, NULL);
                first_bool = true;
                result = first;
            } else {
                first = second;
            }

            if (head->next !=NULL ) {
                do {
                    head = head->next;
                } while (head !=NULL && first->val == head->val);
            } else{
                break;
            }
            if (head !=NULL) {
                second = new ListNode(head->val, NULL);
                first->next = second;
            }
        }
        return result;
    }
};

void SimpleTest(){
    {
        Solution sl;
        ListNode l1_1 = 1;
        ListNode l1_2 = {1, &l1_1};
        ListNode l1_3 = {2, &l1_2};

        ListNode l2_1 = 1;
        ListNode l2_2 = {2, &l2_1};

        ListNode first = *sl.deleteDuplicates(&l1_3);

        ASSERT_EQUAL( first == l2_2, true);
    }
    {
        Solution sl;
        ListNode l1_1 = 1;
        ListNode l1_2 = {1, &l1_1};
        ListNode l1_3 = {2, &l1_2};
        ListNode l1_4 = {3, &l1_3};
        ListNode l1_5 = {3, &l1_4};

        ListNode l2_1 = 1;
        ListNode l2_2 = {2, &l2_1};
        ListNode l2_3 = {3, &l2_2};

        ListNode first = *sl.deleteDuplicates(&l1_5);

        ASSERT_EQUAL( first == l2_3, true);
    }

    {
        Solution sl;
        ListNode l1_1 = 1;
        ListNode l1_2 = {1, &l1_1};
        ListNode l1_3 = {1, &l1_2};
        ListNode l1_4 = {1, &l1_3};
        ListNode l1_5 = {1, &l1_4};

        ListNode l2_1 = 1;

        ListNode first = *sl.deleteDuplicates(&l1_5);

        ASSERT_EQUAL( first == l2_1, true);

    }
};




int main() {
    TestRunner tr;
    RUN_TEST(tr, SimpleTest);
    return 0;
}