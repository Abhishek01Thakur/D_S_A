class Solution {
public:
    bool isCyclic(vector<int> adj[],vector<bool> &vis,vector<bool> &dfsvis,int cur)
    {
        
        vis[cur] = true;
        dfsvis[cur] = true;
        
        
        for(auto it : adj[cur]) {
            if(!vis[it]) {
                if(isCyclic(adj,vis,dfsvis,it)) return true;
            } 
            else if(dfsvis[it]) {
                return true; 
            }
        }
        dfsvis[cur] = false; 
        return false;
    }
    
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int> adj[numCourses];
        
        for(int i=0; i < prerequisites.size() ;i++)
        {
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
            //adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        
        vector<bool> vis(numCourses,false);
        vector<bool> dfsvis(numCourses,false);
        
        for(int i=0;i<numCourses;i++)
        {
            if(!vis[i])
            {
                if(isCyclic(adj,vis,dfsvis,i))
                    return false;
            }
        }
        
        return true;
        
    }
};
