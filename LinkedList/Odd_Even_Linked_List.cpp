/*
    Problem: Odd Even Linked List
    Platform: LeetCode
    Approach: In-place pointer rearrangement

    Time Complexity: O(n)
    Space Complexity: O(1)

    Idea:
    Separate the list into two parts:
    - Odd indexed nodes
    - Even indexed nodes

    Then attach the even list at the end of the odd list.

    Important:
    Indexing is based on position (1-based), NOT node value.
*/

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        
        // Edge case: empty list or single node
        if (!head || !head->next) 
            return head;

        // odd pointer starts at head (1st node)
        ListNode* odd = head;

        // even pointer starts at 2nd node
        ListNode* even = head->next;

        // Store starting point of even list
        ListNode* evenHead = even;

        while (even && even->next) {
            
            // Connect odd nodes together
            odd->next = even->next;
            odd = odd->next;

            // Connect even nodes together
            even->next = odd->next;
            even = even->next;
        }

        // Attach even list at end of odd list
        odd->next = evenHead;

        return head;
    }
};
