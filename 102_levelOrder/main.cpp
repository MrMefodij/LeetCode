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

    std::vector<int> treeLevelValue (const std::vector<TreeNode*>& levelTree){
        std::vector<int> result;
        for (const auto a : levelTree) {
            if (a->left != nullptr){
                result.push_back(a->left->val);
            }
            if (a->right != nullptr){
                result.push_back(a->right->val);
            }
        }
        if (result.size()>0){
            return result;
        } else{
            return {};
        }
    }

    std::vector<std::vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) return {};
        if (root->left == nullptr && root->right == nullptr) return {{root->val}};

        std::vector<TreeNode*> treeLevel_ = {root};
        std::vector<std::vector<int>> result = {{root->val}};
        while (treeLevel_.size()>0){
            std::vector<int> tmp = treeLevelValue(treeLevel_);
            if (tmp.size()>0){result.push_back(std::move(tmp));}
            treeLevel_ = treeLevel(treeLevel_);
        }
        return result;
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

        TreeNode* tree = new TreeNode(3, tree_l2, tree_r2);

        std::vector<std::vector<int>> result ={{3}, {9,20},{15,7}};

        ASSERT_EQUAL(sl.levelOrder(tree), result);
    }
}

int main() {
    TestRunner tr;
    RUN_TEST(tr, SimpleTest);
    return 0;
}
