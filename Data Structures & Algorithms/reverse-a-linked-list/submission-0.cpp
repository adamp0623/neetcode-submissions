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

 // n1 -> n2 -> n3 -> n4 -> NULL
 // n4 -> n3 -> n2 -> n1 -> NULL

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
        if(!head) return nullptr;

        ListNode* prev_node = head;
        ListNode* cur_node = head->next;
        head->next = nullptr;
        
        while(cur_node) {
            // Pointer to next node
            auto temp = cur_node->next;
            cur_node->next = prev_node;

            prev_node = cur_node;
            cur_node = temp;
        }

        return prev_node;
        
    }
};
