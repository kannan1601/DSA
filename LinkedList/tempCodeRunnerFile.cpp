class Solution {
public:
    ListNode* middleNode(ListNode* head) {
    //     if(head == NULL) return head;
    //     ListNode *temp = head;
    //     int N = 0;
    //     while(temp != NULL){
    //         N++;
    //         temp = temp -> next;
    //     }
    //     temp = head;
    //     int cnt = (N / 2) + 1;
    //     ListNode *newHead = NULL;
    //     --cnt;
    //     while(cnt--){
    //         temp = temp->next;
    //     }
    //     newHead = temp;
    //     return newHead;
    // }

    // OPTIMAL APP
    
     ListNode *slowptr = head;
        ListNode *fastptr = head;
        while(fastptr != NULL && fastptr -> next != NULL){
            slowptr = slowptr -> next;
            fastptr = fastptr -> next -> next;
        }
        return slowptr;
    }
};