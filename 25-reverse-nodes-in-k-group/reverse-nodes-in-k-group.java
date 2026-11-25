/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {

    ListNode findKthNode(ListNode head, int k) {
        ListNode temp = head;
        while (temp != null && k > 0) {
            temp = temp.next;
            k--;
        }
        return temp;
    }

    ListNode reverseLL(ListNode head) {
        ListNode prev = null;
        ListNode temp = head;
        ListNode front = null;

        while (temp != null) {
            front = temp.next;
            temp.next = prev;
            prev = temp;
            temp = front;
        }

        return prev;
    }

    public ListNode reverseKGroup(ListNode head, int k) {
        if (head == null || head.next == null || k <= 1)
            return head;

        ListNode dummy = new ListNode();
        dummy.next = head;

        ListNode groupPrev = dummy;
        ListNode kthNode = null;
        ListNode groupNext = null;
        ListNode curr = null;

        while (true) {

            kthNode = findKthNode(groupPrev, k);
            if (kthNode == null)
                break;

            groupNext = kthNode.next;

            curr = groupPrev.next;
            kthNode.next = null;

            // reverse current group
            curr = reverseLL(curr);

            groupPrev.next = curr;
            while (curr.next != null)
                curr = curr.next;
            curr.next = groupNext;
            groupPrev = curr;
        }

        return dummy.next;
    }
}