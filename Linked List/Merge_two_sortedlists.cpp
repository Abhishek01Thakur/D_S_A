class Solution {
public:
//     ListNode *dummy, *temp;
//         dummy = new ListNode();
//         temp = dummy;
        
//         //when both list1 and list2 isn't empty
//         while(list1 && list2){
//             if(list1->val < list2->val){
//                 temp->next = list1;
//                 list1 = list1->next;
//             }
//             else{
//                 temp->next = list2;
//                 list2 = list2->next;   
//             }
//             temp = temp->next;
//         }
        
//         // we reached at the end of one of the list
//         if(list1) temp->next = list1;
//         if(list2) temp->next = list2;
        
//         return dummy->next;
    
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        if(list1==NULL)
            return list2;
        if(list2==NULL)
            return list1;
        
        ListNode *nhead=new ListNode();
        ListNode *h;
        
        if(list1!=NULL && list2!=NULL && list1->val<=list2->val){
            nhead->val=(list1->val);
            list1=list1->next;
        }
        else if(list1!=NULL && list2!=NULL && list1->val>list2->val){
            nhead->val=(list2->val);
            list2=list2->next;
        }
        
        h=nhead;
        
        while(list1!=NULL && list2!=NULL){
            
            if(list1->val<=list2->val){
                    nhead->next=list1;
                    list1=list1->next;
            }
            else{
                    nhead->next=list2;
                    list2=list2->next;
            }
            
            nhead=nhead->next;
        }
        
        while(list1!=NULL){
            nhead->next=list1;
            list1=list1->next;
            nhead=nhead->next;
        }
        while(list2!=NULL){
            nhead->next=list2;
            list2=list2->next;
            nhead=nhead->next;
        }
        
        nhead->next=NULL;
        
        return h;
        
    }
};
