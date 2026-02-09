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
    TreeNode* buildBST(vector<int>& vecTree, int left, int right) {
        if (left > right) return nullptr;

        int mid = left + (right - left) / 2;
        TreeNode* root = new TreeNode(vecTree[mid]);

        root->left = buildBST(vecTree, left, mid - 1);
        root->right = buildBST(vecTree, mid + 1, right);

        return root;
    }

    void inorderTraversal(TreeNode* node, vector<int>& vecTree) {
        if (!node) return;

        inorderTraversal(node->left, vecTree);
        vecTree.push_back(node->val);
        inorderTraversal(node->right, vecTree);
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> vecTree;
        
        inorderTraversal(root, vecTree);

        return buildBST(vecTree, 0, vecTree.size() - 1);
    }
};