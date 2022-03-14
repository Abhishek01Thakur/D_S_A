/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode* root) {
        if(root==NULL)
            return;
        
        stack<TreeNode*> s;
        s.push(root);
        // we push right first due to the stacks lifo property and as a result the next child will be on the top following the pre-order
        while(!s.empty())
        {
            TreeNode* cur=s.top();
            s.pop();
            
            if(cur->right)
                s.push(cur->right);
            if(cur->left)
                s.push(cur->left);
            
            if(!s.empty())
                cur->right=s.top();
            
            cur->left=NULL;
            
        }
        
    }
    
 
};
