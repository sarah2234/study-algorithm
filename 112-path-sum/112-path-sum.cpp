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
    bool output = false;
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL)
            return false;
        else if(root->left == NULL && root->right == NULL && root->val == targetSum)
            return true;
        
        if(root->left)
            DFS(root->left, targetSum, root->val);
        if(root->right)
            DFS(root->right, targetSum, root->val);
        
        return output;
    }
    
    void DFS(TreeNode* currentNode, int targetSum, int currentSum)
    {
        if(output)
            return;
        
        currentSum += currentNode->val;
        if(currentNode->left != NULL)
            DFS(currentNode->left, targetSum, currentSum);
        if(currentNode->right != NULL)
            DFS(currentNode->right, targetSum, currentSum);
        if(currentNode->left == NULL && currentNode->right == NULL && targetSum == currentSum)
            output = true;
            
    }
};