class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right){
            return head;
        }

        ListNode* curr = head;
        ListNode* prev = NULL;
        for(int i = 0 ; curr != NULL && i < left-1; i++){
            prev = curr; 
            curr = curr -> next;
            
        }

        ListNode* last = prev;
        ListNode* newEnd = curr;
        ListNode* next;

        for(int i = 0; curr != NULL && i < right - left +1; i++){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            
        }
        if(last != NULL){
            last->next = prev;
        }else{
            head = prev;
        }

        newEnd->next = curr;
        return head;
    }
};
