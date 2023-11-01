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
    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int> m;
        queue<TreeNode*> q;

        q.push(root);

        while (!q.empty()) {
            TreeNode* t = q.front();
            q.pop();
            m[t->val]++;
            
            if (t->left) q.push(t->left);
            if (t->right) q.push(t->right);
        }

        int maxCnt = 0;
        vector<int> ans;
        for (auto& i : m) {
            if (i.second > maxCnt) {
                maxCnt = i.second;
            }
        }

        for (auto& i : m) {
            if (i.second == maxCnt) {
                ans.push_back(i.first);
            }
        }
        

        return ans;
    }
};