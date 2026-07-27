class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0; 
        int high = nums.size()-1;
        int mini = INT_MAX, mid;
        while(low<= high){
            mid = (low+high)/2;
            mini = min(mini,nums[mid]);
            if(nums[low]>nums[high]&&nums[low]<=nums[mid]){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return mini;
    }
};