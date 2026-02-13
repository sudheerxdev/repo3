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
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode ptr = head;
        int count = 0 ;
        while(ptr!=null){
            ptr=ptr.next;
            count++;
        }
        ListNode temp = head;
        if(count==n){
            return head.next;
        }
        for(int i = 1 ; i < count - n ; i++){
            temp = temp.next;
        }
        temp.next = temp.next.next;
        return head;

    }
}
