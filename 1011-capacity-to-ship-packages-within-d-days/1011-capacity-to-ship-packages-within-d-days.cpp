class Solution {
public:
    int helper(vector<int>& weights, int mid){
        int days = 1;
        int currWeight = 0;
        for(auto weight: weights){
            if(currWeight+weight<=mid){
                currWeight+=weight;
            }else{
                currWeight = weight;
                days++;
            }
        }
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(),weights.end());
        int high = 0;
       
        for(auto weight:weights){
            high+=weight;
        }

        int ans = high;

        while(low<=high){
            int mid = (low+high)/2;
            int reqDays = helper(weights,mid);
            if(reqDays<=days){
                ans = mid;
                high = mid-1;
            }else{
                low=mid+1;
            }
        }
    return ans;
    }
};