// There are n rooms labeled from 0 to n - 1 and all the rooms are locked except for room 0. 
// Your goal is to visit all the rooms. However, you cannot enter a locked room without having its key.

// When you visit a room, you may find a set of distinct keys in it. 
// Each key has a number on it, denoting which room it unlocks, and you can take all of them with you to unlock the other rooms.

// Given an array rooms where rooms[i] is the set of keys that you can obtain if you visited room i, return true if you can visit all the rooms, or false otherwise.
  
  https://leetcode.com/problems/keys-and-rooms/

  
 class Solution {
public:
    
    void dfs(vector<bool> &vis,vector<vector<int>>& rooms,int src)
    {
        vis[src]=true;

        for(auto x: rooms[src])
        {   
            
            cout<<x;
            if(!vis[x])
                dfs(vis, rooms, x);
        }
    
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        int n=rooms.size();
        
        vector<bool> vis(n,false);
        
        dfs(vis,rooms,0);
                
        for(int i=0;i<n;i++){
            if(vis[i]==false)
                return false;
        }

        return true;
        
    }
};

<--------------------------------------------------------------------->
 BFS
 
 bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n,0);
        
        queue<int> q;
        q.push(0);
        visited[0] = true;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            visited[node] = true;
            for(auto i: rooms[node]){
                if(!visited[i]){
                    q.push(i);
                }
            }
        }
        
        for(int i=0;i<n;i++){
            if(visited[i] == 0){
                return false;
            }    
        }   
        return true;
    }
 
                  
            
