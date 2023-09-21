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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* begin = head;
        ListNode* end = head;
        int temp;
        int cnt = 1;
        for (int i = 1; i < k; i++)
        {
            begin = begin->next;
        }
        
        while (end->next != nullptr)
        {
            end = end->next;
            cnt++;
        }
        end = head;
        for (int i = 1; i <= cnt - k; i++)
        {
            end = end->next;
        }
        
        temp = end->val;
        end->val = begin->val;
        begin->val = temp;
        
        return head;
    }
};