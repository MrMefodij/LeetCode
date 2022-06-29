//
// Created by amefodev on 21.06.2022.
//

#ifndef INC_203_REMOVEELEMENTS_LISTNODE_H
#define INC_203_REMOVEELEMENTS_LISTNODE_H
#pragma once
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

std::ostream& operator << (std::ostream& os,const ListNode& s)
{
    ListNode* tmp = const_cast<ListNode *>(&s);
    os << "{";
    bool first = true;
    while (tmp != NULL){
        if (!first)
        {
            os << ", ";
        }
        first = false;
        os << tmp->val;
        tmp = tmp->next;
    }
    return os << "}";
}
bool operator == (const ListNode& lhs, const ListNode& rhs)
{
    ListNode* tmp_lhs = const_cast<ListNode *>(&lhs);
    ListNode* tmp_rhs = const_cast<ListNode *>(&rhs);

    while (tmp_lhs != NULL && tmp_rhs != NULL){
        if (tmp_lhs->val != tmp_rhs->val){
            return false;
        } else {
            tmp_lhs = tmp_lhs->next;
            tmp_rhs = tmp_rhs->next;
        }
    }
    if (tmp_lhs != NULL && tmp_rhs == NULL){
        return false;
    } else if (tmp_lhs == NULL && tmp_rhs != NULL){
        return false;
    }
    return true;
}

#endif //INC_203_REMOVEELEMENTS_LISTNODE_H
