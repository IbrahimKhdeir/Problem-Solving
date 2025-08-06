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
 */class Solution {
public:
    string smallestFromLeaf(TreeNode* root) {
        string result = "~";  // '~' is higher than any lowercase letter

        dfs(root, "", result);
        return result;
    }

    void dfs(TreeNode* node, string path, string& result) {
        if (!node) return;

        // Prepend current letter to path
        path = char('a' + node->val) + path;

        if (!node->left && !node->right) {
            // Leaf node: check if path is smaller
            if (path < result) {
                result = path;
            }
        }

        dfs(node->left, path, result);
        dfs(node->right, path, result);
    }
};
