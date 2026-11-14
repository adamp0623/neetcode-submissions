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
    bool hasCycle(ListNode* head) {
        // Can you do this with a slow and fast pointer. 
        // Increment one pointer 1 index each iteration.
        // Increment another pointer 2 indexes each iteration.
        // If at any point, the index of the second pointer becomes smaller or equal
        // to the slow pointer, then there is a cycle and return true.
        // If the slow pointer and fast pointer become NULL, return true.

        // Each pointer needs to be assigned an index whenever it is visited.

        // Cant you just have one pointer. Label each node as you visit.
        // If you revisit the same pointer ever, return false. Stop once you reach the end.

        if(!head) return false;

        unordered_map<ListNode*, bool> seen;
        ListNode* cur_node = head;

        while(cur_node) {
            if(seen.find(cur_node) != seen.end()) return true;
            seen[cur_node] = true;
            cur_node = cur_node->next;
        }

        return false;
        
    }
};
