class Solution {
public:
    
    void solveR(int a[],vector<int>& heights){
        int n=heights.size();
        stack<int> s;
        a[n-1]=n;
        s.push(n-1);
        
        for(int i=n-2 ;i >=0 ; i--){
            
            while(!s.empty() && heights[i] <= heights[s.top()])
                s.pop();
            
            if(s.empty()) a[i]=n;
            else{
                a[i] = s.top();
            }
            s.push(i);
        }
    }
    
    void solveL(int a[],vector<int>& heights){
        int n=heights.size();
        stack<int> s;
        a[0]=-1;
        s.push(0);
        
        for(int i=1 ;i < n ; i++){
            
            while(!s.empty() && heights[i] <= heights[s.top()])
                s.pop();
            
            if(s.empty()) a[i]=-1;
            else{
                a[i] = s.top();
            }
            s.push(i);
        }
    }
    
    
    int largestRectangleArea(vector<int>& heights) {
        
        int n =heights.size();
        int rse[n];
        int lse[n];
        
        solveR(rse,heights);
        solveL(lse,heights);
        
        int maxarea=INT_MIN;
        for(int i=0;i<n;i++){
            
            int width = rse[i]-lse[i]-1;
            int area = width * heights[i];
            maxarea=max(area,maxarea);
        }
        return maxarea;
    }
};
