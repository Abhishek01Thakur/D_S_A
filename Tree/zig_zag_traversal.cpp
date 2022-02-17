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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        if(root==NULL)
            return {};
        
        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);
        vector<int> v;
        vector<vector<int>> v1;
        bool flag=false;
        while(!q.empty()){
            
            TreeNode *temp= q.front();
            q.pop();
            
            if(temp==NULL){
                
                if(flag)            // ever alternate level is pushed into v1 in reverse order
                    reverse(v.begin(),v.end());
                
                if(!q.empty())
                    q.push(NULL);
                
                v1.push_back(v);
                v.clear();
                flag=!flag;
            }
            else{
                v.push_back(temp->val);
                if(temp->left)
                q.push(temp->left);
                if(temp->right)
                q.push(temp->right);
            }
            
        }
        
        return v1;
        
    }
};
