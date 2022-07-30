#include <iostream>
#include <vector>
#include "../test_runner/test_runner.h"
#include "../test_runner/TreeNode.h"

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr) return root2;
        if (root2 == nullptr) return root1;
        //TreeNode* result;
        root1->val = root1->val + (root2 == nullptr ? 0 : root2->val);

        if (root1->left != nullptr || root2->left != nullptr){
            root1->left = mergeTrees(root1->left, root2->left);
        }

        if (root1->right != nullptr || root2->right != nullptr){
            root1->right = mergeTrees(root1->right, root2->right);
        }
        return root1;
    }
};

void SimpleTest() {
    {
        Solution sl;

        TreeNode *tree1_l5 = new TreeNode(5);
        TreeNode *tree1_l3 = new TreeNode(3, tree1_l5, nullptr);
        TreeNode *tree1_r2 = new TreeNode(2);

        TreeNode *tree1 = new TreeNode(1, tree1_l3, tree1_r2);

        TreeNode *tree2_l4 = new TreeNode(4);
        TreeNode *tree2_r7 = new TreeNode(7);
        TreeNode *tree2_r3 = new TreeNode(3, nullptr, tree2_r7);
        TreeNode *tree2_l1 = new TreeNode(1, nullptr, tree2_l4);

        TreeNode *tree2 = new TreeNode(2, tree2_l1, tree2_r3);

        sl.mergeTrees(tree1, tree2);
        std::cout << std::endl;
    }
    {
        Solution sl;
        TreeNode *tree1 = new TreeNode(1);
        TreeNode *tree2_r2 = new TreeNode(2);
        TreeNode *tree2 = new TreeNode(2, tree2_r2, nullptr);

        sl.mergeTrees(tree1, tree2);
        std::cout << std::endl;
    }
}
int main() {
    TestRunner tr;
    RUN_TEST(tr, SimpleTest);
    return 0;
}
