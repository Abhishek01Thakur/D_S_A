// Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, 
// and return an array of the non-overlapping intervals that cover all the intervals in the input.

 

// Example 1:

// Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
// Output: [[1,6],[8,10],[15,18]]
// Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
// Example 2:

// Input: intervals = [[1,4],[4,5]]
// Output: [[1,5]]
// Explanation: Intervals [1,4] and [4,5] are considered overlapping.


vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> mergedinterval;
        
        sort(intervals.begin(),intervals.end());
        vector<int> temp=intervals[0];
        
        for(auto it:intervals)
        {
            if(it[0]<=temp[1])
            {
                temp[1]=max(it[1],temp[1]);
            }
            else{
                mergedinterval.push_back(temp);
                temp=it;
            }
        }
        mergedinterval.push_back(temp);
        
        return mergedinterval;
    }
