#include <iostream>
#include "../test_runner/test_runner.h"
#include "../test_runner/TreeNode.h"

class Solution {
public:
    std::vector<int> postorderTraversal(TreeNode* root) {
        if (root == nullptr) return {};
        if (root->left == nullptr && root->right == nullptr) return {root->val};

        std::vector<int> result;
        if (root != nullptr || (root->left == nullptr && root->right == nullptr)) {
            if (root->left != nullptr){
                std::vector<int> left_result = postorderTraversal(root->left);
                result.insert(result.end(), left_result.begin(), left_result.end());
            }
            if (root->right != nullptr){
                std::vector<int> left_result = postorderTraversal(root->right);
                result.insert(result.end(),left_result.begin(), left_result.end());
            }
            result.push_back(root->val);
        }
        return result;
    }
};

void SimpleTest(){
}

int main() {
    TestRunner tr;
    RUN_TEST(tr, SimpleTest);
    return 0;
}
