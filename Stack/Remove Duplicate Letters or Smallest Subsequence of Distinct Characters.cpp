Given a string s, remove duplicate letters so that every letter appears once and only once.
You must make sure your result is the smallest in lexicographical order among all possible results.

Example 1:

Input: s = "bcabc"
Output: "abc"
Example 2:

Input: s = "cbacdcbc"
Output: "acdb"

class Solution {
public:
    string smallestSubsequence(string s) {
        
        map<char,int> cnt;
        for(auto ch: s) cnt[ch]++;
        
        map<char,bool> vis;
        stack<char> st;
        
        for(auto ch:s){
            
            cnt[ch]--;
            
            if(!vis[ch]){
                
                while(!st.empty() && st.top() > ch && cnt[st.top()]>0)
                {
                    vis[st.top()]=false;
                    st.pop();
                }
                
                st.push(ch);
                vis[ch]=true;
                
            }
            
        }
        
        string ans;
        while(!st.empty()){
            ans=st.top()+ans;
            st.pop();
        }
        
        return ans;
    }
};
