
// Given the root of a binary tree and an integer targetSum, return the number of paths where the sum of the values along the path equals targetSum.

// The path does not need to start or end at the root or a leaf, but it must go downwards (i.e., traveling only from parent nodes to child nodes).



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
    void solve(TreeNode *root,vector<int> path,int &count,int ts)
    {
        if(root==NULL)
            return;
        
        path.push_back(root->val);
        
        solve(root->left,path,count,ts);
        solve(root->right,path,count,ts);
        
        
        int size=path.size(),sum=0;
        for(int i=size-1;i>=0;i--){
            sum+=path[i];
            if(sum==ts)
            {
                count++; //cannot use break becoz their is chance of again forming target sum when their are some negative numbers in between
            }
        }
        
        path.pop_back();
        
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        
        vector<int> path;
        int count=0;
        solve(root,path,count,targetSum);
        
        return count;
        
    }
};
