// Java implementation of the approach
import java.util.*;

class GFG
{
	
	// Function to return the minimum cost
	static long minimumCost(long price[], int n)
	{
        Arrays.sort(price);
        
        if(n == 1){
            return price[0];
        }
        
        long ans = 0;
        for(int i = n - 1; i >= 1; i -= 2){
            if(i == 1){
                ans += price[1];
            } else if(i == 2){
                ans += price[0] + price[1] + price[2];
            } else {
                long f1 = price[0] + price[i] + price[0] + price[i - 1];
                long f2 = price[1] + price[0] + price[i] + price[1];
                ans += Math.min(f1, f2);
            }
        }
        
        return ans;
	}
	
	// Driver code
	public static void main (String[] args)
	{
		long price[] = { 30, 40, 60, 70 };
		int n = price.length;
	
		System.out.println(minimumCost(price, n));
	}
}

