class Solution {
public:   // 1->1->2->2->2->3->4->4    o/p 1->2->3->4
    ListNode* deleteDuplicates(ListNode* head) {
        
        if(head == NULL) return NULL;
        
        ListNode *curr=head;
        
        while(curr!=NULL){
            
            if((curr->next!=NULL) && curr->val == curr->next->val){
                ListNode *todel = curr->next;
                curr->next=curr->next->next;
                delete(todel);
            }
            else{
                curr=curr->next;
            }
        }
        return head;
    }
};
