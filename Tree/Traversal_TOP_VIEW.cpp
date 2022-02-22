class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        //Your code here
        vector<int> ans;
        if(root==NULL)
            return ans;
            
        map<int,int> m;
        
        queue< pair<Node *, int>> q;
        
        q.push({root,0});
        
        while(!q.empty()){
            
            pair<Node *, int> temp = q.front();
            q.pop();
            Node *front = temp.first;
            int hd= temp.second;
            
            if(m.find(hd) == m.end())
                m[hd] = front->data;
            
            
            if(front->left)
                q.push({front->left,hd-1});
            if(front->right)
                q.push({front->right,hd+1});
            
        }
        
        for(auto i:m){
            ans.push_back(i.second);
        }
        
        return ans;
        
    }

};
