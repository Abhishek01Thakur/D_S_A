package work;
import java.util.*;
public class targetSum {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Scanner scn = new Scanner(System.in);
		int n =scn.nextInt();
		
		int arr[] =new int[n];
		for(int i=0;i<n;i++) {
			arr[i] =scn.nextInt();
		}
		
		int tar =scn.nextInt();
		
		boolean dp[][] = new boolean[tar+1][n+1];
		
		for(int i=0; i < dp.length; i++) {
			
			for(int j=0;j < dp[0].length ; j++) {
				
				if(i==0 && j==0) {
					dp[i][j]=true;
				}
				else if(i==0) {
					dp[i][j]=false;
				}
				else if(j==0) {
					dp[i][j]=true;
				}
				else {
          
					if(dp[i-1][j]=true)
						dp[i][j]=true;
					else {
              int curr = arr[i-1];

              if(j >= curr) {
                if(dp[i-1][j-curr]==true) {
                  dp[i][j]=true;
                }
                else {
                  dp[i][j]=false;
                }
              }
					}
          
				}	
			}
		}
		System.out.println(dp[arr.length][tar]);
		
		
		scn.close();
	}

}
