vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    queue<int> q;
	    vector<int> indegree(V,0);
	    
	    for(int i=0;i<V;i++)
	    {
	        for(auto it: adj[i])
	        indegree[it]++;
	    }
	    
	    for(int i=0;i<V;i++)
	    {
	        if(indegree[i]==0)
	        q.push(i);
	    }
	    
	    vector<int> topo;
	    
	    while(!q.empty())
	    {
	        int temp=q.front();
	        q.pop();
	        
	        topo.push_back(temp);
	        
	        for(auto it:adj[temp])
	        {
	            indegree[it]--;
	            if(indegree[it]==0)
	            q.push(it);
	        }
	       
	    }
	    
	    return topo;
	    
	}
