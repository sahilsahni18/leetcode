/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int depth(TreeNode *root) {
    return !root ? 0 : max(depth(root->left), depth(root->right)) + 1;
}

TreeNode* subtreeWithAllDeepest(TreeNode* root) {
    int d = depth(root->left) - depth(root->right);
    return !d ? root : subtreeWithAllDeepest(d > 0 ? root->left : root->right);
}
};