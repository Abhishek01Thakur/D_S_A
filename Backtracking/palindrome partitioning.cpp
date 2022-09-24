Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.
A palindrome string is a string that reads the same backward as forward.
Example 1:
Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]

Example 2:
Input: s = "a"
Output: [["a"]]


class Solution {
public:
    bool ispal(string p,int i,int j){
        while(i<j){
            if(p[i++]!=p[j--])
                return false;
        }
        return true;
    }
    
    void solve(int idx,string &s,vector<vector<string>> &ans,vector<string> &v)
    {
        if(idx==s.size()){
            ans.push_back(v);
            return;
        }
        for(int i=idx;i<s.size();i++){
            if(ispal(s,idx,i)){
                v.push_back(s.substr(idx,i-idx+1));
                solve(i+1,s,ans,v);
                v.pop_back();
            }
        }
    }
    
    
    vector<vector<string>> partition(string s) {
        
        vector<vector<string>> ans;
        vector<string> v;
        
        solve(0,s,ans,v);
        
        return ans;
    }
};
