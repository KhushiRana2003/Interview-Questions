class Solution {
public:
ListNode* MiddleList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode *prev=NULL;
        ListNode *curr=head;
        ListNode *n;
        
        while(curr != NULL){
            n = curr->next;
            curr->next=prev;
            prev= curr;
            curr=n;
        }
        return prev;
    }

    void reorderList(ListNode* head) {
        if(head == NULL && head->next == NULL){
            return ;
        }

        ListNode* mid = MiddleList(head);
        ListNode* hs = reverseList(mid);
        ListNode* hf = head;

        while(hs != NULL && hf != NULL){
            ListNode* temp = hf->next;
            hf->next = hs;
            hf = temp;

            temp = hs->next;
            hs->next = hf;
            hs = temp;
        }

        // pointing last node to null
        if(hf != NULL){
            hf->next = NULL;
        }
    }
};
