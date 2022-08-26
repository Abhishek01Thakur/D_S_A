https://leetcode.com/problems/range-sum-query-mutable/

class Node{
    
    int str;
    int end;
    Node *left;
    Node *right;
    int val; 
    
    public:
    
    Node* construct(vector<int> &nums,int lo,int hi){
        if(lo==hi){
            Node *node = new Node();
            node->str = node->end = lo;
            node->left = node->right = NULL;
            node->val = nums[lo];
            return node;
        }
        
        Node *node = new Node();
        node->str = lo;
        node->end = hi;
        
        int mid = (lo + hi) / 2;
        node->left = construct(nums, lo, mid);
        node->right = construct(nums, mid + 1, hi);
        node->val = node->left->val + node->right->val;
        
        return node;
    }
    
    void update(Node *node,int idx,int val){
        if(node->str == node->end){
            node->val = val;
            return;
        }
        
        int mid = (node->str + node->end) / 2;
        if(idx <= mid){
            update(node->left, idx, val);
        } else {
            update(node->right, idx, val);
        }
        
        node->val = node->left->val + node->right->val;
    }
    
    int query(Node *node,int qs,int qe){
        if(qs > node->end || qe < node->str){
            return 0;
        } else if(node->str >= qs && node->end <= qe){
            return node->val;
        } else {
            int lval = query(node->left, qs, qe);
            int rval = query(node->right, qs, qe);
            return lval + rval;
        }
    }
    
};

Node *root = new Node();

class NumArray {
public:
      
    NumArray(vector<int>& nums) {
        root = root->construct(nums,0,nums.size()-1);
    }
    
    void update(int index, int val) {
        root->update(root,index,val); 
    }
    
    int sumRange(int left, int right) {
        return root->query(root,left,right);  
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
