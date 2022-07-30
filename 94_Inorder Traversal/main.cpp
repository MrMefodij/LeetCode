#include <iostream>
#include "../test_runner/test_runner.h"
#include "../test_runner/TreeNode.h"

class Solution {
public:
    std::vector<int> inorderTraversal(TreeNode* root) {
        if (root == nullptr) return {};
        //if (root->val == NULL) return {};
        if (root->left == nullptr && root->right == nullptr) return {root->val};

        std::vector<int> result;
        if (root->left != nullptr){
            std::vector<int> left_result = inorderTraversal(root->left);
            result.insert(result.end(), left_result.begin(), left_result.end());
        }
        result.push_back(root->val);
        if (root->right != nullptr){
            std::vector<int> left_result = inorderTraversal(root->right);
            result.insert(result.end(),left_result.begin(), left_result.end());
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

        std::vector<int> result = {1, 3, 2};
        ASSERT_EQUAL(sl.inorderTraversal(tree3), result);
    }
    {
        Solution sl;
        TreeNode* tree1 = new TreeNode();
        std::vector<int> result = {};
        //ASSERT_EQUAL(sl.inorderTraversal(tree1), result);
    }
    {
        Solution sl;
        TreeNode* tree1 = new TreeNode(1);
        std::vector<int> result = {1};
        ASSERT_EQUAL(sl.inorderTraversal(tree1), result);
    }
    {
        Solution sl;
        TreeNode* tree1 = new TreeNode(1);
        TreeNode* tree2 = new TreeNode(2);
        TreeNode* tree3 = new TreeNode(3, tree1, tree2);

        std::vector<int> result = {1,3,2};
        ASSERT_EQUAL(sl.inorderTraversal(tree3), result);
    }
    {
        //[1,null,0,3]
        Solution sl;
        TreeNode* tree3 = new TreeNode(3);
        TreeNode* tree2 = new TreeNode(0, tree3, nullptr);
        TreeNode* tree1 = new TreeNode(1, nullptr, tree2);

        std::vector<int> result = {1,3,0};
        ASSERT_EQUAL(sl.inorderTraversal(tree1), result);

    }
}

int main() {
    TestRunner tr;
    RUN_TEST(tr, SimpleTest);
    return 0;
}
