class Solution {
public:
    void inorder(TreeNode *root,vector<TreeNode*> &in){      
        if(root==NULL)return;
   
        inorder(root->left,in);
        in.push_back(root);
        inorder(root->right,in);        
    }
    
    TreeNode *toBST(int s,int e,const vector<TreeNode*> &in){
        
        if(s>e)
            return NULL;
        
        int mid=(s+e)/2;
        auto it=in[mid];
        it->left=toBST(0,mid-1,in);
        it->right=toBST(mid+1,e,in);
            
        return it;
        
    }
     
    TreeNode* balanceBST(TreeNode* root) {
        
        vector<TreeNode*> in;
        inorder(root,in);
        
        return toBST(0,in.size()-1,in);  
        
    }
    
    
    
    
//     void bstToArray(TreeNode * root, vector<TreeNode *>& nodes) {
//     if (NULL == root) {
//       return;
//     }
    
//     bstToArray(root->left, nodes);
//     nodes.push_back(root);
//     bstToArray(root->right, nodes);
//   }
  
//   TreeNode * arrayToBst(const vector<TreeNode *>& nodes, int left, int right) {
//     if (left > right) {
//       return NULL;
//     }
    
//     int mid = (left + right) / 2;
//     auto out = nodes[mid];
//     out->left = arrayToBst(nodes, left, mid - 1);
//     out->right = arrayToBst(nodes, mid + 1, right);
//     return out;
//   }
  
// public:
//   TreeNode * balanceBST(TreeNode * root) {
//     vector<TreeNode *> nodes;
//     bstToArray(root, nodes);
//     return arrayToBst(nodes, 0, nodes.size() - 1);
//   }
    
    
    
    
    
    
};
