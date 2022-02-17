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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        
        if(root==NULL)
            return {};
        queue<TreeNode *> q;
        vector<int> v;
        vector<vector<int>> v1;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            TreeNode *temp=q.front();
            q.pop();   
            if(temp==NULL){
                if(!q.empty())
                    q.push(NULL);
                v1.insert(v1.begin(),v); //HERE WE INSERT AT THE BEGINNING
                v.clear();
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
