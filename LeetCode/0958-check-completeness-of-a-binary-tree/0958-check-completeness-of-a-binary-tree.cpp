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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> tree;
        bool flag = false;
        tree.push(root);
        while (!tree.empty())
        {
            TreeNode* node = tree.front();
            tree.pop();
            
            if (!node->left && node->right)
                return false;
            
            if (flag && (node->left || node->right))
                return false;
            
            if (node->left)
                tree.push(node->left);
            else
                flag = true;
            
            if (node->right)
                tree.push(node->right);
            else
                flag = true;
            
        }
        
        return true;
    }
}; 