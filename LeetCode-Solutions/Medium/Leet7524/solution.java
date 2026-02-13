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
    public ListNode deleteMiddle(ListNode head) {
        ListNode hare = head ; 
        ListNode tortoise = head ; 
        ListNode ptr = head;
        if(head == null  || head.next == null)return null;
        while(hare != null && hare.next != null){
            hare = hare.next.next;
            ptr = tortoise;
            tortoise = tortoise.next;
        }
        ptr.next = tortoise.next;
        return head;
    }
}
