#include <iostream>
#include "../test_runner/test_runner.h"

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL && list2==NULL)  return NULL;
        if(list1==NULL && list2!=NULL)  return list2;
        if(list1!=NULL && list2==NULL)  return list1;

        ListNode* result = new ListNode;
        ListNode* last = result;
        while (list1!=NULL && list2!=NULL){
            if (list1->val <= list2->val){
                last->val = list1->val;
                list1 = list1->next;
            } else {
                last->val = list2->val;
                list2 = list2->next;
            }
            ListNode * tmp = new ListNode;
            last->next = tmp;
            last = tmp;
        }
        if (list1!=NULL && list2==NULL){
            last->val = list1->val;
            last->next = list1->next;
        } else if (list1==NULL && list2!=NULL){
            last->val = list2->val;
            last->next = list2->next;
        } 
        return result;
    }
};
void SimpleTest(){
    {
        Solution sl;
        ListNode l1_1 = 4;
        ListNode l1_2 = {2, &l1_1};
        ListNode l1_3 = {1, &l1_2};

        ListNode l2_1 = 4;
        ListNode l2_2 = {3, &l2_1};
        ListNode l2_3 = {1, &l2_2};

        ListNode *first = &l1_3;
        ListNode *second = &l2_3;
        ListNode *result = sl.mergeTwoLists(first, second);
        std::cout << std::endl;
    }
    {
        Solution sl;
        ListNode l1_1 ;
        ListNode l2_1 ;
    }
};




int main() {
    TestRunner tr;
    RUN_TEST(tr, SimpleTest);
    return 0;
}
