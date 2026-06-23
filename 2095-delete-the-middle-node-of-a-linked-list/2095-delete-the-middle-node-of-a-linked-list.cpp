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
    ListNode* deleteMiddle(ListNode* head) {
        int n = 0;
        ListNode* curr = head;

        while (curr != nullptr) {
            n++;
            curr = curr->next;
        }

        if (n == 1) return nullptr;

        int cnt = 0;
        ListNode* prev = head;
        curr = head;

        while (cnt < n / 2) {
            cnt++;
            prev = curr;
            curr = curr->next;
        }

        prev->next = curr->next;

        return head;
    }
};