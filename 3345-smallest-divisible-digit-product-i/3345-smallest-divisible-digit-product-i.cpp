class Solution {
public:

    int helper(int n, int t){
        int digitProduct = 1;
        while(n>0){
            int num = n%10;
            if(num == 0) return 0;
            else{
                digitProduct*=num;
            }
            n=n/10;
        }
        return digitProduct;
    }
    int smallestNumber(int n, int t) {
        int digitProduct = helper(n,t);
        int rem = digitProduct%t;
        if(rem==0) return n;
        else{
          return smallestNumber(n+1, t);
        }
        return 0;
    }
};