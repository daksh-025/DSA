
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* fast = dummy;
        ListNode* slow = dummy;

        // Move fast n+1 steps ahead
        for (int i = 0; i <= n; i++) {
            fast = fast->next;
        }

        // Move both pointers
        while (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }

        // Delete the required node
        ListNode* delNode = slow->next;
        slow->next = slow->next->next;

        delete delNode;

        ListNode* newHead = dummy->next;
        delete dummy;

        return newHead;
    }
};
