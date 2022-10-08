class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL || k <= 0){
            return head;
        }

        ListNode* last = head;
        int length = 1;
        while(last->next != NULL){
            last = last->next;
            length++;
        }

        last->next = head;

        int rotation = k%length;
        ListNode* newLast = head;

        int skip = length - rotation;

        for(int i = 0; i < skip-1; i++){
            newLast = newLast->next;

        }

        head = newLast->next;

        newLast->next = NULL;
        return head;

    }
};
