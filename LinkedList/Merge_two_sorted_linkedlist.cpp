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
    ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {
        if(head1 == NULL){
            return head2;
        }
        if(head2 == NULL){
            return head1;
        }
        // ListNode *newHead = NULL;
        // ListNode *temp = newHead;
        // while(head1 != NULL && head2 != NULL){
        //     if(head1 -> val <= head2 -> val){
        //         ListNode *new_node = new ListNode();
        //         new_node -> val = head1 -> val;
        //         new_node -> next = NULL;
        //         if(newHead == NULL){
        //             newHead = temp = new_node;
        //         }
        //         else{
        //             temp -> next = new_node;
        //             temp = new_node;
        //         }
        //         head1 = head1 -> next;
        //     }
        //     else{
        //         ListNode *new_node = new ListNode();
        //         new_node -> val = head2 -> val;
        //         new_node -> next = NULL;
        //         if(newHead == NULL){
        //             newHead = temp = new_node;
        //         }
        //         else{
        //             temp -> next = new_node;
        //             temp = new_node;
        //         }
        //         head2 = head2 -> next;
        //     }
        // }

        // while(head1 != NULL){
        //     ListNode *new_node = new ListNode();
        //     new_node -> val = head1 -> val;
        //     new_node -> next = NULL;
        //     temp -> next = new_node;
        //     temp = new_node;
        //     head1 = head1 -> next;
        // }
        // while(head2 != NULL){
        //     ListNode *new_node = new ListNode();
        //     new_node -> val = head2 -> val;
        //     new_node -> next = NULL;
        //     temp -> next = new_node;
        //     temp = new_node;
        //     head2 = head2 -> next;
        // }

        // return newHead;
        
        
        // OPTIMISED APPROACH

        ListNode *l1 = head1, *l2 = head2;
        if(l1 -> val > l2 -> val){
            swap(l1, l2);
        }

        ListNode *newHead = l1;
        while(l1 != NULL && l2 != NULL){
            ListNode *temp = NULL;
            while(l1 != NULL && (l1 -> val <= l2 -> val)){
                temp = l1;
                l1 = l1 -> next;
            }
            temp -> next = l2;
            swap(l1, l2);
        }

        return newHead;

    }
};