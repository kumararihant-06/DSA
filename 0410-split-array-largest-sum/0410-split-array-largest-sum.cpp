class Solution {
public:
    int helper(vector<int>& nums, int mid){
        int reqK = 1;
        int currSum = 0;
        for(auto num: nums){
            if(currSum+num<=mid){
                currSum+=num;
            }else{
                currSum = num;
                reqK++;
            }
        }
        return reqK;
    }
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = 0;
        
        for(auto num: nums){
            high+=num;
        }

        int ans = high;
        while(low<=high){
            int mid = (low+high)/2;
            int reqK = helper(nums, mid);
            if(reqK<=k){
                ans = mid;
                high = mid-1;
            }else{
                low= mid+1;
            }
        }
    return ans;
    }
};