class Solution {
public:
    bool detectCycleUtil(vector<int> adj[],vector<int> &vis,int cur)
    {
        if(vis[cur]==2)
            return true;
        
        vis[cur]=2; //processing
        for(auto it:adj[cur])
        {
            if(vis[it]!=1){
                if(detectCycleUtil(adj,vis,it))
                    return true;
            }
        }
        vis[cur]=1; //processed
        
        return false;
        
    }    
    
    bool detectCycle(vector<int> adj[],int num)
    {   
        
        vector<int> vis(num,0);
        for(int i=0;i<num;i++)
        {
            if(!vis[i])
            {
                if(detectCycleUtil(adj,vis,i))
                    return true;
            }
        }
        
        return false;
    }
    
    void dfs(vector<int> adj[],vector<bool> &vis,int cur,stack<int> &s)
    {
        vis[cur]=true;
        for(auto it:adj[cur]){
            if(!vis[it])
            dfs(adj,vis,it,s);
        }
        
        s.push(cur);
        
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        int n=prerequisites.size();
        vector<int> adj[numCourses];
        
        for(int i=0;i<n;i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        
        vector<int> ans;
        if(detectCycle(adj,numCourses)) //if cycle then no topo sort
            return ans;
        
        stack<int> s; //stack for storing topo arrangement
        vector<bool> vis(numCourses,false);
        
        for(int i=0;i<numCourses;i++)
        {
            if(!vis[i])
                dfs(adj,vis,i,s);
        }
        
        while(!s.empty())
        {
            ans.push_back(s.top());
            s.pop();
        }
        
        return ans;
    }
};
