/*
Given a directed acyclic graph (DAG) of n nodes labeled from 0 to n - 1, find all possible paths from node 0 to node n - 1 and return them in any order.

The graph is given as follows: graph[i] is a list of all nodes you can visit from node i (i.e., there is a directed edge from node i to node graph[i][j]).


Input: graph = [[1,2],[3],[3],[]]
Output: [[0,1,3],[0,2,3]]
Explanation: There are two paths: 0 -> 1 -> 3 and 0 -> 2 -> 3.


Input: graph = [[4,3,1],[3,2,4],[3],[4],[]]
Output: [[0,4],[0,3,4],[0,1,3,4],[0,1,2,3,4],[0,1,4]]
 

Constraints:

n == graph.length
2 <= n <= 15
0 <= graph[i][j] < n
graph[i][j] != i (i.e., there will be no self-loops).
All the elements of graph[i] are unique.
The input graph is guaranteed to be a DAG.


*/


void dfs(int s,vector<vector<int>>& graph,vector<vector<int>>& ans,vector<int> edg,vector<bool> vis,int v)
    {   
        vis[s]= true;
        
        edg.push_back(s);
        
        if(s==v)
        {   
           ans.push_back(edg);
           return; 
        }
            
        for(int i=0;i<graph[s].size();i++)
        {
            if(vis[graph[s][i]] == false)
               dfs(graph[s][i],graph,ans,edg,vis,v); 
        }
        
        edg.pop_back();
        
    }

    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        int v=graph.size();
        
        vector<bool> vis(v,false);
        vector<vector<int>> ans;
        vector<int> edg;
        v=v-1;
        
        for(int j=0;j<graph[0].size();j++)
        {   
            edg.push_back(0);
            dfs(graph[0][j],graph,ans,edg,vis,v);
            edg.clear();
        }
        
        return ans;
        
    }
};
