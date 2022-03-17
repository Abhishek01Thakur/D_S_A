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
    TreeNode *solve(vector<int>& preorder,int mini,int maxi,int &i)
    {
        if(i>=preorder.size())
            return NULL;
        
        if(preorder[i]<mini || preorder[i]>maxi)
            return NULL;
        
        TreeNode *root= new TreeNode(preorder[i++]);
        root->left = solve(preorder,mini,root->val,i);
        root->right = solve(preorder,root->val,maxi,i);
        
        return root;
        
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        int mini=INT_MIN;
        int maxi=INT_MAX;
        int i=0;
        
        return solve(preorder,mini,maxi,i);
        
    }
};



//-----------------------------------------------------------------------
//-----------------------------------------------------------------------

// Use the nature of BST and remove the lower limit due to the nature of preoder traversal
// time: n
// space: n
// class Solution {
// public:
//     TreeNode* bstFromPreorder(vector<int>& preorder) {
//         idx = 0;
//         return helper(INT_MAX, preorder);
//     }
// private: 
//     int idx;
//     TreeNode* helper(int p_val, vector<int>& preorder) {
//         if (idx == preorder.size() || preorder[idx] > p_val) {
//             return nullptr;
//         }
//         int c_val = preorder[idx];
//         idx++;
//         TreeNode *node = new TreeNode(c_val);
//         node -> left = helper(c_val, preorder);
//         node -> right = helper(p_val, preorder);
//         return node;
//     }
// };

//-----------------------------------------------------------------------
//-----------------------------------------------------------------------

// Use preorder + inorder
// time: n * log n
// space: n
// class Solution {
// public:
//     TreeNode* bstFromPreorder(vector<int>& preorder) {
//         inorder = vector<int> (preorder.begin(), preorder.end());
//         sort(inorder.begin(), inorder.end());
//         for (int i = 0; i < inorder.size(); i++) {
//             m[inorder[i]] = i;
//         }
//         idx = 0;
//         return helper(0, preorder.size() - 1, preorder);
//     }
// private: 
//     // k: val, v: idx in inorder traversal
//     unordered_map<int, int> m;
//     vector<int> inorder;
//     int idx;
    
//     TreeNode* helper(int l, int r, vector<int>& preorder) {
//         if (l > r) {
//             return nullptr;
//         }
//         int value = preorder[idx];
//         idx++;
//         // use preorder to find root
//         TreeNode *node = new TreeNode(value);
//         // use inorder to find the range for left and right subtree
//         int index = m[value]; // index in inorder traversal
//         node -> left = helper(l, index - 1, preorder);
//         node -> right = helper(index + 1, r, preorder);
//         return node;
//     }
// };


