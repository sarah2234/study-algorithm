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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> tmp;
        while (head) {
            tmp.push_back(head);
            head = head->next;
        }
        
        int dividedSize = tmp.size() / k;
        int remain = tmp.size() % k; 
        vector<ListNode*> ans;
        
        if (dividedSize > 0) {
            int index = 0;
            for (int i = 0; i < k; i++) {
                ans.push_back(tmp[index]);
                
                index = ((i + 1) == k ? tmp.size() : index + dividedSize) - 1;
                
                if (remain) {
                    index++;
                    remain--;
                }
                
                tmp[index]->next = NULL;
                index++;
            }
        } else {
            for (int i = 0; i < tmp.size(); i++) {
                ans.push_back(tmp[i]);
                tmp[i]->next = NULL;
            }
            for (int i = 0; i < k - tmp.size(); i++) {
                ans.push_back(NULL);
            }
        }
        
        
        return ans;
    }
};