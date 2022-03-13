class Solution {
private:
    int minValue(TreeNode* root) {
    
        TreeNode* temp = root;
        int ans = 0;

        while(temp->left != NULL){
            temp = temp->left;
        }

        ans = temp->val;
        return ans;
    }
    
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        // root is NULL
        if(root==NULL)
            return root;
        
        if(root->val==key){
            
            // 0 child
            
            if(root->left==NULL && root->right==NULL){
                delete root;
                return NULL;
            }
            
            //1 child
            
            // if only left child is present
            if(root->left!=NULL && root->right==NULL){
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }
            //if only right child is present
            if(root->left==NULL && root->right!=NULL){
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }
            
            // 2 child
            if(root->left!=NULL && root->right!=NULL){
                //find min value in right child
                int mini = minValue(root->right);
                root->val = mini;
                root->right = deleteNode(root->right,mini);        //deleting that minimum node in right child
                return root;
            } 
        }
        else if(root->val > key){
            root->left = deleteNode(root->left,key);      
            return root;
        } 
        else {
            root->right = deleteNode(root->right,key);
            return root;
        } 
        
        return root;
    }
};
