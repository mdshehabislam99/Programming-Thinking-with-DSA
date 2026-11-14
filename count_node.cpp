#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        int left = leftDepth(root);
        int right = rightDepth(root);
        if (left == right) return (1 << left) - 1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }

private:
    int leftDepth(TreeNode* node) {
        int depth = 0;
        while (node) {
            node = node->left;
            depth++;
        }
        return depth;
    }

    int rightDepth(TreeNode* node) {
        int depth = 0;
        while (node) {
            node = node->right;
            depth++;
        }
        return depth;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
//solution is node
    Solution sol;
    cout << "Number of nodes: " << sol.countNodes(root) << endl;

    return 0;
}
