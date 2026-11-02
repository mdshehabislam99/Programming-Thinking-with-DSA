#include <iostream>
#include <unordered_set>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

bool hasCycle(TreeNode* node, unordered_set<TreeNode*>& visiting,
              unordered_set<TreeNode*>& visited) {
    if (node == nullptr) return false;
    if (visiting.count(node)) return true;
    if (visited.count(node)) return false;

    visiting.insert(node);
    if (hasCycle(node->left, visiting, visited) ||
        hasCycle(node->right, visiting, visited)) {
        return true;
    }

    visiting.erase(node);
    visited.insert(node);
    return false;
}

bool cycle_check(TreeNode* root) {
    unordered_set<TreeNode*> visiting;
    unordered_set<TreeNode*> visited;
    return hasCycle(root, visiting, visited);
}

int main() {
    TreeNode root(1);
    TreeNode left(2);
    TreeNode right(3);

    root.left = &left;
    root.right = &right;
    left.right = &root;  // Creates a cycle: root -> left -> root.

    cout << (cycle_check(&root) ? "Cycle detected" : "No cycle") << endl;
    return 0;
}
