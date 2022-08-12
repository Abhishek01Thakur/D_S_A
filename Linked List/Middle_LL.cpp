class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *s=head,*f=head;
        
        while(f!=NULL && f->next!=NULL){ //f!=null for even for |Second| half and f->next->next!=NULL for |First| half and f->next!=null for odd
            s=s->next;
            f=f->next->next;
        }
        
        return s;
    }
};
