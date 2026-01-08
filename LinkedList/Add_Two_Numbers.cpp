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

// Problem: Add Two Numbers
// Pattern: Linked List Construction with Carry
//
// Key Idea:
// - Traverse both lists simultaneously
// - Add corresponding digits along with carry
// - Use a dummy node to simplify list construction
//
// Time Complexity: O(max(m, n))
// Space Complexity: O(max(m, n)) for the result list

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;

        // Dummy node to simplify result list creation
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;

        while (l1 || l2 || carry) {
            int sum = carry;

            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }

            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum / 10;

            // Create new node with digit value
            curr->next = new ListNode(sum % 10);
            curr = curr->next;
        }

        ListNode* result = dummy->next;
        delete dummy; // free dummy node
        return result;
    }
};
