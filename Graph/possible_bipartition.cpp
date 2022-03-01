/*
We want to split a group of n people (labeled from 1 to n) into two groups of any size. 
Each person may dislike some other people, and they should not go into the same group.

Given the integer n and the array dislikes 
where dislikes[i] = [ai, bi] indicates that the person labeled ai does not like the person labeled bi, 
return true if it is possible to split everyone into two groups in this way.

 

Example 1:

Input: n = 4, dislikes = [[1,2],[1,3],[2,4]]
Output: true
Explanation: group1 [1,4] and group2 [2,3].
Example 2:

Input: n = 3, dislikes = [[1,2],[1,3],[2,3]]
Output: false
Example 3:

Input: n = 5, dislikes = [[1,2],[2,3],[3,4],[4,5],[1,5]]
Output: false
*/


class Solution {
public:
    
    bool isBipartite(vector<int> adj[],int node, vector<int> &color)
    {
        queue<int> q;
        
        q.push(node);
        color[node]=1;
        
        while(!q.empty())
        {
            int cur =q.front();
            q.pop();
            
            for(auto i : adj[cur])
            {
                
                if(color[i] == color[cur])
                    return false;
                
                if(color[i]==-1) // unvisited node
                {
                    color[i]=1-color[cur];
                    q.push(i);
                }  
            } 
        }
        
        return true;
    }
    
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        
        vector<int> adj[n+1];
        
        for(int i=0;i<dislikes.size();i++)
        {
            adj[dislikes[i][0]].push_back(dislikes[i][1]);
            adj[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        
        vector<int> color(n+1,-1);
        
        for(int i=1;i<=n;i++)
        {
            if(color[i]==-1)
                if(!isBipartite(adj,i,color))
                    return false;
        }
        
        return true;
    }
};
