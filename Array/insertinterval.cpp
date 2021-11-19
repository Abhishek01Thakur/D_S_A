// You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start and the end of the ith interval and intervals is sorted in ascending order by starti. 
//You are also given an interval newInterval = [start, end] that represents the start and end of another interval.

// Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).

// Return intervals after the insertion.

 

// Example 1:

// Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
// Output: [[1,5],[6,9]]
// Example 2:

// Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
// Output: [[1,2],[3,10],[12,16]]
// Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
// Example 3:

// Input: intervals = [], newInterval = [5,7]
// Output: [[5,7]]
// Example 4:

// Input: intervals = [[1,5]], newInterval = [2,3]
// Output: [[1,5]]
// Example 5:

// Input: intervals = [[1,5]], newInterval = [2,7]
// Output: [[1,7]]

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n=intervals.size(),i=0;
        vector<vector<int>> res;
        
        while(i<n && intervals[i][1]<newInterval[0])
        {
            res.push_back(intervals[i]);
            i++;
        }
        
        while(i<n && newInterval[1]>=intervals[i][0])
        {
            newInterval[0]=min(newInterval[0],intervals[i][0]);
            newInterval[1]=max(newInterval[1],intervals[i][1]);
            i++;
        }
        res.push_back(newInterval);
        
        while(i<n)
        {
            res.push_back(intervals[i]);
            i++;
        }
        
        return res;
    }
};
