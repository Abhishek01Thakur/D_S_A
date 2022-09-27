Given an array and a number k, find the largest sum of the subarray containing at least k numbers. It may be assumed that the size of array is at-least k.



long long int maxSumWithK(long long int a[], long long int n, long long int k) 
{
    
    long long int res[n];
    
    res[0] = a[0];
    int csum=a[0];
    
    for(long long int i = 1; i < n;i++){
        if(csum < 0){
            csum=a[i];
        }
        else{
            csum+=a[i];
        }
       res[i] = csum;
    }
    
    long long win[n -k+1];
    win[0] = 0;
    for(long long int i = 0; i < k;i++){
        win[0] +=a[i];
    }
    
    for(long long int i = 1; i < n-k+1;i++){
        win[i] = win[i-1] - a[i-1] + a[i+k-1];
    }
    
    long long int ans=0+win[0];
    
    for(int i = 0 ; i < n-k+1-1 ;i++)
    {
        ans = max(ans ,max(win[i+1],res[i] + win[i+1]));
    }
    
    return ans;
    
}


