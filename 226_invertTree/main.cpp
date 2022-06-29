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

    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) return root;
        if (root->left == nullptr && root->right == nullptr) return root;

        std::vector<TreeNode*> treeLevel_ = {root};

        while (treeLevel_.size()>0){
            for( auto a : treeLevel_){
                if ( a->left != nullptr && a->right != nullptr) {
                    TreeNode* tmp = a->left;
                    a->left = a->right;
                    a->right = tmp;
                } else if (a->left == nullptr && a->right != nullptr){
                    a->left = a->right;
                    a->right = nullptr;
                } else if (a->left != nullptr && a->right == nullptr){
                    a->right = a->left;
                    a->left = nullptr;
                }
            }
            treeLevel_ = treeLevel(treeLevel_);
        }
        return root;

    }
};

void SimpleTest(){
    {
        Solution sl;
        TreeNode* tree_l1 = new TreeNode(1);
        TreeNode* tree_l3 = new TreeNode(1);

        TreeNode* tree_r6 = new TreeNode(6);
        TreeNode* tree_r9 = new TreeNode(9);

        TreeNode* tree_l2 = new TreeNode(2, tree_l1, tree_l3);
        TreeNode* tree_r7 = new TreeNode(7, tree_r6, tree_r9);

        TreeNode* tree = new TreeNode(4, tree_l2, tree_r7);

        TreeNode* inv_tree = sl.invertTree(tree);
        std::cout<<"f"<<std::endl;
    }
    {
        Solution sl;

        TreeNode* tree_r3 = new TreeNode(15);
        TreeNode* tree_r4 = new TreeNode(7);

        TreeNode* tree_l2 = new TreeNode(9);
        TreeNode* tree_r2 = new TreeNode(20, tree_r4, tree_r3);

        TreeNode* tree = new TreeNode(3, tree_l2, tree_r2);

        TreeNode* inv_tree = sl.invertTree(tree);
        std::cout<<"f"<<std::endl;
    }

}

int main() {
    TestRunner tr;
    RUN_TEST(tr, SimpleTest);
    return 0;
}


