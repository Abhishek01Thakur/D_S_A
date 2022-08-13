class Solution {
public:
//     I/P 1->2->3->3->4->5->5
//     O/P 1->2->4
  
    ListNode* deleteDuplicates(ListNode* head) {
        
        if(head==NULL || head->next==NULL) return head;
        
        ListNode *nhead = new ListNode();
        ListNode *h=nhead;
        while(head!=NULL){
            
           if(head->next!=NULL && head->val == head->next->val){
               
               while(head->next!=NULL && head->val == head->next->val) {
                   head=head->next;
               }
               
           }
            else{
                nhead->next=head;
                nhead=nhead->next;
            }
            
            head=head->next;
        }
        
        nhead->next=NULL;
        
        return h->next;
    }
};
