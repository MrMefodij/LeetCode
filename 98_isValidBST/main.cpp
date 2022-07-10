#include <iostream>
#include <vector>
#include "../test_runner/test_runner.h"
#include "../test_runner/TreeNode.h"

class Solution {
public:
    void dfs(TreeNode* root,std::vector<int>&inorder){
        if(root != NULL) {
            dfs(root->left, inorder);
            inorder.push_back(root->val);
            dfs(root->right, inorder);
        }
    }

    bool isSorted(const std::vector<int>& v){
        for(int i=0;i<v.size()-1;i++){
            if(v[i]>=v[i+1])
                return false;
        }
        return true;
    }

    bool isValidBST(TreeNode* root) {
        if (root == nullptr) return true;
        if (root->left == nullptr && root->right == nullptr) return true;

        std::vector<int>inorder;
        dfs(root,inorder);
        return isSorted(inorder);
    }
};

void SimpleTest() {
    {
        Solution sl;

        TreeNode* tree_l1 = new TreeNode(1);
        TreeNode* tree_r3 = new TreeNode(3);
        TreeNode* tree = new TreeNode(2, tree_l1, tree_r3);

        ASSERT_EQUAL(sl.isValidBST(tree), true);
    }
    {
        Solution sl;

        TreeNode* tree_r3 = new TreeNode(3);
        TreeNode* tree_r6 = new TreeNode(6);

        TreeNode* tree_l1 = new TreeNode(1);
        TreeNode* tree_r4 = new TreeNode(4, tree_r3, tree_r6);
        TreeNode* tree = new TreeNode(5, tree_l1, tree_r4);

        ASSERT_EQUAL(sl.isValidBST(tree), false);
    }
    {
        Solution sl;

        TreeNode* tree_r3 = new TreeNode(3);
        TreeNode* tree_r7 = new TreeNode(7);

        TreeNode* tree_l4 = new TreeNode(4);
        TreeNode* tree_r6 = new TreeNode(6, tree_r3, tree_r7);
        TreeNode* tree = new TreeNode(5, tree_l4, tree_r6);

        ASSERT_EQUAL(sl.isValidBST(tree), false);
    }
    {
        Solution sl;

        TreeNode* tree_l35 = new TreeNode(35);
        TreeNode* tree_l41 = new TreeNode(41);

        TreeNode* tree_r45 = new TreeNode(45);
        TreeNode* tree_r70 = new TreeNode(70);

        TreeNode* tree_l40 = new TreeNode(40, tree_l35, tree_l41);
        TreeNode* tree_r60 = new TreeNode(60, tree_r45, tree_r70);
        TreeNode* tree = new TreeNode(50, tree_l40, tree_r60);

        ASSERT_EQUAL(sl.isValidBST(tree), false);
    }
    {
        Solution sl;

        TreeNode* tree_l35 = new TreeNode(35);
        TreeNode* tree_l41 = new TreeNode(41);

        TreeNode* tree_r45 = new TreeNode(45);
        TreeNode* tree_r70 = new TreeNode(70);

        TreeNode* tree_l40 = new TreeNode(40, tree_l35, tree_l41);
        TreeNode* tree_r60 = new TreeNode(60, tree_r45, tree_r70);
        TreeNode* tree = new TreeNode(50, tree_l40, tree_r60);

        ASSERT_EQUAL(sl.isValidBST(tree), false);
    }
    {
        Solution sl;
        TreeNode* tree_l27 = new TreeNode(27);
        TreeNode* tree_l19 = new TreeNode(19, nullptr, tree_l27);
        TreeNode* tree_l26 = new TreeNode(26, tree_l19, nullptr);

        TreeNode* tree_r56 = new TreeNode(56);
        TreeNode* tree_r47 = new TreeNode(47, nullptr,tree_r56);

        TreeNode* tree = new TreeNode(32, tree_l26, tree_r47);

        ASSERT_EQUAL(sl.isValidBST(tree), false);
    }

    {
        Solution sl;
        TreeNode* tree_l2 = new TreeNode(2);
        TreeNode* tree_r2 = new TreeNode(2);

        TreeNode* tree = new TreeNode(2, tree_l2, tree_r2);

        ASSERT_EQUAL(sl.isValidBST(tree), false);
    }
}

int main() {
    TestRunner tr;
    RUN_TEST(tr, SimpleTest);
    return 0;
}