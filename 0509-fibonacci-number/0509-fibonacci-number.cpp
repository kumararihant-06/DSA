class Solution {
public:
    int fib(int n) {
        //Recursion method

        // if(n == 0) return 0;
        // if(n == 1) return 1;
        // int ans1 = fib(n-1);
        // int ans2 = fib(n-2);
        // return ans1+ans2;

        //Memoization Method
        // vector<int> dp (n+1, -1);
        // if(n==1||n==0) return n;
        // if(dp[n]!= -1) return dp[n];
        // return dp[n] = fib(n-1)+fib(n-2);

        // Tabulation method;
        if(n==0 || n==1) return n;
        int prev1 = 1;
        int prev2 = 0;
        for (int i=2; i<=n; i++){
            int curr = prev1+prev2;
            prev2 = prev1;
            prev1 = curr;
        }
    return prev1;
    }
};