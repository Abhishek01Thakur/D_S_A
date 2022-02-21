class Solution
{
    public:
    //Function to find the vertical order traversal of Binary Tree.
    void vot(Node *root,map<int,vector<int>> &m,int d){
        
        if(root==NULL)
        return;
        
        m[d].push_back(root->data);
        vot(root->left,m,d-1);
        vot(root->right,m,d+1);
        
        return;
    }
    
    
    vector<int> verticalOrder(Node *root)
    {
        vector<int> v;
        map<int,vector<int>> m;
        int d=0;
        vot(root,m,d);
        
        for(auto p:m){
            
            for(int x:p.second)
                v.push_back(x);
            
        }
        
        
        return v;
    }
};
