class Solution {
  public:
    vector <int> bottomView(Node *root) {
        // Your Code Here
        
        vector<int> ans;
        
        if(root==NULL)
        return ans;
        
        map<int,int> m;
        queue<pair<Node *,int>> q; //node and horizontal index
        
        q.push({root,0});
        
        while(!q.empty()){
            
            pair<Node *,int> temp = q.front();
            q.pop();
            
            Node *front=temp.first;
            int hd=temp.second;
            
            m[hd]=front->data;
            
            if(front->left){
                q.push({front->left,hd-1});
            }
            
            if(front->right){
                q.push({front->right,hd+1});
            }
            
        }
        
        for(auto it: m){
            ans.push_back(it.second);
        }
        
        
    }
};
