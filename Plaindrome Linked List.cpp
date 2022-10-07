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

    bool isPalindrome(ListNode* head) {
        ListNode* mid = MiddleList(head);
        ListNode* headSecond = reverseList(mid);
        ListNode* rereversehead = headSecond;

        while(head != NULL && headSecond != NULL){
            if(head->val != headSecond->val){
                break;
            }
            head = head->next;
            headSecond = headSecond->next;
        }

        reverseList(headSecond);

        return (head==NULL) || (headSecond == NULL);

    }
};
