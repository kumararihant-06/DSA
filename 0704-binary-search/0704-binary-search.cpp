class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;
        while(low<=high){
        int i = (low+high)/2;
        if(nums[i]==target)return i;
        else if(nums[i]>target){
            high = i-1;
        }else{
            low= i+1;
        }
        }
    return -1; 
    }
};