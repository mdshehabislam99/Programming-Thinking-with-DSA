#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
bool searchNode(TreeNode* root, int target) {
    if (!root) return false;
    if (root->val == target) return true;
    return searchNode(root->left, target) || searchNode(root->right, target);
}


int main()
{
    
   node* root = new TreeNode(1);
   root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    
    return 0;
}
