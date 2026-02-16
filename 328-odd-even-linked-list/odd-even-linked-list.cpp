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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL||head->next==NULL){
            return head;
        }
       ListNode* tempo=head;
       ListNode* tempe=head->next;

      ListNode* head1=head->next;

        while(tempe!=NULL && tempe->next!=NULL){
            tempo->next=tempe->next;
            tempo=tempo->next;

            tempe->next=tempo->next;
            tempe=tempe->next;
        }  
tempo->next=head1;
return head;
    }
};