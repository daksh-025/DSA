
class Solution {
public:
    ListNode* findMiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    void reorderList(ListNode* head) {

        if (head == NULL || head->next == NULL)
            return;

        // Finding middle node
        ListNode* middle = findMiddle(head);

        // Separating the two halves
        ListNode* second = middle->next;
        middle->next = NULL;

        // Reversing second half
        ListNode* curr = second;
        ListNode* prev = NULL;

        while (curr != NULL) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        // prev is the head of reversed second half
        ListNode* head1 = head;
        ListNode* head2 = prev;

        // Merging the two halves
        while (head2 != NULL) {
            ListNode* next1 = head1->next;
            ListNode* next2 = head2->next;

            head1->next = head2;
            head2->next = next1;

            head1 = next1;
            head2 = next2;
        }
    }
};
