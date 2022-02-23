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
    vector<int> rightSideView(TreeNode* root) {
        
        
        if(root==NULL)
            return {};
        
        queue<TreeNode*> q;
        q.push(root);
        vector<int> v;
        while(q.size()!=0)
        {   
            TreeNode *temp=q.front();
            v.push_back(temp->val);
            int x=q.size();
            while(x--)
            {
                TreeNode *temp=q.front();
                q.pop();
                
                if(temp->right)
                    q.push(temp->right);
                if(temp->left)
                    q.push(temp->left);
                
            }   
        }
        
        return v;
    }
};
