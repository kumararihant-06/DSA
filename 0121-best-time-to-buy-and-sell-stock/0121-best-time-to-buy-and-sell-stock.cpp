class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int curr = prices[0];
        int maxi = 0;
        for(int i=1; i<prices.size(); i++){
            if (curr<prices[i]){
                maxi = max(maxi,prices[i]-curr);
            }else{
                curr = prices[i];
            }
        }
        return maxi;
    }
};