#include <iostream>
#include "../test_runner/test_runner.h"
#include "../test_runner/TreeNode.h"

class Solution {
public:
    std::vector<TreeNode*> treeLevel (const std::vector<TreeNode*>& levelTree){
        std::vector<TreeNode*> result;
        for (const auto a : levelTree) {
            if (a->left != nullptr){
                result.push_back(a->left);
            }
            if (a->right != nullptr){
                result.push_back(a->right);
            }
        }
        if (result.size()>0){
            return result;
        }
        return {};
    }

    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        if (root->left == nullptr && root->right == nullptr) return 1;

        std::vector<TreeNode*> treeLevel_ = {root};
        size_t level = 0;
        while (treeLevel_.size()>0){
            level++;
            treeLevel_ = treeLevel(treeLevel_);
        }
        return level;
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

        ASSERT_EQUAL(sl.maxDepth(tree),3);
    }
    {
        Solution sl;

        TreeNode* tree_r3 = new TreeNode(15);
        TreeNode* tree_r4 = new TreeNode(7);

        TreeNode* tree_l2 = new TreeNode(9);
        TreeNode* tree_r2 = new TreeNode(20, tree_r4, tree_r3);

        TreeNode* tree = new TreeNode(3, tree_l2, tree_r2);

        ASSERT_EQUAL(sl.maxDepth(tree),3);
    }
    {
        Solution sl;

        TreeNode* tree_l2 = new TreeNode(2);

        TreeNode* tree = new TreeNode(1, nullptr, tree_l2);

        ASSERT_EQUAL(sl.maxDepth(tree),2);
    }
}

int main() {
    TestRunner tr;
    RUN_TEST(tr, SimpleTest);
    return 0;
}

