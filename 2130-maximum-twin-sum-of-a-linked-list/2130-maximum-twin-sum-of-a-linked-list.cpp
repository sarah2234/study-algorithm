/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
        int cnt = 1;
        int sum = 0;
        ListNode* curr = head;
        vector<int> num;
        while (curr)
        {
            cnt++;
            num.push_back(curr->val);
            curr = curr->next;
        }
        cnt--;
        
        for (int i = 0; i < cnt / 2; i++)
        {
            sum = max(sum, num[i] + num[cnt - 1 - i]);
        }
        
        return sum;
    }
};