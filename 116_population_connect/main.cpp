#include <iostream>
#include "../test_runner/test_runner.h"
#include "Node.h"

class Solution {
public:
    std::vector<Node*> treeLevel (const std::vector<Node*>& levelTree){
        std::vector<Node*> result = {};
        for (const auto a : levelTree) {
            if (a->left != nullptr) {
                result.push_back(a->left);
            }
            if (a->right != nullptr) {
                result.push_back(a->right);
            }
        }
        if (result.size() > 0) {
            for (int i = 0; i < result.size() - 1; ++i) {
                result[i]->next = result[i + 1];
            }
            result.back()->next = NULL;
        }
        return result;
    }

    Node* connect(Node* root) {
        if (root == nullptr) return root;
        std::vector<Node*> tmp = treeLevel({root});
        while (tmp.size()>0){
            tmp = treeLevel(tmp);
        }
        return root;
    }
};

void SimpleTest() {
    {
        Solution sl;

        Node * r_6 = new Node(6);
        Node * r_7 = new Node(7);
        Node * r_3 = new Node(3, r_6, r_7, nullptr);

        Node * l_4 = new Node(4);
        Node * l_5 = new Node(5);
        Node * l_2 = new Node(2, l_4, l_5, nullptr);
        Node * root = new Node(1,l_2, r_3, nullptr);

        sl.connect(root);
        std::cout << std::endl;
    }
    {
        Solution sl;

        std::cout << std::endl;
    }
}
int main() {
    TestRunner tr;
    RUN_TEST(tr, SimpleTest);
    return 0;
}

