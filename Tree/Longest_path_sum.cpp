/*
Given a binary tree of size N. Your task is to complete the function sumOfLongRootToLeafPath(), that find the sum of all nodes on the longest path from root to leaf node.
If two or more paths compete for the longest path, then the path having maximum sum of nodes is being considered.

Example 1:

Input: 
        4        
       / \       
      2   5      
     / \ / \     
    7  1 2  3    
      /
     6
Output: 13

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
class Solution
{
public:
    
    void solve(Node *root,int len,int &maxLen,int sum,int &maxSum){
        
        if(root==NULL)
        {
            if(len>=maxLen)
            {
                maxLen=max(len,maxLen);
                maxSum=max(sum,maxSum);
            }
            return;
        }
        
        sum+=root->data;
        
        solve(root->left,len+1,maxLen,sum,maxSum);
        solve(root->right,len+1,maxLen,sum,maxSum);
    }
    
    int sumOfLongRootToLeafPath(Node *root)
    {
        //code here
        int len=0;
        int maxLen=0;
        
        int sum=0;
        int maxSum=INT_MIN;
        
        solve(root,len,maxLen,sum,maxSum);
        
        return maxSum;
        
    }
};
