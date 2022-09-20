class Solution {
public:
    string longestPalindrome(string s) {
        string res="";
        bool dp[s.size()][s.size()];
        memset(dp,false,sizeof(dp));
        
        for(int g=0 ; g < s.size() ; g++){

            for(int i =0 , j=g; j< s.size() ;i++ ,j++){

                if(g==0){
                    dp[i][j]=true;
                }
                else if(g==1){
                    dp[i][j] = (s[i]==s[j]);
                }
                else{
                    dp[i][j] = (s[i]==s[j]) && (dp[i+1][j-1]);
                }
                
                if(dp[i][j] && res.size() < (j-i+1))
                res = s.substr(i,j-i+1);
            }
        }
        
        return res;
    }
};
