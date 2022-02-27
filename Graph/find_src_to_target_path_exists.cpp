/*
There is a bi-directional graph with n vertices, where each vertex is labeled from 0 to n - 1 (inclusive). 
The edges in the graph are represented as a 2D integer array edges, where each edges[i] = [ui, vi] denotes a bi-directional edge between vertex ui and vertex vi.
Every vertex pair is connected by at most one edge, and no vertex has an edge to itself.

You want to determine if there is a valid path that exists from vertex source to vertex destination.

Given edges and the integers n, source, and destination, return true if there is a valid path from source to destination, or false otherwise.


Input: n = 3, edges = [[0,1],[1,2],[2,0]], source = 0, destination = 2
Output: true
Explanation: There are two paths from vertex 0 to vertex 2:
- 0 → 1 → 2
- 0 → 2

nput: n = 6, edges = [[0,1],[0,2],[3,5],[5,4],[4,3]], source = 0, destination = 5
Output: false
Explanation: There is no path from vertex 0 to vertex 5.

https://leetcode.com/problems/find-if-path-exists-in-graph/

*/

class Solution {
public:
    bool dfs(vector<int> graph[], vector<bool> &vis, int src, int dest)
    {
        vis[src]=true;
        if(src==dest) return true;
        for(auto i:graph[src])
        {
            if(!vis[i])
            {
                if(dfs(graph,vis,i,dest))
                    return true;
            }
        }
        return false;
    }

    bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
    {

        vector<bool> vis(n, false);

        vector<int> graph[n];
        for(auto i:edges)
        {
            graph[i[0]].push_back(i[1]);
            graph[i[1]].push_back(i[0]);
        }
        return dfs(graph, vis, source, destination);
    }
};
