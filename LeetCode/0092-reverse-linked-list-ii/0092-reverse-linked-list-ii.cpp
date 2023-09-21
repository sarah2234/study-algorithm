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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        vector<ListNode*> list;
        ListNode* curr = head;
        int index = 0;
        
        while (curr) {
            list.push_back(curr);
            curr = curr->next;
        }
        
        recur(list, left - 1, right - 1);
        list[list.size() - 1]->next = nullptr;

        return list[0];
    }
    
    void recur(vector<ListNode*>& list, int left, int right) {
        if (left >= right)
            return;
        
        ListNode* tmp = list[right];
        list[right] = list[left];
        list[left] = tmp;
        
        if (left > 0) {
            list[left - 1]->next = list[left];
        } 
        list[right - 1]->next = list[right];
        
        if (right < list.size() - 1) {
            list[right]->next = list[right + 1];
        }
        list[left]->next = list[left + 1];
        
        recur(list, left + 1, right - 1);
    }
};