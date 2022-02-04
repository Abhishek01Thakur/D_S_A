import java.util.*;

class JavaEditor2 {
    public static Scanner sc = new Scanner(System.in);

    static Boolean isSubsetSum(int n, int arr[], int tar) {
        Boolean[][] dp = new Boolean[n + 1][tar + 1];
        int sum = 0;
        Boolean ans = tarSumSS(arr, 0, sum, tar, dp);
        return ans;
    }

    public static Boolean tarSumSS(int[] arr, int i, int sum, int tar, Boolean[][] dp) {

        if (sum == tar) {
            return dp[i][sum] = true;
        }
        // donot place i>=length condition before the sum==tar.
        // It might happen that the last element would have made the sum==target and we check this condiiton in next call with i+1 (this i+1 may
        // become == arr.length but sum have already became equal to target, so place sum == tar first.)
        if (i >= arr.length)
            return false;

        if (dp[i][sum] != null)
            return dp[i][sum];
        Boolean yes = false, no = false;
        if (sum + arr[i] <= tar)
            yes = tarSumSS(arr, i + 1, sum + arr[i], tar, dp);
        no = dp[i][sum] = tarSumSS(arr, i + 1, sum, tar, dp);
        return dp[i][sum] = yes || no;

    }

    public static void main(String[] args) {
        int n = sc.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++)
            a[i] = sc.nextInt();
        int tar = sc.nextInt();
        Boolean ans = isSubsetSum(n, a, tar);
        System.out.println(ans);
    }
}
