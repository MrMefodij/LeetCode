#include <iostream>
#include "test_runner.h"

// Definition for singly-linked list.
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = new ListNode;
        ListNode* last = result;
        bool plusOne = 0;
        while (l1!=NULL || l2!=NULL){
            last->val = (l1 != nullptr ? l1->val : 0) + (l2 != nullptr ? l2->val : 0) + plusOne;
            if (last->val >9){
                last->val -= 10;
                plusOne =1;
            } else {
                plusOne = 0;
            }


            if ((l1!=NULL && l1->next != nullptr) || (l2!=NULL && l2->next != nullptr)) {
                ListNode *next = new ListNode;
                last->next = next;
                last = next;
            }

            if (l1!=NULL) l1 = l1->next;
            if (l2!=NULL) l2 = l2->next;
        }
        if (plusOne){
            ListNode* next = new ListNode;
            last->next = next;
            last = next;
            last->val = 1;
        }
        return result;
    }
};
void SimpleTest(){
    Solution sl;
    ListNode l1_1 = 3;
    ListNode l1_2 = {4,&l1_1};
    ListNode l1_3 = {2,&l1_2};

    ListNode l2_1 = 4;
    ListNode l2_2 = {6,&l2_1};
    ListNode l2_3 = {5,&l2_2};

    ListNode* first = &l1_3;
    ListNode* second = &l2_3;
    ListNode* result = sl.addTwoNumbers(first,second);
    std::cout<<std::endl;
};

void SimpleTest2(){
    Solution sl;
    ListNode l1_1 = 9;
    ListNode l1_2 = {9,&l1_1};
    ListNode l1_3 = {9,&l1_2};
    ListNode l1_4 = {9,&l1_3};
    ListNode l1_5 = {9,&l1_4};
    ListNode l1_6 = {9,&l1_5};
    ListNode l1_7 = {9,&l1_6};

    ListNode l2_1 = 9;
    ListNode l2_2 = {9,&l2_1};
    ListNode l2_3 = {9,&l2_2};
    ListNode l2_4 = {9,&l2_3};

    ListNode* first = &l1_7;
    ListNode* second = &l2_4;
    ListNode* result = sl.addTwoNumbers(first,second);
    std::cout <<std::endl;
}

void SimpleTest3(){
    Solution sl;
    ListNode l1_1 = 9;
    ListNode l1_2 = {4,&l1_1};
    ListNode l1_3 = {2,&l1_2};

    ListNode l2_1 = 9;
    ListNode l2_2 = {4,&l2_1};
    ListNode l2_3 = {6,&l2_2};
    ListNode l2_4 = {5,&l2_3};

    ListNode* first = &l1_3;
    ListNode* second = &l2_4;
    ListNode* result = sl.addTwoNumbers(first,second);
    std::cout<<std::endl;
};


int main() {
    TestRunner tr;
    RUN_TEST(tr, SimpleTest);
    RUN_TEST(tr, SimpleTest2);
    RUN_TEST(tr, SimpleTest3);
    return 0;
}
