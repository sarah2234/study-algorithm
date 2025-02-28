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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* shorter = l1, *longer = l2;
        ListNode* l1_s = l1, *l2_s = l2;
        ListNode* head = new ListNode, *tail = head;

        while (l1_s != nullptr)
        {
            l1_s = l1_s->next;
            if (l2_s != nullptr)
                l2_s = l2_s->next;
            else 
            {
                shorter = l2;
                longer = l1;
                break;
            }
        }

        int up = 0;
        while (shorter != nullptr)
        {
            ListNode* newNode = new ListNode;
            tail->next = newNode;
            tail = tail->next;
                    
            tail->val = (shorter->val + longer->val + up) % 10;
            up = (shorter->val + longer->val + up) / 10;
            shorter = shorter->next;
            longer = longer->next;
        }
                
        while (longer != nullptr)
        {
            ListNode* newNode = new ListNode;
            tail->next = newNode;
            tail = tail->next;

            tail->val = (longer->val + up) % 10;
            up = (longer->val + up) / 10;
            longer = longer->next;
        }

        if (up != 0)
        {
            ListNode* newNode = new ListNode;
            tail->next = newNode;
            tail = tail->next;
            tail->val = 1;
        }

        return head->next;
    }
};