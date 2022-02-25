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
    
    void solve(TreeNode *root,vector<vector<int>> &ans,vector<int> v,int s,int ts)
    {
        if(root==NULL)
            return;
        
        s+=root->val;
        v.push_back(root->val);
        
        if(root->left==NULL && root->right==NULL && s==ts)
        {
            ans.push_back(v);
        }
        solve(root->left,ans,v,s,ts);
        solve(root->right,ans,v,s,ts);
        v.pop_back();
        
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        
        vector<vector<int>> ans;
        
        vector<int> v;
        int sum=0;
        solve(root,ans,v,sum,targetSum);
        
        return ans;
    }
};
