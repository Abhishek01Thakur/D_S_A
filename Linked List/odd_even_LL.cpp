class Solution {
public:
  
  //BASED ON INDICES
  1-> 2 -> 3 -> 4 -> 5 ->6
  o/p 1->3->5->2->4->6
    
    
    ListNode* oddEvenList(ListNode* head) {

        if(head==NULL)
         return head;
        
        ListNode *e=head->next,*o=head,*ehead=e;
        
        while(e!=NULL && e->next!=NULL)
        {
            o->next=o->next->next;
            e->next=e->next->next;
            o=o->next;
            e=e->next;
        }
        o->next=ehead;
        
        return head;
    }
   
  
  
 //       BASED ON  VALUES
  2->4->1->6->3->5
  O/P 1->3->5->2->4->6
  
//         ListNode *eh = new ListNode(),*et;
//         ListNode *oh = new ListNode(),*ot;
//         et=eh;
//         ot=oh;
//         ListNode *cur=head;
        
//         while(cur!=NULL){
//             if(cur->val%2 != 0){
//                 ot->next = cur;
//                 ot = ot->next;
//             }
//             else{
//                 et->next = cur;
//                 et= et->next;
//             }
//             cur = cur->next;
//         }
        
//         ot->next = eh->next;
//         et->next = NULL;
        
//         return oh->next;
    
    
    
    
};
