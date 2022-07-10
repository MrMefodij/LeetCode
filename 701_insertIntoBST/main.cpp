#include <iostream>
#include "../test_runner/test_runner.h"
#include "../test_runner/TreeNode.h"

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr) {
            TreeNode* tree_ = new TreeNode(val);
            return tree_;
        }

        TreeNode* pointer = root;
        TreeNode* tree = new TreeNode(val);
        while (true){
            if (val < pointer->val){
                if (pointer->left == nullptr){
                    pointer->left = tree;
                    break;
                }
                pointer = pointer->left;
            } else if (val > pointer->val){
                if (pointer->right == nullptr){
                    pointer->right = tree;
                    break;
                }
                pointer = pointer->right;
            }
        }

        return root;
    }
};

void SimpleTest(){

}

int main() {
    TestRunner tr;
    RUN_TEST(tr, SimpleTest);
    return 0;
}