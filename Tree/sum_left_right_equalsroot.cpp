class Solution
{
    public:
    
    pair<bool,int> isSumTreeFast(Node *root){
        
        if(root==NULL){
             return {true,0};
        }
         
        if(root->left==NULL && root->right==NULL){
             return {true,root->data};
        }
         
        pair<bool,int> leftAns=isSumTreeFast(root->left);
        pair<bool,int> rightAns=isSumTreeFast(root->right);
        
        bool condn = root->data == leftAns.second + rightAns.second;
        
        pair<bool,int> ans;
        
        if(leftAns.first && rightAns.first && condn){
            
            ans.first=true;
            ans.second=2*root->data;
        }
        else{
            ans.first=false;
        }
        
        return ans;
        
    }
    
    bool isSumTree(Node* root)
    {
         // Your code here
         return isSumTreeFast(root).first;
         
    }
};
