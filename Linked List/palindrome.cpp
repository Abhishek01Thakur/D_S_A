class Solution {
public:
    
    int length(ListNode *head){
        if(head==NULL)
            return 0;
        return length(head->next)+1;
    }
    
    bool pal(ListNode *rhead,int f){
        
        if(rhead==NULL)
            return true;
        
        bool rres= pal(rhead->next,f+1); // f for the count till mid
        
        if(rres==false) return false;
        
        if(f>len/2){
            if(lhead->val!=rhead->val)    //two pointer approach
                return false;
            
            lhead=lhead->next;
        }
        
        return true;
    }
    
    ListNode *lhead;   
    int len=0;          
    bool isPalindrome(ListNode* head) {
        len=length(head); //len of linked list
        lhead=head;
        return pal(head,1);
    }
};
