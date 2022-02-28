/*
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.


Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9

*/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_map<int,bool> m;
        
        for(int i=0;i<nums.size();i++){
            m[nums[i]]=true;
        }
        
        for(int it : nums){
            
            if(m.find(it-1)!=m.end())
                m[it]=false;
            
        }
        int maxlen=0;
        for(auto it: m){
            
            if((it.second)==true){
                
                int templen=1;
                int tempele=it.first;
                
                while(m.find(tempele + templen)!=m.end()){
                    templen++;
                }
                
                if(templen>maxlen)
                    maxlen=templen;
                
            }
        }
        
        return maxlen;
        
    }
};
