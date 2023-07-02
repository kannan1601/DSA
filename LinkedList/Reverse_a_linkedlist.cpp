class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *newHead = NULL;
        ListNode *nxt = NULL;
        while(head != NULL){
            nxt = head -> next;
            head -> next = newHead;
            newHead = head;
            head = nxt;
        }
        return newHead;
    }
};