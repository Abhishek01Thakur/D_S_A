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

/*
  Given the root of a binary tree and an integer targetSum, 
  return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.

A leaf is a node with no children.

Input: root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
Output: true
Explanation: The root-to-leaf path with the target sum is shown.

*/

class Solution {
public:
    bool solve(TreeNode *root,int targetSum,int sum){
        
        if(root==NULL)
            return false;
        
        sum+=root->val;
        
        if(root->left==NULL && root->right==NULL){
            if(sum==targetSum)
                return true;
            else
                return false;
        }
        
        return solve(root->left,targetSum,sum) || solve(root->right,targetSum,sum);
        
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        
        return solve(root,targetSum,0);
        
    }
};
