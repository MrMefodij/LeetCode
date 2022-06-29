#include <iostream>
#include "../test_runner/test_runner.h"
#include "../test_runner/TreeNode.h"

class Solution {
public:
    std::vector<std::optional<int>> preorderTraversal(TreeNode* root) {
        if (root == nullptr) return {false};
        if (root->left == nullptr && root->right == nullptr) return {root->val};

        std::vector<std::optional<int>> result;
        if (root != nullptr) {
            result.push_back(root->val);
            if (root->left != nullptr){
                std::vector<std::optional<int>> left_result = preorderTraversal(root->left);
                result.insert(result.end(), left_result.begin(), left_result.end());
            } else {
                result.insert(result.end(),{false});
            }
            if (root->right != nullptr){
                std::vector<std::optional<int>> left_result = preorderTraversal(root->right);
                result.insert(result.end(),left_result.begin(), left_result.end());
            } else {
                result.insert(result.end(),{false});
            }
        }
        return result;
    }

    std::vector<std::optional<int>> rightPreorderTraversal(TreeNode* root) {
        if (root == nullptr) return {false};
        if (root->left == nullptr && root->right == nullptr) return {root->val};

        std::vector<std::optional<int>> result;
        if (root != nullptr || (root->left == nullptr && root->right == nullptr)) {
            result.push_back(root->val);
            if (root->right != nullptr){
                std::vector<std::optional<int>> left_result = rightPreorderTraversal(root->right);
                result.insert(result.end(),left_result.begin(), left_result.end());
            } else {
                result.insert(result.end(),{false});
            }
            if (root->left != nullptr){
                std::vector<std::optional<int>> left_result = rightPreorderTraversal(root->left);
                result.insert(result.end(), left_result.begin(), left_result.end());
            } else {
                result.insert(result.end(),{false});
            }
        }
        return result;
    }

    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        if (root->left != nullptr && root->right == nullptr) return false;
        if (root->left == nullptr && root->right != nullptr) return false;
        if (root->left == nullptr && root->right == nullptr) return true;

        std::vector<std::optional<int>> left_result = preorderTraversal(root->left);
        std::vector<std::optional<int>> right_result = rightPreorderTraversal(root->right);

        return left_result == right_result;
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

        ASSERT_EQUAL(sl.isSymmetric(tree),true);
    }
    {
        Solution sl;
        TreeNode* tree_l3 = new TreeNode(3);

        TreeNode* tree_r3 = new TreeNode(3);

        TreeNode* tree_l2 = new TreeNode(2, nullptr, tree_l3);
        TreeNode* tree_r2 = new TreeNode(2,  nullptr,  tree_r3);

        TreeNode* tree = new TreeNode(1, tree_l2, tree_r2);

        ASSERT_EQUAL(sl.isSymmetric(tree),false);
    }
    {
        Solution sl;

        TreeNode* tree_l2 = new TreeNode(2);
        TreeNode* tree_r2 = new TreeNode(2);

        TreeNode* tree = new TreeNode(1, tree_l2, tree_r2);

        ASSERT_EQUAL(sl.isSymmetric(tree),true);
    }
    {
        Solution sl;
        TreeNode* tree_l2_9 = new TreeNode(9);
        TreeNode* tree_l2_8 = new TreeNode(8);

        TreeNode* tree_r2_9 = new TreeNode(9);
        TreeNode* tree_r2_8 = new TreeNode(8);

        TreeNode* tree_l2_4 = new TreeNode(4);
        TreeNode* tree_l2_5 = new TreeNode(5, tree_l2_8, tree_l2_9);

        TreeNode* tree_r2_4 = new TreeNode(4);
        TreeNode* tree_r2_5 = new TreeNode(5, tree_r2_9, tree_r2_8);

        TreeNode* tree_l2 = new TreeNode(3, tree_l2_4, tree_l2_5);
        TreeNode* tree_r2 = new TreeNode(3, tree_r2_5, tree_r2_4);

        TreeNode* tree = new TreeNode(2, tree_l2, tree_r2);

        ASSERT_EQUAL(sl.isSymmetric(tree),true);
    }
    {
        Solution sl;
        TreeNode* tree_l2 = new TreeNode(0);
        TreeNode* tree = new TreeNode(1, tree_l2, nullptr);

        ASSERT_EQUAL(sl.isSymmetric(tree),false);
    }
}

int main() {
    TestRunner tr;
    RUN_TEST(tr, SimpleTest);
    return 0;
}