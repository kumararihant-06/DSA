class Solution {
public:
    int maxSum(vector<int>& nums){
        int bestending = nums[0];
        int res = nums[0];
        for(int i = 1; i<nums.size(); i++){
            int v1 = bestending + nums[i];
            int v2 = nums[i];
            bestending = max(v1,v2);
            res = max(bestending, res);
        }
        return res;
    }
    int minSum(vector<int>& nums){
        int bestending = nums[0];
        int res = nums[0];
        for(int i = 1; i<nums.size(); i++){
            int v1 = bestending + nums[i];
            int v2 = nums[i];
            bestending = min(v1,v2);
            res = min(bestending, res);
        }
        return res;
    }
    int maxAbsoluteSum(vector<int>& nums) {
        int v1 = abs(maxSum(nums));
        int v2 = abs(minSum(nums));
        int result = max(v1,v2);
        return result;
    }
};