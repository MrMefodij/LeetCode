#include <iostream>
#include <vector>
#include "../test_runner/test_runner.h"
#include "TreeNode.h"

class Solution {
public:
    std::vector<int> preorderTraversal(TreeNode* root) {
        if (root == nullptr) return {};
        if (root->left == nullptr && root->right == nullptr) return {root->val};

        std::vector<int> result;
        if (root != nullptr || (root->left == nullptr && root->right == nullptr)) {
            result.push_back(root->val);
            if (root->left != nullptr){
                std::vector<int> left_result = preorderTraversal(root->left);
                result.insert(result.end(), left_result.begin(), left_result.end());
            }
            if (root->right != nullptr){
                std::vector<int> left_result = preorderTraversal(root->right);
                result.insert(result.end(),left_result.begin(), left_result.end());
            }
        }
        return result;
    }
};

void SimpleTest(){
    {
        Solution sl;
        TreeNode* tree1 = new TreeNode(3);
        TreeNode* tree2 = new TreeNode(2, tree1, nullptr);
        TreeNode* tree3 = new TreeNode(1, nullptr, tree2);

        std::vector<int> result = {1, 2, 3};
        ASSERT_EQUAL(sl.preorderTraversal(tree3), result);
    }
    {
        Solution sl;
        TreeNode* tree1 = new TreeNode();
        std::vector<int> result = {};
        ASSERT_EQUAL(sl.preorderTraversal(tree1), result);
    }
    {
        Solution sl;
        TreeNode* tree1 = new TreeNode(1);
        std::vector<int> result = {1};
        ASSERT_EQUAL(sl.preorderTraversal(tree1), result);
    }
    {
        Solution sl;
        TreeNode* tree1 = new TreeNode(1);
        TreeNode* tree2 = new TreeNode(2);
        TreeNode* tree3 = new TreeNode(3, tree1, tree2);

        std::vector<int> result = {3,1,2};
        ASSERT_EQUAL(sl.preorderTraversal(tree3), result);
    }
}

int main() {
    TestRunner tr;
    RUN_TEST(tr, SimpleTest);
    return 0;
}
