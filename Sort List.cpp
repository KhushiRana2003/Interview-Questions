class Solution {
    public:
ListNode* sortList(ListNode* head) {
        //If List Contain a Single or 0 Node
        if(head == NULL || head ->next == NULL)
            return head;
        
        
        ListNode *temp = NULL;
        ListNode *slow = head;
        ListNode *fast = head;
        
        // 2 pointer appraoach / turtle-hare Algorithm (Finding the middle element)
        while(fast !=  NULL && fast -> next != NULL)
        {
            temp = slow;
            slow = slow->next;          //slow increment by 1
            fast = fast ->next ->next;  //fast incremented by 2
            
        }   
        temp -> next = NULL;            //end of first left half
        
        ListNode* l1 = sortList(head);    //left half recursive call
        ListNode* l2 = sortList(slow);    //right half recursive call
        
        return mergelist(l1, l2);         //mergelist Function call
    }
    
    //MergeSort Function O(n*logn)
    ListNode* mergelist(ListNode *l1, ListNode *l2)
    {
        ListNode *ptr = new ListNode(0);
        ListNode *curr = ptr;
        
        while(l1 != NULL && l2 != NULL)
        {
            if(l1->val <= l2->val)
            {
                curr -> next = l1;
                l1 = l1 -> next;
            }
            else
            {
                curr -> next = l2;
                l2 = l2 -> next;
            }
        
        curr = curr ->next;
        
        }
        
        //for unqual length linked list
        
        if(l1 != NULL)
        {
            curr -> next = l1;
            l1 = l1->next;
        }
        
        if(l2 != NULL)
        {
            curr -> next = l2;
            l2 = l2 ->next;
        }
        
        return ptr->next;
    }
    // ListNode* getMid(ListNode* head) {
    //     ListNode* slow = head;
    //     ListNode* fast = head;

    //     while(fast != NULL && fast->next != NULL){
    //         slow = slow->next;
    //         fast = fast->next->next;
    //     }
    //     return slow;
    // }

    // ListNode* merge(ListNode* list1, ListNode* list2) {
    //     ListNode* res = new ListNode();
    //     ListNode* tail = res;
    //     while(list1 != NULL && list2 != NULL){
    //             if(list1-> val < list2->val){
    //                 tail->next = list1;
                    
    //                 list1 = list1->next;
    //                 tail = tail->next;
    //             }

    //             if(list2->val < list1->val){
    //                 res->next = list2;
                    
    //                 list2 = list2->next;
    //                 tail = tail->next;
    //             }
    //         }

    //     tail->next = (list1 != NULL) ? list1 : list2;
            
    //     return res->next;
    // }

// public:
// using merge sort in this and for this we need mid and two parts and after this we merge them. so we use merge two list function and mid function and sortlist sort the node one by one.
    // ListNode* sortList(ListNode* head) {
    //     if(head == NULL || head->next == NULL){
    //         return head;
    //     }

    //     ListNode* slow = head;
    //     ListNode* fast = head;

    //     while(fast != NULL && fast->next != NULL){
    //         slow = slow->next;
    //         fast = fast->next->next;
    //     }

    //     // ListNode* mid = getMid(head);
    //     ListNode* left = sortList(head);
    //     ListNode* right = sortList(slow);

    //     return merge(left, right);

    // }

};







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
