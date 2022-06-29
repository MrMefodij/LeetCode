#include <iostream>
#include "ListNode.h"
#include "../test_runner/test_runner.h"

// Definition for singly-linked list.

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (head == NULL) return NULL;
        ListNode* tmp;
        if (head->val != val){
            tmp = new ListNode(head->val);
            tmp->next = removeElements(head->next, val);
        } else {
            tmp = removeElements(head->next, val);
        }
        return tmp;
    }
};
void SimpleTest(){
    {
        Solution sl;
        ListNode l1_1 = 6;
        ListNode l1_2 = {5, &l1_1};
        ListNode l1_3 = {4, &l1_2};
        ListNode l1_4 = {3, &l1_3};
        ListNode l1_5 = {6, &l1_4};
        ListNode l1_6 = {2, &l1_5};
        ListNode l1_7 = {1, &l1_6};

        ListNode l2_1 = 5;
        ListNode l2_2 = {4, &l2_1};
        ListNode l2_3 = {3, &l2_2};
        ListNode l2_4 = {2, &l2_3};
        ListNode l2_5 = {1, &l2_4};

        ListNode first = *sl.removeElements(&l1_7, 6);

        ASSERT_EQUAL( first == l2_5, true);
    }
};




int main() {
    TestRunner tr;
    RUN_TEST(tr, SimpleTest);
    return 0;
}
