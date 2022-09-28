You are given a string s of length n, and an integer k. You are tasked to find the longest subsequence repeated k times in string s.

A subsequence is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters.

A subsequence seq is repeated k times in the string s if seq * k is a subsequence of s, where seq * k represents a string constructed by concatenating seq k times.

For example, "bba" is repeated 2 times in the string "bababcba", because the string "bbabba", constructed by concatenating "bba" 2 times, is a subsequence of the string "bababcba".
Return the longest subsequence repeated k times in string s. If multiple such subsequences are found, return the lexicographically largest one. If there is no such subsequence, return an empty string.

  
  

class Solution {
public:
    string longestSubsequenceRepeatedK(string s, int k) {
        string res="";
        queue<string> q;
        q.push("");
        
        while(q.size()>0){
            
            int sz=q.size();
            while(sz--)
            {
                string rem =q.front();
                q.pop();
                
                for(int i= 0 ; i <26; i++){
                    char ch='a'+i;
                    string next = rem + ch;
                    if(iskSub(s,next,k)){
                        res=next;
                        q.push(next);
                    }
                }    
            }  
        } 
        return res;
    }
    
    bool iskSub(string s,string sub,int k){
        int j=0;
        int rep=0;
        
        for(int i = 0; i <s.size() ;i++){
            
            if(s[i]==sub[j]){
                j++;
            }
            
            if(j==sub.size()){
                j=0;
                rep++;
            }
            
            if(rep==k)
                return true;
        }
        return false;
    }
};
