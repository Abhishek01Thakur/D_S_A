Given a string s, return the number of palindromic substrings in it.

A string is a palindrome when it reads the same backward as forward.

A substring is a contiguous sequence of characters within the string.
  
 
![image](https://user-images.githubusercontent.com/69719886/191326061-88e1e57b-b386-481f-be0b-329323a5e5db.png)

  
class Solution {
public:
    int countSubstrings(string s) {
        int res=0;
        bool dp[s.size()][s.size()];
        
        for(int g=0 ; g < s.size() ; g++){
            
            for(int i =0 , j=g; j< s.size() ;i++ ,j++){
                
                if(g==0){
                    dp[i][j]=true;
                }
                else if(g==1){
                    dp[i][j] = s[i]==s[j];
                }
                else{
                    dp[i][j] = s[i]==s[j] && dp[i+1][j-1];
                }
                if(dp[i][j])
                    res++;
            }
        }
        
        return res;
    }
};
