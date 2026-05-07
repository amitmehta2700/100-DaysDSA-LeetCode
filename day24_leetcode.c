/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* removeElements(struct ListNode* head, int val) {
    // Create dummy node
    struct ListNode dummy;
    dummy.next = head;

    struct ListNode *prev = &dummy;
    struct ListNode *curr = head;

    while (curr != NULL) {
        if (curr->val == val) {
            prev->next = curr->next;   // remove node
        } else {
            prev = curr;               // move prev only if not deleted
        }
        curr = curr->next;
    }

    return dummy.next;  // new head
}