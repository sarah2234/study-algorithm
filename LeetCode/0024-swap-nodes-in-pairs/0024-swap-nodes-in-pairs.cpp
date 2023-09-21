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
    ListNode* swapPairs(ListNode* head) {
        int cnt = 0;
        ListNode* curr = head;
        ListNode* temp, *first, *prev, *second;
        first = head;
        while (curr)
        {
            if (cnt % 2 == 0)
            {
                prev = first;
                first = curr;
            }
            else if (cnt % 2 == 1)
            {
                second = curr;
                
                temp = first;
                first = second;
                temp->next = second->next;
                first->next = temp;
                if (cnt != 1)
                    prev->next = first;
                else
                    head = first;
                
                first = first->next;
                curr = curr->next;
            }
            
            curr = curr->next;
            cnt++;
        }
        return head;
    }
};