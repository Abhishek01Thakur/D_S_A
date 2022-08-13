class Solution {
public:
//   i/p 1-> 2 -> 3 -> 4 -> 5 -> 6
//   o/p 1->6->2->5->3->4
  
    int length(ListNode *head){
        if(head==NULL)
            return 0;
        return length(head->next)+1;
    }
    
    void fold(ListNode *right,int f){
        if(right==NULL) return;
        
        fold(right->next,f+1);
        
        if(f>len/2)
        {
            ListNode *temp = lhead->next;
            lhead->next=right;
            right->next=temp;
            lhead=temp;
        }
        else if(f==len/2){
            right->next=NULL;
        }
        
        
    }
    ListNode *lhead;
    int len;
    void reorderList(ListNode* head) {
        len=length(head);
        lhead=head;
        fold(head,0);
    }
};
