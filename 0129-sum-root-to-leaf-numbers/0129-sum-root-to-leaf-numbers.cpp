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
    int total = 0;
    
    int sumNumbers(TreeNode* root) {
        return searchLeafNode(root, "");
    }
    
    int searchLeafNode(TreeNode* node, string num) {
        num += std::to_string(node->val);
        
        if (!node->right && !node->left)
            total += std::stoi(num);
        
        if (node->right)
            searchLeafNode(node->right, num);
        if (node->left)
            searchLeafNode(node->left, num);
        
        return total;
    }
};