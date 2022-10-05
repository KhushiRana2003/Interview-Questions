class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* res = new ListNode();
        ListNode* tail = res;
        // ListNode* temp1 = list1;
        // ListNode* temp2 = list2;

        // base case
        //  no need to mention the base case
        // if(list1 == NULL && list2 == NULL){
        //     return NULL;
        // }

        // if(list1 != NULL && list2 == NULL){
        //     return list1;
        // }

        // if(list1 == NULL && list2 != NULL){
        //     return list2;
        // }

        
            // if(temp1->val == temp2->val){
            //     res == temp1; 
            //     res = res->next;
            //     res->next = temp2;
            //     temp1=temp1->next;
            //     temp2=temp2->next;
            // }
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
};
