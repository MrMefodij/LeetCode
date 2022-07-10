#include <iostream>
#include "../test_runner/test_runner.h"
#include "../test_runner/TreeNode.h"

class Solution {
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        while (root != NULL){
            if (p->val < root->val && q->val < root->val){
                root = root->left;
            } else if (p->val > root->val && q->val > root->val){
                root = root->right;
            } else {
                return root;
            }
        }
        return NULL;
    }
};

void SimpleTest(){
    {
        Solution sl;

        TreeNode* tree_l3 = new TreeNode(3);
        TreeNode* tree_l5 = new TreeNode(5);
        TreeNode* tree_l4 = new TreeNode(4, tree_l3, tree_l5);
        TreeNode* tree_l0 = new TreeNode(0);
        TreeNode* tree_l2 = new TreeNode(2, tree_l0, tree_l4);

        TreeNode* tree_r7 = new TreeNode(7);
        TreeNode* tree_r9 = new TreeNode(9);
        TreeNode* tree_r8 = new TreeNode(8, tree_r7, tree_r9);

        TreeNode* tree = new TreeNode(6, tree_l2, tree_r8);

        ASSERT_EQUAL(sl.lowestCommonAncestor(tree, tree_l2, tree_r8), tree);
    }
    {
        Solution sl;

        TreeNode* tree_l3 = new TreeNode(3);
        TreeNode* tree_l5 = new TreeNode(5);
        TreeNode* tree_l4 = new TreeNode(4, tree_l3, tree_l5);
        TreeNode* tree_l0 = new TreeNode(0);
        TreeNode* tree_l2 = new TreeNode(2, tree_l0, tree_l4);

        TreeNode* tree_r7 = new TreeNode(7);
        TreeNode* tree_r9 = new TreeNode(9);
        TreeNode* tree_r8 = new TreeNode(8, tree_r7, tree_r9);

        TreeNode* tree = new TreeNode(6, tree_l2, tree_r8);

        ASSERT_EQUAL(sl.lowestCommonAncestor(tree, tree_l2, tree_l4), tree_l2);
    }
}

int main() {
    TestRunner tr;
    RUN_TEST(tr, SimpleTest);
    return 0;
}
