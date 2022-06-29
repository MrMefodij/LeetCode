#include <iostream>
#include "../test_runner/test_runner.h"
#include "../test_runner/TreeNode.h"

class Solution {
public:
    std::vector<std::vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) return {};
        if (root->left == nullptr && root->right == nullptr) return {{root->val}};
    }
};

void SimpleTest(){
    {
        Solution sl;
        TreeNode* tree_l3 = new TreeNode(3);
        TreeNode* tree_l4 = new TreeNode(4);

        TreeNode* tree_r3 = new TreeNode(3);
        TreeNode* tree_r4 = new TreeNode(4);

        TreeNode* tree_l2 = new TreeNode(2, tree_l3, tree_l4);
        TreeNode* tree_r2 = new TreeNode(2, tree_r4, tree_r3);

        TreeNode* tree = new TreeNode(1, tree_l2, tree_r2);

        std::vector<std::vector<int>> result ={{1},{2,2},{3,4,4,3}};

        ASSERT_EQUAL(sl.levelOrder(tree), result);
    }
    {
        Solution sl;
        TreeNode* tree_l3 = new TreeNode(3);

        TreeNode* tree_r3 = new TreeNode(3);

        TreeNode* tree_l2 = new TreeNode(2, nullptr, tree_l3);
        TreeNode* tree_r2 = new TreeNode(2,  nullptr,  tree_r3);

        TreeNode* tree = new TreeNode(1, tree_l2, tree_r2);

        std::vector<std::vector<int>> result ={{1},{2,2},{3,3}};

        ASSERT_EQUAL(sl.levelOrder(tree),result);
    }
    {
        Solution sl;
        TreeNode* tree_r3 = new TreeNode(15);
        TreeNode* tree_r4 = new TreeNode(7);

        TreeNode* tree_l2 = new TreeNode(9);
        TreeNode* tree_r2 = new TreeNode(20, tree_r3, tree_r4);

        TreeNode* tree = new TreeNode(1, tree_l2, tree_r2);

        std::vector<std::vector<int>> result ={{3}, {9,20},{15,7}};

        ASSERT_EQUAL(sl.levelOrder(tree), result);
    }
}

int main() {
    TestRunner tr;
    RUN_TEST(tr, SimpleTest);
    return 0;
}
