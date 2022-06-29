//
// Created by amefodev on 25.06.2022.
//

#ifndef INC_144_BINARY_TREE_TREENODE_H
#define INC_144_BINARY_TREE_TREENODE_H
#pragma once
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#endif //INC_144_BINARY_TREE_TREENODE_H
