class Solution {
public:
    int solve(int n, vector<int> &dp){
        //Memoization Method TC: O(n) SC: O(n)+O(n);
        if(n==1||n==0) return n;
        if(dp[n]!= -1) return dp[n];
        return dp[n] = solve(n-1,dp)+solve(n-2,dp);

    }
    int fib(int n) {
        //Recursion method TC: O(2^n) SC: O(n)

        // if(n == 0) return 0;
        // if(n == 1) return 1;
        // int ans1 = fib(n-1);
        // int ans2 = fib(n-2);
        // return ans1+ans2;

        vector<int> dp(n+1,-1);
        return solve(n,dp);
       

    //     // Tabulation method; TC: O(n) SC: O(1)
    //     if(n==0 || n==1) return n;
    //     int prev1 = 1;
    //     int prev2 = 0;
    //     for (int i=2; i<=n; i++){
    //         int curr = prev1+prev2;
    //         prev2 = prev1;
    //         prev1 = curr;
    //     }
    // return prev1;
    }
};