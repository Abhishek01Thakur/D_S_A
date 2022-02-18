class Solution{
    public:
    //Function to find the height of a binary tree.
    int height(struct Node* node){
        // code here 
        if(node==NULL)
         return 0;
         
        int ls=height(node->left);
        int rs=height(node->right);
        return max(ls,rs)+1;
    }
};
