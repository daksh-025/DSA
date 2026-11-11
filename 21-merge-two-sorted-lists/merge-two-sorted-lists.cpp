class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head1 = list1;
        ListNode* head2 = list2;
        ListNode* head3 = NULL;
        ListNode* curr = NULL;

        while(head1 != NULL && head2 != NULL) {
            if(head1->val <= head2->val) {
                if(head3 == NULL) {
                    head3 = head1;
                    curr = head3;
                }
                else {
                    curr->next = head1;
                    curr = curr->next;
                }
                head1 = head1->next;
            }
            else {
                if(head3 == NULL) {
                    head3 = head2;
                    curr = head3;
                }
                else {
                    curr->next = head2;
                    curr = curr->next;
                }
                head2 = head2->next;
            }
        }

        if(head1 != NULL) {
            if(head3 == NULL) {
                head3 = head1;
            }
            else {
                curr->next = head1;
            }
        }

        if(head2 != NULL) {
            if(head3 == NULL) {
                head3 = head2;
            }
            else {
                curr->next = head2;
            }
        }

        return head3;
    }
};
            
      