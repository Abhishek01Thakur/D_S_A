/*
Input:
n1 = 3 , n2 = 4
           5    
          /    
         2  
        / \  
       3   4
Output: 2
Explanation:
LCA of 3 and 4 is 2.
*/

class Solution
{
    public:
    //Function to return the lowest common ancestor in a Binary Tree.
    Node* lca(Node* root ,int n1 ,int n2 )
    {
       //Your code here 
       if(root==NULL)
        return NULL;
        
        if(root->data==n1 || root->data==n2)
            return root;
            
        Node *leftAns = lca(root->left,n1,n2);    
        Node *rightAns = lca(root->right,n1,n2);
        
        
        if(leftAns && rightAns)
            return root;
        else if(!leftAns && rightAns)
            return rightAns;
        else if(!rightAns && leftAns)
            return leftAns;
        else
            return NULL;
        
       
    }
};
