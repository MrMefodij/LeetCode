#include <iostream>
#include "../test_runner/test_runner.h"
#include "../test_runner/TreeNode.h"

class Solution {
public:
    std::vector<std::pair<int, TreeNode*>> treeLevel (const std::vector<std::pair<int, TreeNode*>> & levelTree, int targetSum){
        std::vector<std::pair<int, TreeNode*>> result;
        for (const auto a : levelTree) {
            if (a.second->left != nullptr){
                result.push_back(std::make_pair(a.first + a.second->left->val, a.second->left));
            }
            if (a.second->right != nullptr){
                result.push_back(std::make_pair(a.first + a.second->right->val, a.second->right));
            }
        }
        if (result.size()>0){
            return result;
        }
        return {};
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return false;
        if (root->left == nullptr && root->right == nullptr ) return root->val == targetSum;


        std::vector<std::pair<int, TreeNode*>> treeLevel_ = {std::make_pair(root->val,root)};
        while (treeLevel_.size()>0){
            for (const auto& a : treeLevel_) {
                if (a.first == targetSum && a.second->left == nullptr && a.second->right == nullptr){
                    return true;
                }
            }
            treeLevel_ = treeLevel(treeLevel_,targetSum);
        }
        return false;
    }
};

void SimpleTest(){
    {
        Solution sl;

        TreeNode* tree_l7 = new TreeNode(7);
        TreeNode* tree_l2 = new TreeNode(2);
        TreeNode* tree_l11 = new TreeNode(11, tree_l7, tree_l2);
        TreeNode* tree_l4 = new TreeNode(4, tree_l11, nullptr);

        TreeNode* tree_r1 = new TreeNode(1);
        TreeNode* tree_r4 = new TreeNode(4, nullptr, tree_r1);
        TreeNode* tree_r13 = new TreeNode(13);
        TreeNode* tree_r8 = new TreeNode(8, tree_r13, tree_r4);

        TreeNode* tree = new TreeNode(5, tree_l4, tree_r8);

        ASSERT_EQUAL(sl.hasPathSum(tree,22), true);
    }
    {
        Solution sl;

        TreeNode* tree_l2 = new TreeNode(2);
        TreeNode* tree_r3 = new TreeNode(3);

        TreeNode* tree = new TreeNode(1, tree_l2, tree_r3);

        ASSERT_EQUAL(sl.hasPathSum(tree,5), false);
    }
    {
        Solution sl;
        TreeNode* tree_l_1 = new TreeNode(-1);

        TreeNode* tree_r_2 = new TreeNode(-2);

        TreeNode* tree_l1 = new TreeNode(1, tree_l_1, nullptr);
        TreeNode* tree_l3 = new TreeNode(3);

        TreeNode* tree_l_2 = new TreeNode(-2, tree_l1, tree_l3);
        TreeNode* tree_r_3 = new TreeNode(-3, tree_r_2, nullptr);

        TreeNode* tree = new TreeNode(1, tree_l_2, tree_r_3);

        ASSERT_EQUAL(sl.hasPathSum(tree, -1), true);
    }
}

int main() {
    TestRunner tr;
    RUN_TEST(tr, SimpleTest);
    return 0;
}
