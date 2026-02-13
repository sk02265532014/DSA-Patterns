/*
    Problem: Remove Duplicates from Sorted List
    Platform: LeetCode
    Approach: Iterative pointer traversal
    Time Complexity: O(n)
    Space Complexity: O(1)

    Idea:
    Since the list is sorted, duplicates will always be adjacent.
    Traverse the list and compare current node with next node.
    If duplicate found, remove it by adjusting pointers and free memory.
*/

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
    ListNode* deleteDuplicates(ListNode* head) {
        // Pointer to traverse the linked list
        ListNode* curr = head;

        // Traverse while current node and next node exist
        while (curr && curr->next) {
            
            // If duplicate node found
            if (curr->val == curr->next->val) {
                
                // Store duplicate node
                ListNode* dup = curr->next;
                
                // Skip duplicate node
                curr->next = dup->next;
                
                // Free memory of duplicate node
                delete dup;
            }
            else {
                // Move to next distinct element
                curr = curr->next;
            }
        }

        return head;
    }
};
