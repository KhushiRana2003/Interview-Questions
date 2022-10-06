class Solution {

    ListNode* getMid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode* merge(ListNode* list1, ListNode* list2) {
        ListNode* res = new ListNode();
        ListNode* tail = res;
        while(list1 != NULL && list2 != NULL){
                if(list1-> val < list2->val){
                    tail->next = list1;
                    
                    list1 = list1->next;
                    tail = tail->next;
                }

                if(list2->val < list1->val){
                    res->next = list2;
                    
                    list2 = list2->next;
                    tail = tail->next;
                }
            }

            tail->next = (list1 != NULL) ? list1 : list2;
            
            return tail;
    }

public:

// using merge sort in this and for this we need mid and two parts and after this we merge them. so we use merge two list function and mid function and sortlist sort the node one by one.

    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }

        ListNode* mid = getMid(head);
        ListNode* left = sortList(head);
        ListNode* right = sortList(mid);

        return merge(left, right);
    }

};
