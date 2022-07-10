#include <iostream>
#include "../test_runner/test_runner.h"
#include "../test_runner/TreeNode.h"

class Solution {
public:
    std::vector<TreeNode*> treeLevel (const std::vector<TreeNode*>& levelTree, int val){
        std::vector<TreeNode*> result;
        for (const auto a : levelTree) {
            if (a->val == val){
                return {a};
            }
            if (a->val > val) {
                if (a->left != nullptr) {
                    result.push_back(a->left);
                }
            }
            if (a->val < val) {
                if (a->right != nullptr) {
                    result.push_back(a->right);
                }
            }
        }
        if (result.size()>0){
            return result;
        }
        return {};
    }

    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == nullptr) return root;

        std::vector<TreeNode*> treeLevel_ = {root};
        while (treeLevel_.size()>0){
            for (auto a : treeLevel_) {
                if (a->val == val){
                    return a;
                }
            }
            treeLevel_ = treeLevel(treeLevel_, val);
        }
        return nullptr;
    }
};

void SimpleTest(){

}

int main() {
    TestRunner tr;
    RUN_TEST(tr, SimpleTest);
    return 0;
}