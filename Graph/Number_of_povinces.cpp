/*
There are n cities. Some of them are connected, while some are not.
If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

Return the total number of provinces.

*/


/*-------------USING ADJACENCY LIST------------------*/


class Solution {
public:
    
    void dfs(vector<int> adj[],vector<bool> &vis,int s)
    {
        vis[s]=true;
        
        for(int i=0;i<adj[s].size();i++)
        {
            if(!vis[adj[s][i]])
                dfs(adj,vis,adj[s][i]);
        }
        
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int n=isConnected.size();
        
        vector<int> adj[n];
        
        for(int i=0;i< isConnected.size();i++)
        {
            for(int j=0;j< isConnected[i].size();j++)
            {
                if(i!=j && isConnected[i][j]==1)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        
        vector<bool> vis(n,false);
        
        int cnt=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(adj,vis,i);
                cnt++;
            }
        }
        
        return cnt;
    }
};


/*------------USING ADJACENCY MATRIX---------------------*/

class Solution {
private:
    void dfs(vector<vector<int>>& isConnected, vector<bool>& visited, int i, int& n){
        if (visited[i]) return;
        visited[i]=true;
        for (int j=0; j<n; j++){
            if (isConnected[i][j]==1) {dfs(isConnected, visited, j, n);}
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size(), res=0;
        vector<bool> visited(n, false);
        for (int i=0; i<n; i++){
            if (!visited[i]) {
                dfs(isConnected, visited, i, n);
                res++;
            }
        }
        return res;
    }
};
