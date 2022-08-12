class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
          
        ListNode *s=head,*f=head,*prev=NULL;
        int i=0;
        n=n-1; // n-1
        while(i<n){ //gap n-1 ka in terms of edges, but question has n in terms of nodes
            f=f->next;
            i++;
        }
        
        while(f->next!=NULL){
            prev=s;
            s=s->next;
            f=f->next;
        }
        
        if(prev!=NULL){
            prev->next= s->next; 
        }
        else{
            head=head->next;     //for the case when we delete head node
        }
        
        return head;
    }
};
