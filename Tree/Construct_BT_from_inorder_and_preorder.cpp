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
    void mapping(vector<int>& in, map<int,int> &nIdx,int n)
    {
        for(int i=0;i<n;i++)
            nIdx[in[i]]=i;
    }
    TreeNode* solve(vector<int>& in,vector<int>& pre,int &index,int inStart,int inEnd,int n,map<int,int> &nIdx)
    {
        if(index>=n || inStart>inEnd)
            return NULL;

        int ele = pre[index++];
        TreeNode *root = new TreeNode(ele);
        int pos = nIdx[ele];

        root->left= solve(in,pre,index,inStart,pos-1,n,nIdx);
        root->right= solve(in,pre,index,pos+1,inEnd,n,nIdx);

        return root;

    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        int n=inorder.size();
        map<int,int> nIdx;
        mapping(inorder,nIdx,n);
        int preidx=0;
        TreeNode *ans=solve(inorder,preorder,preidx,0,n-1,n,nIdx);
        return ans;
        
    }
};
