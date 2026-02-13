/*
    Problem: Reverse Linked List
    Platform: LeetCode
    Approach: Iterative (Three Pointer Technique)
    
    Time Complexity: O(n)
    Space Complexity: O(1)

    Idea:
    We reverse the direction of each link one by one.
    Maintain three pointers:
    - left  -> previous node
    - head  -> current node
    - right -> next node

    At each step:
    1. Store next node
    2. Reverse current node's pointer
    3. Move all pointers one step forward
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
    ListNode* reverseList(ListNode* head) {

        // left will become the new head after reversal
        ListNode* left = NULL;
        ListNode* right = NULL;

        while (head) {
            // Store next node
            right = head->next;

            // Reverse current node's pointer
            head->next = left;

            // Move left pointer forward
            left = head;

            // Move head forward
            head = right;
        }

        // left is the new head of reversed list
        return left;
    }
};
