#include <iostream>
#include <set>
#include "../test_runner/test_runner.h"
#include "../test_runner/TreeNode.h"

class Solution {
public:
    void dfs(TreeNode* root,std::vector<int>&inorder)
    {
        if(root == NULL)
            return;

        dfs(root->left,inorder);
        inorder.push_back(root->val);
        dfs(root->right,inorder);
    }
    bool findTarget_2(TreeNode* root, int k)
    {
        std::vector<int>inorder;
        dfs(root,inorder);

        int start = 0;
        int end = inorder.size()-1;
        while(start < end)
        {
            if(inorder[start]+inorder[end] == k)
                return true;

            else if(inorder[start]+inorder[end] > k)
                end --;
            else
                start ++;
        }
        return false;
    }

    std::vector<TreeNode*> treeLevel (const std::vector<TreeNode*>& levelTree){
        std::vector<TreeNode*> result = {};
        for (const auto a : levelTree) {
            if (a->left != nullptr) {
                result.push_back(a->left);
            }
            if (a->right != nullptr) {
                result.push_back(a->right);
            }
        }
        return result;
    }

    bool findTarget(TreeNode* root, int k) {
        if (root == nullptr) return false;
        if (root->left == nullptr && root->right == nullptr) return false;

        std::set<int> result;
        std::vector<TreeNode*> tmp = {root};
        while (tmp.size()>0){
            for (const auto a : tmp) {
                result.insert(a->val);
            }
            tmp = treeLevel(tmp);
        }
        for (auto it =  result.begin(); result.size()>0; it=result.begin()){
            int tmp = *it;
            result.erase(it);
            if ( auto it_search = result.find( k - tmp) != result.end()){
                return true;
            }
        }
        return false;
    }
};

void SimpleTest() {
    {
        Solution sl;

        TreeNode * tree_l2 = new TreeNode(2);
        TreeNode * tree_l4 = new TreeNode(4);
        TreeNode * tree_l3 = new TreeNode(3, tree_l2, tree_l4);

        TreeNode * tree_r7 = new TreeNode(7);
        TreeNode * tree_r6 = new TreeNode(6, nullptr, tree_r7);

        TreeNode * tree = new TreeNode(5, tree_l3, tree_r6);
        ASSERT_EQUAL(sl.findTarget(tree,9), true);
    }
    {
        Solution sl;

        TreeNode * tree_l2 = new TreeNode(2);
        TreeNode * tree_l4 = new TreeNode(4);
        TreeNode * tree_l3 = new TreeNode(3, tree_l2, tree_l4);

        TreeNode * tree_r7 = new TreeNode(7);
        TreeNode * tree_r6 = new TreeNode(6, nullptr, tree_r7);

        TreeNode * tree = new TreeNode(5, tree_l3, tree_r6);
        ASSERT_EQUAL(sl.findTarget(tree,28), false);
    }
    {
        Solution sl;
        TreeNode * tree_l3 = new TreeNode(3);

        TreeNode * tree = new TreeNode(2, nullptr, tree_l3);
        ASSERT_EQUAL(sl.findTarget(tree,6), false);
    }
}

int main() {
    TestRunner tr;
    RUN_TEST(tr, SimpleTest);
    return 0;
}
