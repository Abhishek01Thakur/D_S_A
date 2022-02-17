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
    int height(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        
        int left=height(root->left);
        int right=height(root->right);
        
        return 1+max(left,right);
    }
    
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        int h=height(root);
        vector<vector<int>> ans(h,vector<int> {});
        if(root==NULL)
            return ans;
        
        queue<TreeNode*> st;
        st.push(root);
        int x=h-1;
        //cout<<h<<endl;
        while(!st.empty())
        {
            int length=st.size();
            
            for(int i=0;i<length;i++)
            {
                TreeNode* val=st.front();
                ans[x].push_back(val->val);
                st.pop();
                if(val->left)
                    st.push(val->left);
                if(val->right)
                    st.push(val->right);
            }
            
            x--;
        }
        return ans;
    }
};
