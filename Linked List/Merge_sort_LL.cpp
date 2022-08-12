class Solution {
public:
    ListNode* sortList(ListNode* head) {
        
        if(head==NULL || head->next==NULL)
            return head;
        
        ListNode  *f=head,*s=head;
        
        while(f->next!=NULL && f->next->next!=NULL)
        {
            s=s->next;
            f=f->next->next;
        }
        
        ListNode *temp=s->next;
        s->next=NULL;
            
        ListNode *left=sortList(head);
        ListNode *right=sortList(temp);
        
        return merge(left,right);   
    }
    
    ListNode* merge(ListNode *l,ListNode *r){
        
        if(l==NULL) return r;
        if(r==NULL) return l;
        
        ListNode *nhead=  new ListNode();
        ListNode *h=nhead;
        
        while(l!=NULL && r!=NULL){
            
            if(l->val<=r->val){
                nhead->next=l;
                l=l->next;
            }
            else{
                nhead->next=r;
                r=r->next;
            }
            nhead=nhead->next;
        }
        
        if(l!=NULL){
            nhead->next=l;
        }
        
        if(r!=NULL){
            nhead->next=r;
        }
        
        return h->next;
    }
    
    
    
};
