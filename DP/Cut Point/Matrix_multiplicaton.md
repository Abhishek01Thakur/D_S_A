![image](https://user-images.githubusercontent.com/69719886/190212624-b5796ebc-2c2c-47ff-9610-d6f3ff89c2f5.png)
![image](https://user-images.githubusercontent.com/69719886/190218030-cdc4ad9b-f69f-4fa8-a5fc-3cd217d95380.png)




//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        int n = N-1;
        int dp[n][n];
        
        for(int g=0; g < n ;g++){
            
            for(int i=0 , j =g ; j < n ;i++, j++){
                
                if(g==0){
                    dp[i][j]=0;
                }
                else if(g==1){
                    dp[i][j] = arr[i] * arr[j] * arr[j+1];
                }
                else{
                    
                    int mn = INT_MAX;
                    for(int k1=1 , k2=g ; k1<=g ;k1++ , k2--){
                        int left = dp[i][j - k2];
                        int right = dp[i + k1][j];
                        int multc = arr[i] * arr[j+1] * arr[i + k1];
                        
                        mn = min(mn , left + right + multc);
                    }
                    
                    dp[i][j] = mn;
                }
    
            }
        }
        
        return dp[0][n-1];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends
